#pragma once
#include "includeNode.h"

/* 연결 리스트 클래스 */
template <typename T>
class LinkedList /* class 키워드를 활용해 정의 */
{
private:           /* 접근 제어 키워드: 외부에서 접근 불가능 */
    Node<T> *_header; /* 리스트 시작 데이터 */
    int _Current;  /* 연결 리스트 요소 개수 */
public:            /* 접근 제어 키워드: 외부에서 접근 가능 */
    Node<T> *get_header(void);
    int get_Current(void);

    void PrintT(void); /* 테이블 형식으로 리스트 출력 */
};