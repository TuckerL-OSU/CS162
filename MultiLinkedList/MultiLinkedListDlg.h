// MultiLinkedListDlg.h : header file
//

#if !defined(AFX_MULTILINKEDLISTDLG_H__E3AABDBC_BB2C_43E3_8576_7882426C3FA1__INCLUDED_)
#define AFX_MULTILINKEDLISTDLG_H__E3AABDBC_BB2C_43E3_8576_7882426C3FA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiLinkedListDlg dialog

class CMultiLinkedList;
#include <vector>
using namespace std;

class CMultiLinkedListDlg : public CDialog
{
// Construction
public:
	CMultiLinkedListDlg(CWnd* pParent = NULL);	// standard constructor

	//To read the data available in the given file and build the linlked list
	void BuildDataList(char* sFileName);

	//To build linked list using the vector containing the data
	void CreateHierarchy( vector<CString> vec );

	//Linked list which acts as a data storage for the tree item
	CMultiLinkedList* m_pMultiList;

	//To rebuild the tree
	void OnBuildtree();
	
	//Pop menu used for the tree items
	CMenu	m_menu;

	//Right clicked item of the tree
	HTREEITEM m_hRightClickedItem;

// Dialog Data
	//{{AFX_DATA(CMultiLinkedListDlg)
	enum { IDD = IDD_MULTILINKEDLIST_DIALOG };
	CTreeCtrl	m_ctrlTree;
	CString	m_sImportPath;
	CString	m_sExportPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiLinkedListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiLinkedListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenu( UINT nID );
	afx_msg void OnImport();
	afx_msg void OnExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTILINKEDLISTDLG_H__E3AABDBC_BB2C_43E3_8576_7882426C3FA1__INCLUDED_)
