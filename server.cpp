#include <iostream>
#include "server.h"

using std ::cout;
using std ::endl;

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

void CList ::InsertAtFirst(int iNo)
{
    CNode *pNewNode = NULL;

    pNewNode = new CNode;
    if (NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = m_pFirst;
    m_pFirst = pNewNode;
}

void CList ::InsertAtLast(int iNo)
{
    CNode *pNewNode = NULL;
    CNode *pTemp = NULL;

    pNewNode = new CNode;
    if (NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;
    pNewNode->m_pNext = NULL;

    if (NULL == m_pFirst)
    {
        m_pFirst = pNewNode;
        return;
    }

    pTemp = m_pFirst;

    while (pTemp->m_pNext != NULL)
        pTemp = pTemp->m_pNext;

    pTemp->m_pNext = pNewNode;
}

int CList ::DeleteFirst()
{
    int iDelData;

    CNode *pTemp = NULL;

    if (NULL == m_pFirst)
        return -1;

    iDelData = m_pFirst->m_iData;

    pTemp = m_pFirst;
    m_pFirst = pTemp->m_pNext;
    pTemp->m_pNext = NULL;
    delete pTemp;
    pTemp = NULL;

    return iDelData;
}

int CList ::DeleteLast()
{
    int iDelData;

    CNode *pTemp = NULL;

    if (NULL == m_pFirst)
        return -1;

    if (m_pFirst->m_pNext == NULL)
    {
        iDelData = m_pFirst->m_iData;
        delete m_pFirst;
        m_pFirst = NULL;
    }
    else
    {
        pTemp = m_pFirst;
        while (pTemp->m_pNext->m_pNext != NULL)
            pTemp = pTemp->m_pNext;

        iDelData = pTemp->m_pNext->m_iData;
        delete pTemp->m_pNext;
        pTemp->m_pNext = NULL;
        pTemp = NULL;
    }

    return iDelData;
}
void CList ::InsertAtPosition(int, int)
{
}
int CList ::DeleteAtPosition(int)
{
}

int CList ::CountNodes()
{
    int iCount = 0;
    CNode *pTemp = m_pFirst;

    while (pTemp != NULL)
    {
        iCount++;
        pTemp = pTemp->m_pNext;
    }

    return iCount;
}

int CList ::SearchFirstOccurance(int iKey)
{
    int iPosition = 0;
    CNode *pTemp = m_pFirst;

    while (pTemp != NULL)
    {
        iPosition++;
        if(pTemp->m_iData == iKey)
            return iPosition;
        pTemp = pTemp->m_pNext;
    }

    return 0;
}

int CList ::SearchLastOccuarnce(int iKey)
{
    int iPosition = 0;
    int iLastPosition;

    CNode *pTemp = m_pFirst;

    while (pTemp != NULL)
    {
        iPosition ++;
        if(pTemp->m_iData == iKey)
            iLastPosition = iPosition;
        pTemp = pTemp->m_pNext;
    }

    return iLastPosition;
}

int CList ::SearchAllOccuarnces(int iKey)
{
    int iCount = 0;

    CNode *pTemp = m_pFirst;

    while(pTemp != NULL)
    {
        if(iKey == pTemp->m_iData)
            iCount ++;
        pTemp = pTemp->m_pNext;
    }

    return iCount;
}

void CList ::ConcatLists()
{
}
void CList ::ConcatAtPosition()
{
}

void CList ::Display()
{
    CNode *pTemp = m_pFirst;

    while(pTemp != NULL)
    {
        cout << "|" << pTemp->m_iData << "|" << "->";
        pTemp = pTemp->m_pNext;
    }
    cout << "|NULL|\n";
}

void CList ::ReverseDisplay()
{
}
void CList ::PhysicalReverse()
{
}

void CList ::DeleteAll()
{
    CNode *pTemp = NULL;

    while(m_pFirst != NULL)
    {
        pTemp = m_pFirst;
        m_pFirst = pTemp->m_pNext;
        pTemp->m_pNext = NULL;
        delete pTemp;
        pTemp = NULL;
    }
}