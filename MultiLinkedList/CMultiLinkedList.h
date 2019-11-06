// CMultiLinkedList.h: interface for the CMultiLinkedList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMULTILINKEDLIST_H__B4B71B11_22DF_4683_B91A_85031F9F76B8__INCLUDED_)
#define AFX_CMULTILINKEDLIST_H__B4B71B11_22DF_4683_B91A_85031F9F76B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



//*******************************************************************
//================================================================
	//Class to hold the information about the name of the tree entity and 
	//the handle of the tree item associated with it
//===================================================================
class Data
{
public:
	Data()
	{
		m_pData = NULL;
		tree    = NULL;
	}

public:
	CString			m_Name;
	void*			m_pData;
	HTREEITEM		tree;
};
//*******************************************************************

class CMultiLinkedList;


//================================================================
//	Node to hold the information about the entity and its relative
//	linkage
//================================================================
class Node
{
public:
	Node(CMultiLinkedList* pList = NULL);
	~Node();

public:

	//Usually for a node the previous and next will be of same level.
	Node* m_pPrev;

	//To hold the node which is next
	Node* m_pNext;

	//Usually for a node the right will of one level down the node
	Node* m_pRight;

	//Usually for a node the left will of one level up the node
	Node* m_pLeft;

	//To hold the data of the node
	Data*  m_pObj;

	//To indicate the level of the node
	int   m_level;

	//To  know the list details to which this node is associated
	CMultiLinkedList* m_pParentList;
};
//*******************************************************************

typedef struct __CALLBACKINFO
{
	Node* pNode;
	void* m_pParam;
}CALLBACKINFO,*PCALLBACKINFO;

typedef void (*ListCallBack) (PCALLBACKINFO );

//================================================================
//	Complete list used to manage the material data base
//================================================================
class CMultiLinkedList
{
public:
	CMultiLinkedList();
	virtual ~CMultiLinkedList();

	void DeleteLinkedNodes(Node* pNode);
	void DeleteChildren( Node* pNode,bool flag = false );
	void DeleteNodeAndItsChildern( Node* pNode );
	
	//To add the root or start node for the list
	Node* AddStart(Data* pData );	//[in]	-	Data to be used for the start node
	
	//Add new sibling node to the pNode and use the data pData for child node
	Node* AddSiblingTo(Node* pNode,		//[in]	-	Node to which the sibling to be added
					   Data* pData );	//[in]	-	Data to be used for the sibling node
	
	//Add new child node to the pNode and use the data pData for right node
	Node* AddChildTo(Node* pNode,		//[in]	-	Node to which the child to be added
					 Data* pData );		//[in]	-	Data to be used for the child node

	//To add a new node before a given node
	Node* InsertBefore(Node* pNode,			//[in]	-	Node before which the new node to be inserted
					   Data* pData );		//[in]	-	Data to be used for the new node

	//To add a new node before a given node
	Node* InsertAfter(Node* pNode,		//[in]	-	Node after which the new node to be inserted
					  Data* pData );	//[in]	-	Data to be used for the new node

	//To check the right node with its name
	Node* CheckRightNode( Node* pNode,		//[in]	-	Node whose right nodes to be checked
						  CString sName );	//[in]	-	Name of the node to be searched

	//To find the name of a leaf of given level
	Node* FindName( Node* pNode,			//[in]	-	Node from where the search to be started
					int level,				//[in]	-	Level to stop the search
					CString sLeafName );	//[in]	-	Name to be searched

	//To scan the list 
	void ScanList(Node* pNode = NULL,		//[in]	-	Node from where the scanning to be started
				  ListCallBack func = NULL,	//[in]	-	Callback function to be called for each node
				  void* pUserInfo = NULL);	//[in]	-	Any user specific information

	//To get the hierarchy path for a given node.Path starts from the root
	void GetPathForNode(Node* pNode,				//[in]	-	Node whose path to be found
						CString str,				//[in]	-	String carries the path
						void (*CB)(CString str));	//[in]	-	Callback function called after finding the path

	//To find the last node in a given branch
	Node* GetLastNode(Node* pNode );	//[in]	-	Node whose tail [last] node to be found


public:
	Node*	m_pStart;
	Node*	m_pEnd;
};


#endif // !defined(AFX_CMULTILINKEDLIST_H__B4B71B11_22DF_4683_B91A_85031F9F76B8__INCLUDED_)
