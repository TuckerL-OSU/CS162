// CMultiLinkedList.cpp: implementation of the CMultiLinkedList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MultiLinkedList.h"
#include "CMultiLinkedList.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Node::Node(CMultiLinkedList* pList /*= NULL*/ )
{
	m_pPrev = NULL;
	m_pNext = NULL;
	m_pRight = NULL;
	m_pLeft = NULL;
	m_pParentList = pList;
	m_pObj = NULL;
}
//*********************************************************************
Node::~Node()
{
	if( m_pObj )
		delete m_pObj;
}
//*********************************************************************
CMultiLinkedList::CMultiLinkedList()
{
	m_pStart = NULL;
	m_pEnd   = NULL;

}

CMultiLinkedList::~CMultiLinkedList()
{
	//Delete all the linked nodes of the start node
	DeleteLinkedNodes( m_pStart );
}

/***************************************************************************
/DESCRIPTION:
/-----------
/			To delete all the linked nodes of a given node.
/			Given a node this function loop through using next pointer till the end
/			of the branch and delete all the linked nodes
/
/PARAM
/------
/		pNode[IN]	-	Node whose all the linked nodes to be deleted
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedList::DeleteLinkedNodes(Node* pNode)
{
	for( ; pNode != NULL;  )
	{
		Node* delNode =  pNode;
		pNode	  =  pNode->m_pNext;

		//If branch found i.e, if pNode has children delete all of them
		if( delNode->m_pRight )
			DeleteChildren(delNode->m_pRight );

		//If the node is start node in a branch,then move the next node of the pNode
		//as the start node of the branch
		if( delNode->m_pLeft )
		{
			//If the node is a start node in a branch and it has a sibling
			if( delNode->m_pNext )
			{
				delNode->m_pLeft->m_pRight = delNode->m_pNext;
				delNode->m_pNext->m_pLeft  = delNode->m_pLeft;
			
				if( delNode->m_pPrev )
					delNode->m_pNext->m_pPrev = delNode->m_pPrev;
				else
					delNode->m_pNext->m_pPrev = NULL;
			}
			else
				delNode->m_pLeft->m_pRight = NULL;
			
		}
		delete delNode;
		delNode = NULL;

					
	}	
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To delete all the associated children of a given node
/
/PARAM
/------
/		pNode[IN]	-	Node whose children to be deleted
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedList::DeleteChildren( Node* pNode,bool flag  )
{
	//If branch found i.e, if pNode has children delete all of them
	if( pNode->m_pRight )
	{
		DeleteChildren(pNode->m_pRight); 	
	}

	//If the node is start node in a branch,then move the next node of the pNode
	//as the start node of the branch
	if( pNode->m_pLeft )
	{
		if( pNode->m_pNext )
		{
			pNode->m_pLeft->m_pRight = pNode->m_pNext;
			pNode->m_pNext->m_pLeft  = pNode->m_pLeft;
			
			if( pNode->m_pPrev )
			{
				pNode->m_pNext->m_pPrev  = pNode->m_pPrev;
				pNode->m_pPrev ->m_pNext = pNode->m_pNext;
			}
			else
				pNode->m_pNext->m_pPrev = NULL;
			
		}
		else
			pNode->m_pLeft->m_pRight = NULL;
	}
	if( pNode->m_pRight )
	{
		DeleteChildren(pNode->m_pRight); 	
	}

	//Delete all the linked nodes of the pNode
	DeleteLinkedNodes( pNode );

}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To delete a given node and all the associated children of the node
/
/PARAM
/------
/		pNode[IN]	-	Node to be deleted
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedList::DeleteNodeAndItsChildern( Node* pNode )
{
	if( !pNode )
		return;

	//Childeren of a node starts from its right node
	Node* pChildNodeIter = pNode->m_pRight;
	
	//NOTE
	//Break the link of the node and delete it.If we dont break the link and calling
	//DeleteChildren will delete all the nodes.Because DeleteChildren internally calls
	//Delete linked nodes.
	//So what we do is isolate the pNode from its parent [ if pNode is child to another node.Break the left link]
	//and isolate from the siblings [ if pNode is a node in a branch break the prev and next links ].
	//Dont remove the right link because it is the way to reach the branch [ children ]

	//This is means this is start node in a branch
	if( pNode->m_pLeft )
	{
		//Get the next node in the branch and establish a link with
		//its parent.
		Node* pNextNode = pNode->m_pNext;

		if( pNextNode )
		{
			//Get the parent node 
			Node* pParentNode = pNode->m_pLeft;

			//As we are going to delete this pNode, move the pNextNode to
			//the position of the pNode.
			pParentNode->m_pRight = pNextNode;
			pNextNode->m_pLeft    = pParentNode;
			pNextNode->m_pPrev    = NULL;

			pNode->m_pLeft = NULL;
			pNode->m_pNext = NULL;
			

		}
		
	}
	//Intermediate node means rearrange the links
	else
	{
		Node* pPrev = pNode->m_pPrev;
		Node* pNext = pNode->m_pNext;

		if( pPrev )
			pPrev->m_pNext = pNext;
		if( pNext )
			pNext->m_pPrev = pPrev;
		
	}
	//Delete all the children
	DeleteChildren(pNode,true);

}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To add the start node
/
/PARAM
/------
/		pData[IN]	-	Data to be used for the start node
/
/RESULT:
/-------
/		Created node if successfully added,NULL otherwise
*/
Node* CMultiLinkedList::AddStart(Data* pData )
{
	//Check for start node.If start is there return
	if( m_pStart )
	{
		if( pData ) delete pData;
		return m_pStart;
	}

	m_pStart = new Node(this);
	m_pStart->m_pObj = pData;

	//Start node has the level 0 and level will be increased for each branch
	m_pStart->m_level = 0;

	return m_pStart;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To add new sibling node to the pNode and use the data pData for that
/			Sibling will be in the same level as pNode
/
/PARAM
/------
/		pNode[in]	-	Node to which the sibling to be added
/		pData[IN]	-	Data to be used for the sibling node
/
/RESULT:
/-------
/		Created node if successfully added,NULL otherwise
*/
Node* CMultiLinkedList::AddSiblingTo(Node* pNode,Data* pData )
{
	if( !pNode || !pData )
		return NULL;

	//Create a new node
	Node* pNewNode = new Node(this);

	//Associated the data with the new node
	pNewNode->m_pObj = pData;

	//Sibling is in the same level
	pNewNode->m_level = pNode->m_level;

	//Create the link for the new node.Sibling means pNode's next will be the
	//new node and new node's prev will be the pNode
	pNode->m_pNext    = pNewNode;
	pNewNode->m_pPrev = pNode;

	return pNewNode;

}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To add new right [Child] node to the pNode and use the data 
/			pData for right node.Child will be one level down than pNode
/
/PARAM
/------
/		pNode[IN]	-	Node to which the child to be added
/		pData[IN]	-	Data to be used for the right node
/
/RESULT:
/-------
/		Created node if successfully added,NULL otherwise
*/
Node* CMultiLinkedList::AddChildTo(Node* pNode,Data* pData )
{
	if( !pNode || !pData )
		return NULL;

	//First find if there is any node exisiting already in the same level with samename
	Node* pRes  = FindName( pNode,pNode->m_level+1,pData->m_Name );

	//If so, then delete the pData as its allocated on the heap.otherwise memory leaks
	if( pRes )
	{
		//Delete the pData
		delete pData;
		return pRes;
	}

	//The pNode might have the right branch but the name is not found in the branch
	//So add the new node as the last node to branch
	if( pNode->m_pRight )
	{
		pRes = GetLastNode( pNode->m_pRight );
		return ( AddSiblingTo( pRes,pData) ); 
	}	
	
	//Create a new node
	Node* pNewNode = new Node(this);

	//Associated the data with the new node
	pNewNode->m_pObj = pData;

	//Because child node is one level up than the pNode.
	pNewNode->m_level = pNode->m_level+1;	

	//Create the link for the new node.Child means pNode's next will be the
	//new node and new node's prev will be the pNode
	pNode->m_pRight    = pNewNode;
	pNewNode->m_pLeft  = pNode;

	return pNewNode;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To add a new node before the given node
/
/PARAM
/------
/		pNode[IN]	-	Node before which the new node to be inserted
/		pData[IN]	-	Data to be used for the new node
/
/RESULT:
/-------
/		Created node if successfully added,NULL otherwise
*/
Node* CMultiLinkedList::InsertBefore(Node* pNode,Data* pData )
{
	if( !pNode )
		return NULL;

	//Create a new node
	Node* pNewNode = new Node(this);

	//Associated the data with the new node
	pNewNode->m_pObj = pData;

	//Because child node is one level down
	pNewNode->m_level = pNode->m_level;	

	//Create the link for the new node.If the pNode is starting node in given
	//branch then we have to move the pNewNode to the position of pNode
	if( pNode->m_pLeft )
	{
		pNode->m_pLeft->m_pRight = pNewNode;
		pNewNode->m_pLeft	= pNode->m_pLeft;
		pNode->m_pLeft		= NULL;
	}

	pNode->m_pPrev    = pNewNode;
	pNewNode->m_pNext = pNode;

	return pNewNode;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To add a new node after the given node
/
/PARAM
/------
/		pNode[IN]	-	Node after which the new node to be inserted
/		pData[IN]	-	Data to be used for the new node

/
/RESULT:
/-------
/		Created node if successfully added,NULL otherwise
*/
Node* CMultiLinkedList::InsertAfter(Node* pNode,Data* pData )
{
	if( !pNode )
		return NULL;

	//Create a new node
	Node* pNewNode = new Node(this);

	//Associated the data with the new node
	pNewNode->m_pObj = pData;

	//Because child node is one level down
	pNewNode->m_level = pNode->m_level;	

	//Create the link for the new node.
	pNewNode->m_pPrev    = pNode;

	if( pNode->m_pNext )
	{
		pNode->m_pNext->m_pPrev = pNewNode;
		pNewNode->m_pNext = pNode->m_pNext;
	}

	pNode->m_pNext = pNewNode;
	return pNewNode;
}

/***************************************************************************
/DESCRIPTION:
/-----------
/			To check all the right nodes of a given node against the given name
/
/PARAM
/------
/		pNode[IN]	-	Node whose right side nodes to be checked
/		sName[IN]	-	Name to be checked
/
/RESULT:
/-------
/		Node Pointer if successfully found,NULL otherwise
*/
Node* CMultiLinkedList::CheckRightNode( Node* pNode,CString sName )
{
	if( !pNode || sName.IsEmpty() )
		return NULL;

	//Get the right node
	Node* pRight = pNode->m_pRight;

	//loop through all the decendants of the pRight [ all the nodes of the branch ]
	//and check with the name
	while( pRight )
	{
		//Get the data
		Data* pData = pRight->m_pObj;

		if( pData )
		{
			if( pData->m_Name == sName )
				return pRight;
		}

		//Go ahead with the node which is next to pRight
		pRight = pRight->m_pNext;
	}

	return NULL;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To check all the right nodes of a given node against the given name
/
/PARAM
/------
/		pNode[IN]		-	Node from where the search to be started
/		level[IN]		-	Level to stop the search
/		sLeafName[IN]	-	Name to be searched
/
/
/RESULT:
/-------
/		Node Pointer if successfully found,NULL otherwise
*/
//***************************************************************************
Node* CMultiLinkedList::FindName( Node* pNode,int level,CString sLeafName )
{
	Node* pRes = NULL;

	if( sLeafName.IsEmpty() )
		return NULL;

	if( !pNode )
		return NULL;

	if( pNode->m_level < level )
	{
		pRes = FindName( pNode->m_pRight,level,sLeafName );
	}
	else if( pNode->m_level == level )
	{
		while( pNode )
		{
			//Get the data
			Data* pData = pNode->m_pObj;

			if( pData )
			{
				if( pData->m_Name == sLeafName )
					return pNode;
			}

			//Go ahead with the node which is next to pRight
			pNode = pNode->m_pNext;
		}
	}

	return pRes;
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To scan the list 
/
/PARAM
/------
/		pNode[IN]		-	Node from where the search to be started
/		func[IN]		-	Callback function to be called for each node
/		pUserInfo[IN]	-	Any user specific information
/
/
/RESULT:
/-------
/		void
*/
//***************************************************************************
void CMultiLinkedList::ScanList(Node* pNode /*=NULL*/,ListCallBack func /*=NULL*/,void* pUserInfo /*= NULL*/ )
{
	if( !pNode )
		return;

	CALLBACKINFO cbInfo;
	cbInfo.pNode = pNode;
	cbInfo.m_pParam = pUserInfo;

	func( &cbInfo );

	//Get the child of the pNode
	Node* pRight = pNode->m_pRight;

	if( pRight )
	{
		ScanList( pRight,func,pUserInfo );
	}
	ScanList( pNode->m_pNext,func,pUserInfo );


}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To get the hierarchy path for a given node.Path starts from the root
/
/PARAM
/------
/		pNode[IN]		-	Node whose path to be found
/		func[IN]		-	String carries the path
/		pUserInfo[IN]	-	Callback function called for each node
/
/
/RESULT:
/-------
/		void
*/
void CMultiLinkedList::GetPathForNode(Node* pNode,CString str,void (*CB)(CString str))
{
	CString lstr;

	if( !str.IsEmpty() )
	{
		lstr = str;
		lstr +='%';
	}

	lstr += pNode->m_pObj->m_Name;

	if( !pNode  )
	{
		return;
	}

	//Loop through the children
	if( pNode->m_pRight )
	{
		GetPathForNode( pNode->m_pRight,lstr,CB );
	}
	if( pNode->m_pNext )
		GetPathForNode( pNode->m_pNext,str,CB );

	lstr +='%';
	CB(lstr);
}
/***************************************************************************
/DESCRIPTION:
/-----------
/			To find the last node in a given branch
/
/PARAM
/------
/		pNode[IN]		-	Node whose tail [last] node to be found
/
/
/RESULT:
/-------
/		Last node if found successfully
*/
//***************************************************************************
Node* CMultiLinkedList::GetLastNode(Node* pNode )
{
	if( !pNode )
		return NULL;

	while( pNode->m_pNext )
	{
		pNode = pNode->m_pNext;
	}
	return pNode;
}