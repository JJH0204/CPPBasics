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

/* 이 함수는 왜? 헤더파일에 코드를 작성해야 작동하는 걸까?
- 템플릿 함수는 필요한 곳에서 인스턴스화할 수 있도록 헤더 파일에 정의되어야 합니다.
- 이렇게 하면 가시성이 보장되고 ODR(하나의 정의 규칙)을 준수할 수 있어 코드가 올바르게 컴파일되고 링크될 수 있습니다.*/

/* 객체 생성 및 사용 예제 */
void ex_class(void);