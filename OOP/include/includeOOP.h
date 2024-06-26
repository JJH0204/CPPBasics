#pragma once
#include "includeNode.h"

/* 연결 리스트 클래스 */
template <typename T>
class LinkedList
{
private:
    Node<T> *_Header;
    int _Current;

public:
    LinkedList(void) : _Header(nullptr), _Current(0) {}
    LinkedList(const LinkedList &temp) { Copy(temp); }
    ~LinkedList() { Destruct(); }

    Node<T> *getHeader(void) const { return _Header; }
    void setHeader(Node<T> *newHeader) { _Header = newHeader; }
    int getCurrent(void) const { return _Current; }
    void setCurrent(int current) { _Current = current; }

    /* 테이블 형식으로 리스트 출력 */
    void PrintT(void);

    /* 리스트 데이터 추가 */
    void Add(const Node<T> &data = T(), const int index = -1);
    void Add(const T &data, const int index = -1);

    /* 리스트 데이터 삭제 */
    void Remove(const int index = 0);

    /* 리스트 전체 삭제 */
    void Destruct(void);

    /* 리스트 복사 */
    void Copy(const LinkedList &temp);

    /* 리스트 정렬 */
    void Sort(int (*compar)(const T &, const T &));
};

template <typename T>
void LinkedList<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;

    if ((pCurNode = this->getHeader()) == nullptr || this->getCurrent() < 1)
        return;

    std::cout << "|index\t|data\t|" << std::endl;

    for (int nLoop = 0; nLoop < this->getCurrent() && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|" << pCurNode->getData() << "\t|" << std::endl;
        pCurNode = pCurNode->getNext();
    }
}

template <typename T>
void LinkedList<T>::Add(const Node<T> &data, const int index)
{
    Node<T> *pNewNode = new (std::nothrow) Node<T>;
    /* (std::nothrow) 키워드를 이용해 할당 실패시 nullptr을 반환하도록 설정 */

    /* 할당 실패 시 함수 종료 */
    if (pNewNode == nullptr)
        return;

    *pNewNode = data;

    if (index < 1)
    {
        if (this->getHeader() != nullptr)
            pNewNode->setNext(this->getHeader());
        this->setHeader(pNewNode);
    }
    else
    {
        Node<T> *pCurrentNode = this->getHeader();
        for (int i = 1; i < index && pCurrentNode->getNext() != nullptr; i++)
            pCurrentNode = pCurrentNode->getNext();
        pNewNode->setNext(pCurrentNode->getNext() == nullptr ? nullptr : pCurrentNode->getNext());
        pCurrentNode->setNext(pNewNode);
    }
    this->setCurrent(this->getCurrent() + 1);
}

template <typename T>
void LinkedList<T>::Add(const T &data, const int index)
{
    Node<T> *pNewNode = new (std::nothrow) Node<T>;

    if (pNewNode == nullptr)
        return;

    pNewNode->setData(data);

    if (index < 1)
    {
        if (this->getHeader() != nullptr)
            pNewNode->setNext(this->getHeader());
        this->setHeader(pNewNode);
    }
    else
    {
        Node<T> *pCurrentNode = this->getHeader();
        for (int i = 1; i < index && pCurrentNode->getNext() != nullptr; i++)
            pCurrentNode = pCurrentNode->getNext();
        pNewNode->setNext(pCurrentNode->getNext() == nullptr ? nullptr : pCurrentNode->getNext());
        pCurrentNode->setNext(pNewNode);
    }
    this->setCurrent(this->getCurrent() + 1);
}

template <typename T>
void LinkedList<T>::Remove(const int index)
{
    if (this->getHeader() == nullptr)
        return;

    Node<T> *pCurrentNode = this->getHeader();

    if (index <= 0)
    {
        this->setHeader(pCurrentNode->getNext() != nullptr ? pCurrentNode->getNext() : nullptr);
    }
    else
    {
        Node<T> *pPreviousNode = nullptr;
        for (int i = 0; i < index && pCurrentNode->getNext() != nullptr; i++)
        {
            pPreviousNode = pCurrentNode;
            pCurrentNode = pCurrentNode->getNext();
        }

        if (pCurrentNode == nullptr)
            return;

        if (pPreviousNode != nullptr)
            pPreviousNode->setNext(pCurrentNode->getNext());
    }

    delete pCurrentNode;
    this->setCurrent(this->getCurrent() - 1);
}

template <typename T>
void LinkedList<T>::Destruct(void)
{
    while (this->getHeader() != nullptr && this->getCurrent() > 0)
        this->Remove();
}

template <typename T>
void LinkedList<T>::Copy(const LinkedList<T> &temp)
{
    this->setCurrent(0);

    if (this == &temp)
        return;

    Node<T> *pCurrentNode = temp.getHeader();
    for (int i = 0; pCurrentNode != nullptr && i < temp.getCurrent(); i++)
    {
        Add(pCurrentNode->getData(), i);
        pCurrentNode = pCurrentNode->getNext();
    }
}

template <typename T>
void LinkedList<T>::Sort(int (*compar)(const T &, const T &))
{
    if (this->getHeader() == nullptr || this->getCurrent() < 2)
        return;

    /* 단순 선택 정렬(버블정렬 알고리즘) */
    Node<T> *pCurrentNode = this->getHeader();
    for (int i = 0; i < this->getCurrent() - 1 && pCurrentNode->getNext() != nullptr; i++)
    {
        Node<T> *pTargetNode = pCurrentNode->getNext();
        for (int n = 1; n < this->getCurrent() && pTargetNode != nullptr; n++)
        {
            if (compar(pCurrentNode->getData(), pTargetNode->getData()) > 0)
            {
                T temp = pCurrentNode->getData();
                pCurrentNode->setData(pTargetNode->getData());
                pTargetNode->setData(temp);
            }
            pTargetNode = pTargetNode->getNext();
        }
        pCurrentNode = pCurrentNode->getNext();
    }
}

void exLinkedList1(void);
void exLinkedList2(void);

template <typename T>
class Stack
{
private:
    Node<T> *_Top;
    int _Current;

public:
    Stack(void) : _Top(nullptr), _Current(0) {}
    Stack(Stack<T> &Temp) { Copy(Temp); }
    ~Stack(void) {}

    void setTop(Node<T> *Temp) { _Top = Temp; }
    Node<T> *getTop(void) { return _Top; }
    void setCurrent(const int n) { _Current = n; }
    int getCurrent(void) { return _Current; }

    void Push(const T &data);
    T Pop(void);
    T Peek(void);
    void Copy(Stack<T> &Temp);
    void Destruct(void);
    void PrintT(void);
};

template <typename T>
void Stack<T>::Push(const T &data)
{
    Node<T> *newNode = new (std::nothrow) Node<T>;
    if (newNode == nullptr)
        return;
    newNode->setData(data);

    newNode->setNext(this->getTop());
    this->setTop(newNode);
    this->setCurrent(this->getCurrent() + 1);
}

template <typename T>
T Stack<T>::Pop(void)
{
    if (this->getTop() == nullptr)
    {
        if constexpr (std::is_pointer_v<T>)
            return nullptr;
        else
            throw std::runtime_error("Stack is empty and T is not a pointer type.");
    }
    Node<T> *pCurrentNode = this->getTop();
    T temp = pCurrentNode->getData();
    this->setTop(pCurrentNode->getNext());
    delete pCurrentNode;
    this->setCurrent(this->getCurrent() - 1);
    return temp;
}

template <typename T>
T Stack<T>::Peek(void)
{
    if (this->getTop() == nullptr)
    {
        if constexpr (std::is_pointer_v<T>)
            return nullptr;
        else
            throw std::runtime_error("Stack is empty and T is not a pointer type.");
    }
    Node<T> *pCurrentNode = this->getTop();
    return pCurrentNode->getData();
}

template <typename T>
void Stack<T>::Copy(Stack<T> &Temp)
{
    if (Temp.getTop() == nullptr || Temp.getCurrent() < 1)
        return;

    T *pTemp = new T[Temp.getCurrent()];
    Node<T> *pCurrentNode = Temp.getTop();
    int i = 0;
    for (; i < Temp.getCurrent() && pCurrentNode != nullptr; i++)
    {
        pTemp[i] = pCurrentNode->getData();
        pCurrentNode = pCurrentNode->getNext();
    }
    for (; 0 < i; i--)
        this->Push(pTemp[i - 1]);
    delete[] pTemp;
}

template <typename T>
void Stack<T>::Destruct(void)
{
    while (this->getCurrent() > 0 && this->getTop() != nullptr)
        this->Pop();
}

template <typename T>
void Stack<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;

    if ((pCurNode = this->getTop()) == nullptr || this->getCurrent() < 1)
        return;

    std::cout << "|index\t|data\t|" << std::endl;

    for (int nLoop = 0; nLoop < this->getCurrent() && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|" << pCurNode->getData() << "\t|" << std::endl;
        pCurNode = pCurNode->getNext();
    }
}

void exStack1(void);