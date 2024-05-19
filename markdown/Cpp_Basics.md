# 1. Hello World 출력
- [소스코드](../project_Basics/source/includeBasics.cpp#L1)
```cpp
#include <iostream>
/* C++ 표준 라이브러리 포함 선언 */
#include "includeBasics.h"
using namespace std;
/* 네임스페이스 std를 명시적으로 선언,
이후 사용하는 cout객체를 네임스페이스 선언없이 호출할 수 있다. */

/* --- Cpp 기본 : Hello World --- */
void ex_HelloWorld(void)
{
    // using namespace std;
    cout << "Hello World" << endl;
    // endl <- 줄 바꿈 의미
}
```
@ 앞으로 C언어와 같은 설명은 제외하고 Cpp만의 기억할 특징들을 서술할 예정이다.

# 2. 변수
| 자료형                 | 설명                                                                           | 크기 (대략)            |
|------------------------|--------------------------------------------------------------------------------|------------------------|
| `bool`                 | 논리형 자료형으로 참(true) 또는 거짓(false) 값을 가짐                           | 1 byte                 |
| `char`                 | 문자형 자료형으로 단일 문자를 저장                                              | 1 byte                 |
| `wchar_t`              | 와이드 문자형 자료형으로 더 큰 문자 집합을 저장 (유니코드 등)                   | 2 또는 4 bytes         |
| `char16_t`             | UTF-16 문자형 자료형                                                            | 2 bytes                |
| `char32_t`             | UTF-32 문자형 자료형                                                            | 4 bytes                |
| `short`                | 짧은 정수형 자료형                                                              | 2 bytes                |
| `int`                  | 정수형 자료형                                                                   | 4 bytes                |
| `long`                 | 긴 정수형 자료형                                                                | 4 또는 8 bytes         |
| `long long`            | 더 긴 정수형 자료형                                                             | 8 bytes                |
| `unsigned`             | 부호 없는 정수형 자료형 (`unsigned int`와 동일)                                 | 4 bytes                |
| `unsigned short`       | 부호 없는 짧은 정수형 자료형                                                    | 2 bytes                |
| `unsigned long`        | 부호 없는 긴 정수형 자료형                                                      | 4 또는 8 bytes         |
| `unsigned long long`   | 부호 없는 더 긴 정수형 자료형                                                   | 8 bytes                |
| `float`                | 단정밀도 부동소수점형 자료형 (소수점 이하 숫자 포함)                             | 4 bytes                |
| `double`               | 배정밀도 부동소수점형 자료형 (더 큰 소수점 이하 숫자 포함)                       | 8 bytes                |
| `long double`          | 확장 정밀도 부동소수점형 자료형                                                 | 8, 12, 또는 16 bytes   |
| `void`                 | 자료형이 없음을 나타내며 함수의 반환형으로 주로 사용                             | 0 bytes                |
| `nullptr_t`            | C++11에서 도입된 자료형으로, null 포인터를 나타내기 위해 사용                    | 구현에 따라 다름       |
- 이 표는 C++에서 사용되는 기본 자료형들을 설명하며, 각 자료형의 대략적인 크기를 제공합니다.
- 크기는 컴파일러와 시스템 아키텍처에 따라 달라질 수 있습니다.