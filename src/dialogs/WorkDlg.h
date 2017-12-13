﻿#pragma once

#include "afxwin.h"
#include "afxcmn.h"
#include "configuration\EncoderOptions.h"
#include "controls\MyDialogEx.h"
#include "controls\MyButton.h"
#include "controls\MyStatic.h"
#include "controls\MyEdit.h"
#include "controls\MyComboBoxEdit.h"
#include "controls\MyListCtrl.h"
#include "controls\MyComboBox.h"
#include "controls\MySliderCtrl.h"

// return values from work thread
#define WORKDLG_RETURN_SUCCESS 0
#define WORKDLG_RETURN_FAILURE 1

// elapsed time timers message id's
#define WM_FILE_TIMER WM_USER + 0x01
#define WM_TOTAL_TIMER WM_USER + 0x02

class CWorkDlg;

// params used in worker thread
typedef struct TWorkerParam
{
    CWorkDlg *pWorkDlg;
    CList<CString, CString> *list;
    CList<bool, bool> *listStatus;
    EncoderPreset preset;
    bool bUseOutPath;
    CString szOutPath;
    bool bMultiMonoInput;
    AftenAPI api;
    int nThreads;
    double fTimeTotal;
    double fTimeEncoding;
    double fTimeIORead;
    double fTimeIOWrite;
    __int64 nInTotalSize;
    __int64 nOutTotalSize;
} WorkerParam;

class CWorkDlg : public CMyDialogEx
{
    DECLARE_DYNAMIC(CWorkDlg)
public:
    CWorkDlg(CWnd* pParent = NULL);
    virtual ~CWorkDlg();
    enum { IDD = IDD_DIALOG_WORK };
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
protected:
    void InitSettings();
    void InitCtrls();
    void InitLang();
    void CreateWorker();
    void UpdateFileTimer();
    void UpdateTotalTimer();
protected:
    DECLARE_MESSAGE_MAP()
public:
    int nIDIn[nNumMaxInputFiles];
    int nIDInInfo[nNumMaxInputFiles];
public:
    volatile bool bTerminate;
    volatile bool bCanUpdateWindow;
    HANDLE hThread;
    DWORD dwThreadId;
    __int64 nTotalSize;
    double m_ElapsedTimeFile;
    double m_ElapsedTimeTotal;
    int nCount;
    WorkerParam workParam;
    CString szSpeedEncoderAvg;
    CString szSpeedReadsAvg;
    CString szSpeedWritesAvg;
public:
    CMyStatic m_StcOut;
    CMyStatic m_StcOutInfo;
    CMyStatic m_StcSimdInfo;
    CMyStatic m_StcTimeCurrent;
    CMyStatic m_StcTimeTotal;
public:
    CProgressCtrl m_PrgCurrent;
    CProgressCtrl m_PrgTotal;
public:
    CMyButton m_BtnCancel;
public:
    afx_msg void OnClose();
    afx_msg void OnDestroy();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
    afx_msg void OnBnClickedCancel();
};
