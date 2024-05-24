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
    Node(void) : _data(T()), _pNext(nullptr) {}
    /* 일반 생성자 */
    Node(const T data, Node *pNext = nullptr) : _data(data), _pNext(pNext) {}
    /* 복사 생성자 */
    Node(const Node &node) : _data(node._data), _pNext(node._pNext) {}
    /* 소멸자 */
    ~Node(void) {}

    /* _data 값 수정 */
    void setData(const T data) { _data = data; }
    /* _data 값 반환 */
    T getData(void) { return _data; }

    /* _pNext 값 수정 */
    void setNext(Node *pNext) { _pNext = pNext; }
    /* _pNext 값 반환 */
    Node *getNext(void) { return _pNext; }
};

/* 객체 생성 및 사용 예제 */
void ex_class(void);