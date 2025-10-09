#pragma once
#include <iostream>

class CList;

class CNode
{
    int m_iData;
    CNode *m_pNext;

public :
    CNode();
    ~CNode();

    friend class CList;
};

class CList 
{
    CNode *m_pFirst;

public :
    CList();
    ~CList();
    void InsertAtFirst(int);
    void InsertAtLast(int);
    int DeleteFirst();
    int DeleteLast();
    void InsertAtPosition(int, int);
    int DeleteAtPosition(int);
    int CountNodes();
    int SearchFirstOccurance(int);
    int SearchLastOccuarnce(int);
    int SearchAllOccuarnces(int);
    void ConcatLists();
    void ConcatAtPosition();
    void Display();
    void ReverseDisplay();
    void PhysicalReverse();
    void DeleteAll();
};
