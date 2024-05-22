#pragma once

/* 데이터 저장 노드 정의 */
class Node
{
private:
    void *_data;  /* 저장하는 데이터 주소값 */
    Node *_pNext; /* 다음 연결된 노드 가리키는 포인터 */
public:
    Node(void);
    Node(void *data, Node *pNext = nullptr);

    void set_data(void *data);
    template <typename T>
    T get_data(void);

    void set_next(Node *pNext);
    Node *get_next(void);
};

template <typename T>
T Node::get_data(void)
{
    return *static_cast<T *>(_data);
}
/* 이 함수는 왜? 헤더파일에 코드를 작성해야 작동하는 걸까?
- 템플릿 함수는 필요한 곳에서 인스턴스화할 수 있도록 헤더 파일에 정의되어야 합니다. 이렇게 하면 가시성이 보장되고 ODR(하나의 정의 규칙)을 준수할 수 있어 코드가 올바르게 컴파일되고 링크될 수 있습니다.*/

/* 연결 리스트 클래스 */
class LinkedList /* class 키워드를 활용해 정의 */
{
private:           /* 접근 제어 키워드: 외부에서 접근 불가능 */
    Node *_header; /* 리스트 시작 데이터 */
    size_t _type;  /* 저장된 데이터의 타입 */
    int _Current;  /* 연결 리스트 요소 개수 */
public:            /* 접근 제어 키워드: 외부에서 접근 가능 */
    Node *get_header(void);
    int get_Current(void);

    void PrintT(void); /* 테이블 형식으로 리스트 출력 */
};