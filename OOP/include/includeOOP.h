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
    LinkedList(const LinkedList &temp) {}
    ~LinkedList() { Destruct(); }

    Node<T> *getHeader(void) { return _Header; }
    void setHeader(Node<T> &newHeader) { _Header = newHeader; }
    int getCurrent(void) { return _Current; }
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
};

template <typename T>
void LinkedList<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;
    int nLoop = 0;

    if ((pCurNode = getHeader()) == nullptr)
        return;

    std::cout << "|index\t|data\t|" << std::endl;

    for (; (nLoop < getCurrent()) && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|" << pCurNode->getData() << "\t|" << std::endl;
        pCurNode = pCurNode->getNext();
    }
    return;
}

template <typename T>
void LinkedList<T>::Add(const Node<T> &data, const int index)
{
    Node<T> *newNode = new (std::nothrow) Node<T>; /* (std::nothrow) 키워드를 이용해 할당 실패시 nullptr을 반환하도록 설정 */

    if (newNode != nullptr)
    {
        *newNode = data;
        if (_Header == nullptr || index <= 0)
        { /* 리스트의 가장 처음에 데이터 넣기 */
            newNode->setNext(_Header);
            _Header = newNode;
        }
        else if (index >= getCurrent())
        { /* 리스트의 가장 마지막에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            while (currentNode->getNext() != nullptr)
                currentNode = currentNode->getNext();
            currentNode->setNext(newNode);
            newNode->setNext(nullptr);
        }
        else
        { /* 원하는 위치 index에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            for (int i = 0; i < index - 1 && currentNode != nullptr; i++)
                currentNode = currentNode->getNext();
            if (currentNode != nullptr)
            {
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
            }
            else
            {
                delete newNode; // Index가 잘못된 경우, 메모리 해제
                return;         // 잘못된 인덱스 처리
            }
        }
        _Current++;
    }
    return;
}

template <typename T>
void LinkedList<T>::Add(const T &data, const int index)
{
    Node<T> *newNode = new (std::nothrow) Node<T>; /* (std::nothrow) 키워드를 이용해 할당 실패시 nullptr을 반환하도록 설정 */

    if (newNode != nullptr)
    {
        newNode->setData(data);
        if (_Header == nullptr || index <= 0)
        { /* 리스트의 가장 처음에 데이터 넣기 */
            newNode->setNext(_Header);
            _Header = newNode;
        }
        else if (index >= getCurrent())
        { /* 리스트의 가장 마지막에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            while (currentNode->getNext() != nullptr)
                currentNode = currentNode->getNext();
            currentNode->setNext(newNode);
            newNode->setNext(nullptr);
        }
        else
        { /* 원하는 위치 index에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            for (int i = 0; i < index - 1 && currentNode != nullptr; i++)
                currentNode = currentNode->getNext();
            if (currentNode != nullptr)
            {
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
            }
            else
            {
                delete newNode; // Index가 잘못된 경우, 메모리 해제
                return;         // 잘못된 인덱스 처리
            }
        }
        _Current++;
    }
    return;
}

template <typename T>
void LinkedList<T>::Remove(const int index)
{
    if (0 >= _Current || index > _Current || index < 0)
        return;
    Node<T> *pCurrentNode = _Header;
    if (index == 0)
    {
        _Header = pCurrentNode->getNext();
        delete pCurrentNode;
    }
    else
    {
        for (int i = 1; i < index; i++)
            pCurrentNode = pCurrentNode->getNext();
        Node<T> *pRemoveNode = pCurrentNode->getNext();
        pCurrentNode->setNext(pRemoveNode->getNext());
        delete pRemoveNode;
    }
    _Current--;
    return;
}

template <typename T>
void LinkedList<T>::Destruct(void)
{
    while (_Header != nullptr && _Current > 0)
        Remove();
}