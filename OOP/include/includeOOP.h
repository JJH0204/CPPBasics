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
};

template <typename T>
void LinkedList<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;
    int nLoop = 0;

    if ((pCurNode = this->getHeader()) == nullptr)
        return;

    std::cout << "|index\t|data\t|" << std::endl;

    for (; nLoop < this->getCurrent() && pCurNode != nullptr; nLoop++)
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
        pNewNode->setNext(pCurrentNode->getNext());
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
        pNewNode->setNext(pCurrentNode->getNext());
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
    if (this == &temp)
        return;

    Node<T> *pCurrentNode = temp.getHeader();
    for (int i = 0; pCurrentNode != nullptr && i < temp.getCurrent(); i++)
    {
        Add(pCurrentNode->getData(), i);
        pCurrentNode = pCurrentNode->getNext();
    }
}