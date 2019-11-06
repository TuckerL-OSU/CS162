// MultiLinkedListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiLinkedList.h"
#include "MultiLinkedListDlg.h"
#include "CMultiLinkedList.h"
#include "CLabelInputDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define IDM_NODE_INSERTAFTER  8000
#define IDM_NODE_INSERTBEFORE 8001
#define IDM_NODE_DELETE		  8002
#define IDM_NODE_ADDCHILD	  8003

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//******************************************************************************************
//GLOBAL FUNCTION WHICH IS USED AS THE CALLBACK FUNCTION WHILE LOOPING THROUGH THE LINKED
//LIST.WHEN THIS FUNCTION IS CALLED EVERYTIME IT ADDS AN ITEM IN THE TREE CONTROL USING THE
//NODE DATA
//******************************************************************************************
void AddNodeToTree(PCALLBACKINFO pCBInfo)
{
	//Get the treer control
	CTreeCtrl* pTree = (CTreeCtrl*)(pCBInfo->m_pParam);	

	//Get the node data
	Node* pNode = pCBInfo->pNode;
	
	//Check if the node has left  node [ Parent ]
	if( pNode )
	{
		//Get the label of the tree item
		CString str = pCBInfo->pNode->m_pObj->m_Name;

		HTREEITEM hParent = NULL;

		//Add as child
		if( pNode->m_pLeft )
		{
			//Get its tree item
			hParent =pNode->m_pLeft->m_pObj->tree;			

		}
		//Add as a sibling
		else if( pNode->m_pPrev )
		{
			HTREEITEM hItem  =	pNode->m_pPrev->m_pObj->tree;
			hParent = pTree->GetParentItem( hItem );
			 
		}
		else
			hParent = TVI_ROOT;

		TVINSERTSTRUCT		tvIS;
		tvIS.hParent	=	hParent;
		tvIS.item.mask		=	TVIF_TEXT;
		char* label			=	(char*)str.operator LPCTSTR();	
		tvIS.item.pszText	=   label;	
		HTREEITEM hInsert   = pTree->InsertItem(&tvIS);

		pNode->m_pObj->tree = hInsert;
		pTree->SetItemData( hInsert,(DWORD)pNode );
		pTree->SetItemState( hInsert,TVIS_EXPANDED,TVIS_EXPANDED);

		
	}

}

//******************************************************************************************
//GLOBAL FUNCTION USED TO EXPORT THE HIERARCHY OF LINKED LIST TO A FILE.THIS IS A CALLBACK
//FUNCTION FOR GetPathForNode OF THE LINKED LIST.THIS IS CALLED FOR EACH NODE AFTER GETTING
//ITS HIERARCY PATH
FILE* gpFile = NULL;

void ExportPath(CString str )
{
	fprintf( gpFile,"%s\n",str );
}
//******************************************************************************************


/////////////////////////////////////////////////////////////////////////////
// CMultiLinkedListDlg dialog

CMultiLinkedListDlg::CMultiLinkedListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiLinkedListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiLinkedListDlg)
	m_sImportPath = _T("");
	m_sExportPath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pMultiList = NULL;
	m_hRightClickedItem = NULL;
}

void CMultiLinkedListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiLinkedListDlg)
	DDX_Control(pDX, IDC_TREE1, m_ctrlTree);
	DDX_Text(pDX, IDC_IMPORT_PATH, m_sImportPath);
	DDX_Text(pDX, IDC_EXPORT_PATH, m_sExportPath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiLinkedListDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiLinkedListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, OnRclickTree)
	ON_COMMAND_RANGE( IDM_NODE_INSERTAFTER,IDM_NODE_ADDCHILD,OnMenu)
	ON_BN_CLICKED(IDC_IMPORT, OnImport)
	ON_BN_CLICKED(IDC_EXPORT, OnExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiLinkedListDlg message handlers

BOOL CMultiLinkedListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiLinkedListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiLinkedListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiLinkedListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To read the data available in the given file and build the linlked list
/
/PARAM
/------
/		sFileName[IN]		-	File name which contains the hierarchy data
/
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedListDlg::BuildDataList(char* sFileName)
{
	//Check for file name
	if( !sFileName )
		return;

	//First Create the list
	if( m_pMultiList )
		delete m_pMultiList;

	m_pMultiList = new CMultiLinkedList;

	FILE* pFile = fopen(sFileName,"r");

	if( pFile )
	{
		char buf[128];
		while( fgets( buf,128,pFile) )
		{
			CString sInput = buf;
			
			//Split the strings into tokens with the delimiter
			vector<CString> vec;

			int index1 = 0;
			int index2 = sInput.Find('%');
			while( index2 > 0 )
			{
				//Read the string from index1 to index2
				CString str = sInput.Mid(index1, index2-index1 );
				vec.push_back( str );
				index1 = index2+1;
				index2 = sInput.Find("%",index1);				
			}
			CreateHierarchy( vec );
		}
		fclose( pFile );
	}
	m_ctrlTree.DeleteAllItems();
	m_pMultiList->ScanList( m_pMultiList->m_pStart,AddNodeToTree,&m_ctrlTree);
	
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To build linked list using the vector containing the data
/
/PARAM
/------
/		vec[IN]		-	Vector containing the data to be filled in the list
/
/
/RESULT:
/-------
/		void
*/
//*********************************************************************
void CMultiLinkedListDlg::CreateHierarchy( vector<CString> vec )
{
	if( !vec.size() )
		return;

	int iCnt = 0;
	int iLevel = 0;

	Data* pData    = NULL;
	Node* pParent  = NULL;
	for( iCnt = 0; iCnt < vec.size(); iCnt++ )
	{
		CString str = vec[iCnt];

		if( iLevel == 0 )
		{
			Data* pData   = new Data;
			pData->m_Name = str;
			pParent = m_pMultiList->AddStart( pData );
		}
		else
		{
			//Add the child 
			Data* pData   = new Data;
			pData->m_Name = str;
			pParent = m_pMultiList->AddChildTo( pParent,pData );

		}
		iLevel++;

	}
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To rebuild the tree
/
/PARAM
/------
/		void
/
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedListDlg::OnBuildtree() 
{
	// TODO: Add your control notification handler code here
	m_ctrlTree.DeleteAllItems();
	if( !m_pMultiList )
		return;
	m_pMultiList->ScanList( m_pMultiList->m_pStart,AddNodeToTree,&m_ctrlTree);
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			Message handler for the right click on the tree.Invokes the context
/			menu for the tree items to manipulate them
/
/PARAM
/------
/		void
/
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedListDlg::OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	//Do the hittest to find out which item is being clicked
		CPoint pt;

		//Get the current position of the cursor
		::GetCursorPos(& pt );

		//Cursor position is in screen coordiantes.Convert it to the client
		//Systen
		m_ctrlTree.ScreenToClient(&pt );
		m_hRightClickedItem = NULL;
		m_hRightClickedItem = m_ctrlTree.HitTest(pt);
		
	if( m_hRightClickedItem )
	{
		//Get the item data of the clicked item
		Node* pNode = (Node*)m_ctrlTree.GetItemData( m_hRightClickedItem );
	
		if( pNode )
		{
			if( m_menu.GetSafeHmenu() )
				m_menu.DestroyMenu();

			//Create the popup menu
			m_menu.CreatePopupMenu();

			//Add the menu items
			m_menu.AppendMenu( MF_STRING, IDM_NODE_INSERTBEFORE,"Insert Before");
			m_menu.AppendMenu( MF_STRING, IDM_NODE_INSERTAFTER,"Insert After");
			m_menu.AppendMenu( MF_STRING, IDM_NODE_DELETE,"Delete");
			m_menu.AppendMenu( MF_STRING, IDM_NODE_ADDCHILD,"Add Child");
			

			m_ctrlTree.ClientToScreen(&pt );
			m_menu.TrackPopupMenu( TPM_LEFTBUTTON,pt.x,pt.y,this );

		}
		
	}
	*pResult = 0;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			Message handler for the context menu items
/
/PARAM
/------
/		void
/
/
/RESULT:
/-------
/		void
*/
//*********************************************************************
void CMultiLinkedListDlg::OnMenu( UINT nID )
{
	if( nID == IDM_NODE_INSERTBEFORE )
	{
		//Get the right clicked item
		if( m_hRightClickedItem )
		{
			//Get the data of the tree item
			Node* pNode = (Node*)m_ctrlTree.GetItemData( m_hRightClickedItem );

			//Now we have to insert a new item before the pNode;
			//Get the name of the node from the user
			CLabelInputDlg dlg;
			if( dlg.DoModal() == IDOK )
			{
				if( m_pMultiList )
				{
					Data* pData = new Data;
					pData->m_Name = dlg.m_sLabel;
					m_pMultiList->InsertBefore(pNode,pData );
				}
			}
		}
	}
	else if( nID == IDM_NODE_ADDCHILD )
	{
		//Get the data of the tree item
		Node* pNode = (Node*)m_ctrlTree.GetItemData( m_hRightClickedItem );

			//Now we have to insert a new item before the pNode;
			//Get the name of the node from the user
			CLabelInputDlg dlg;
			if( dlg.DoModal() == IDOK )
			{
				if( m_pMultiList )
				{
					Data* pData = new Data;
					pData->m_Name = dlg.m_sLabel;
					m_pMultiList->AddChildTo(pNode,pData );
				}
			}
	}
	else if( nID == IDM_NODE_INSERTAFTER )
	{
		//Get the data of the tree item
		Node* pNode = (Node*)m_ctrlTree.GetItemData( m_hRightClickedItem );

			//Now we have to insert a new item before the pNode;
			//Get the name of the node from the user
			CLabelInputDlg dlg;
			if( dlg.DoModal() == IDOK )
			{
				if( m_pMultiList )
				{
					Data* pData = new Data;
					pData->m_Name = dlg.m_sLabel;
					m_pMultiList->InsertAfter(pNode,pData );
				}
			}
	}
	else if( nID == IDM_NODE_DELETE )
	{
		//Get the data of the tree item
		Node* pNode = (Node*)m_ctrlTree.GetItemData( m_hRightClickedItem );
		m_pMultiList->DeleteNodeAndItsChildern(pNode);
	}
	else
		return;

	OnBuildtree();
	


}
//***************************************************************************
void CMultiLinkedListDlg::OnImport() 
{
	// TODO: Add your control notification handler code here

	//Open the file dialog to select the input file
	char szFilter[] = "All Files (*.*)|*.*";

	CFileDialog fileDlg( TRUE,
					  "*.*",
					  NULL,
					  NULL,
					  szFilter,
					  this );

	char dirName[128];
	GetCurrentDirectory( sizeof(dirName),dirName );
	fileDlg.m_ofn.lpstrInitialDir = dirName;

	int val  = fileDlg.DoModal();
	if( val == IDOK )
	{
		CString sFileName = fileDlg.GetPathName();
		BuildDataList((char*)sFileName.operator LPCTSTR());
	}

	
}
//***************************************************************************
void CMultiLinkedListDlg::OnExport() 
{

	if( !m_pMultiList )
		return;

	// TODO: Add your control notification handler code here
	CString str;
	gpFile = NULL;

	char szFilter[] = "Text Files (*.txt)|*.txt";

	CFileDialog fileDlg( TRUE,
					  "*.txt",
					  NULL,
					  NULL,
					  szFilter,
					  this );

	char dirName[128];
	GetCurrentDirectory( sizeof(dirName),dirName );
	fileDlg.m_ofn.lpstrInitialDir = dirName;

	int val  = fileDlg.DoModal();
	if( val == IDOK )
	{
		CString sFileName = fileDlg.GetPathName();
		gpFile = fopen( (char*) sFileName.operator LPCTSTR(),"w");
		m_pMultiList->GetPathForNode( 	m_pMultiList->m_pStart, str,ExportPath );

	}

	if( gpFile )
		fclose(gpFile );
}
//*********************************************************************
void CMultiLinkedListDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//Delete the linked list
	if( m_pMultiList )
		delete m_pMultiList;

	CDialog::OnCancel();
}
//*********************************************************************
void CMultiLinkedListDlg::OnOK() 
{
	// TODO: Add extra validation here
	//Delete the linked list
	if( m_pMultiList )
		delete m_pMultiList;

	CDialog::OnOK();
}
