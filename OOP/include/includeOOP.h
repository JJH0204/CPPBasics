#pragma once
#include "includeNode.h"

/* 연결 리스트 클래스 */
template <typename T>
class LinkedList /* class 키워드를 활용해 정의 */
{
private:              /* 접근 제어 키워드: 외부에서 접근 불가능 */
    Node<T> *_Header; /* 리스트 시작 데이터 */
    int _Current;     /* 연결 리스트 요소 개수 */
public:               /* 접근 제어 키워드: 외부에서 접근 가능 */
    LinkedList(void) : _Header(nullptr), _Current(0) {}
    Node<T> *get_Header(void);
    int get_Current(void);

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
Node<T> *LinkedList<T>::get_Header(void)
{
    return _Header;
}

template <typename T>
int LinkedList<T>::get_Current(void)
{
    return _Current;
}

template <typename T>
void LinkedList<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;
    int nLoop = 0;

    if ((pCurNode = get_Header()) == nullptr)
        return;

    std::cout << "|index\t|data\t|" << std::endl;

    for (; (nLoop < get_Current()) && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|" << pCurNode->get_data() << "\t|" << std::endl;
        pCurNode = pCurNode->get_next();
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
            newNode->set_next(_Header);
            _Header = newNode;
        }
        else if (index >= get_Current())
        { /* 리스트의 가장 마지막에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            while (currentNode->get_next() != nullptr)
                currentNode = currentNode->get_next();
            currentNode->set_next(newNode);
            newNode->set_next(nullptr);
        }
        else
        { /* 원하는 위치 index에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            for (int i = 0; i < index - 1 && currentNode != nullptr; i++)
                currentNode = currentNode->get_next();
            if (currentNode != nullptr)
            {
                newNode->set_next(currentNode->get_next());
                currentNode->set_next(newNode);
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
        newNode->set_data(data);
        if (_Header == nullptr || index <= 0)
        { /* 리스트의 가장 처음에 데이터 넣기 */
            newNode->set_next(_Header);
            _Header = newNode;
        }
        else if (index >= get_Current())
        { /* 리스트의 가장 마지막에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            while (currentNode->get_next() != nullptr)
                currentNode = currentNode->get_next();
            currentNode->set_next(newNode);
            newNode->set_next(nullptr);
        }
        else
        { /* 원하는 위치 index에 데이터 넣기 */
            Node<T> *currentNode = _Header;
            for (int i = 0; i < index - 1 && currentNode != nullptr; i++)
                currentNode = currentNode->get_next();
            if (currentNode != nullptr)
            {
                newNode->set_next(currentNode->get_next());
                currentNode->set_next(newNode);
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
        _Header = pCurrentNode->get_next();
        delete pCurrentNode;
    }
    else
    {
        for (int i = 1; i < index; i++)
            pCurrentNode = pCurrentNode->get_next();
        Node<T> *pRemoveNode = pCurrentNode->get_next();
        pCurrentNode->set_next(pRemoveNode->get_next());
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