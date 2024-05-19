#include <iostream>
#include "includeBasics.h"
using namespace std;
/* 네임스페이스 std를 명시적으로 선언,
이후 사용하는 cout객체를 네임스페이스 선언없이 호출할 수 있다. */

/* --- Cpp 기본 : Hello World --- */
void ex_HelloWorld(void)
{
    // using namespace std;
    cout << "Hello World" << endl;
    // endl <- 줄 바꿈 의미( == '\n')

    return; /* 함수 종료 */
}

#define swap(size, a, b) \
    do                   \
    {                    \
        size temp = a;   \
        a = b;           \
        b = temp;        \
    } while (0)

/* --- Cpp 기본 : 변수 --- */
void ex_Variable(void)
{
    /* 정수형 변수 3개 선언, 각 변수에 100, 200, 300 저장 */
    int a = 100, b = 200, c = 300;

    /* cout을 이용해 변수에 저장한 값 출력 */
    cout << a << b << c << endl;

    swap(int, a, b);

    cout << a << b << c << endl;

    swap(int, a, c);

    cout << a << b << c << endl;

    return;
}