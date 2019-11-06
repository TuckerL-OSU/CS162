// CLabelInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiLinkedList.h"
#include "CLabelInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabelInputDlg dialog


CLabelInputDlg::CLabelInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLabelInputDlg)
	m_sLabel = _T("Helo");
	//}}AFX_DATA_INIT
}


void CLabelInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLabelInputDlg)
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
	DDX_Text(pDX, IDC_EDIT1, m_sLabel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLabelInputDlg, CDialog)
	//{{AFX_MSG_MAP(CLabelInputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabelInputDlg message handlers

BOOL CLabelInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLabelInputDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	UpdateData( true );
	CDialog::OnCancel();
}

void CLabelInputDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData( true );
	CDialog::OnOK();
}
