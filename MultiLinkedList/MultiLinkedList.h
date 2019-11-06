// MultiLinkedList.h : main header file for the MULTILINKEDLIST application
//

#if !defined(AFX_MULTILINKEDLIST_H__D78C888A_FE22_4892_8DA0_0AD8A0668C1B__INCLUDED_)
#define AFX_MULTILINKEDLIST_H__D78C888A_FE22_4892_8DA0_0AD8A0668C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiLinkedListApp:
// See MultiLinkedList.cpp for the implementation of this class
//

class CMultiLinkedListApp : public CWinApp
{
public:
	CMultiLinkedListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiLinkedListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiLinkedListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTILINKEDLIST_H__D78C888A_FE22_4892_8DA0_0AD8A0668C1B__INCLUDED_)
