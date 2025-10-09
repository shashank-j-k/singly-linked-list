#include <iostream>
#include "server.h"

using std :: cout;
using std :: endl;

CNode ::CNode()
{
    m_iData = 0;
    m_pNext = NULL;
}

CNode ::~CNode()
{
    m_iData = 0;
    m_pNext = NULL;
}

CList ::CList()
{
    m_pFirst = NULL;
}

CList ::CList()
{
   if (m_pFirst != NULL)
   {
        DeleteAll();
   }
}

void CList :: InsertAtFirst(int iNo)
{
    CNode *pNewNode = NULL;

    pNewNode = new CNode;
    if(NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = m_pFirst;
    m_pFirst = pNewNode;
}

void CList :: InsertAtLast(int iNo)
{
    CNode *pNewNode = NULL;
    CNode *pTemp = NULL;

    pNewNode = new CNode;
    if(NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = NULL;

    if(NULL == m_pFirst)
    {
        m_pFirst = pNewNode;
        return;
    }

    pTemp = m_pFirst;

    while(pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    pTemp->m_pNext = pNewNode;

}
int CList :: DeleteFirst()
{
    int iDelData;

    CNode *pTemp = NULL;

    if(NULL == m_pFirst)
        return -1;

    iDelData = m_pFirst->m_iData;

    pTemp = m_pFirst;
    m_pFirst = pTemp->m_pNext;
    pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    return iDelData;
}

int CList :: DeleteLast()
{

}
void CList :: InsertAtPosition(int, int)
{

}
int CList :: DeleteAtPosition(int)
{

}
int CList :: CountNodes()
{

}
int CList :: SearchFirstOccurance(int)
{

}
int CList :: SearchLastOccuarnce(int)
{

}
int CList :: SearchAllOccuarnces(int)
{

}
void CList :: ConcatLists()
{

}
void CList :: ConcatAtPosition()
{

}
void CList :: Display()
{

}
void CList :: ReverseDisplay()
{

}
void CList :: PhysicalReverse()
{

}
void CList :: DeleteAll()
{

}