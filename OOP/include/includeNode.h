#pragma once

/* 데이터 저장 노드 정의 */
template <typename T>
class Node
{
private:
    T _data;      /* 저장하는 데이터 주소값 */
    Node *_pNext; /* 다음 연결된 노드 가리키는 포인터 */
public:
    /* 디폴트 생성자 */
    Node(void);
    /* 일반 생성자 */
    Node(const T data, Node *pNext = nullptr);
    /* 복사 생성자 */
    Node(const Node &node);

    /* 소멸자 */
    ~Node(void);

    /* _data 값 수정 */
    void set_data(const T data);
    /* _data 값 반환 */
    T get_data(void);

    /* _pNext 값 수정 */
    void set_next(Node *pNext);
    /* _pNext 값 반환 */
    Node *get_next(void);
};

template <typename T>
Node<T>::Node(void) : _data(T()), _pNext(nullptr) {}

template <typename T>
Node<T>::Node(const T data, Node *pNext) : _data(data), _pNext(pNext) {}

template <typename T>
Node<T>::Node(const Node &node) : _data(node._data), _pNext(node._pNext) {}

template <typename T>
Node<T>::~Node(void) {}

template <typename T>
void Node<T>::set_data(const T data)
{
    _data = data;
}

template <typename T>
T Node<T>::get_data(void)
{
    if (_data)
        return _data;
    else
        throw std::runtime_error("_data is nullptr");
    // return nullptr;
}

template <typename T>
void Node<T>::set_next(Node *pNext)
{
    _pNext = pNext;
}

template <typename T>
Node<T> *Node<T>::get_next(void)
{
    return _pNext;
}

/* 객체 생성 및 사용 예제 */
void ex_class(void);