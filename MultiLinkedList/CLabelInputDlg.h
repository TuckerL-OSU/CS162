#if !defined(AFX_CLABELINPUTDLG_H__682B0DA2_0773_413B_A80D_B39149E40FB4__INCLUDED_)
#define AFX_CLABELINPUTDLG_H__682B0DA2_0773_413B_A80D_B39149E40FB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CLabelInputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLabelInputDlg dialog

class CLabelInputDlg : public CDialog
{
// Construction
public:
	CLabelInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLabelInputDlg)
	enum { IDD = IDD_DIALOG_LABEL };
	CEdit	m_ctrlEdit;
	CString	m_sLabel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLabelInputDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLABELINPUTDLG_H__682B0DA2_0773_413B_A80D_B39149E40FB4__INCLUDED_)
