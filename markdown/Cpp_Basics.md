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
## 2.1. C++의 변수 특징
- 동일한 이름의 변수를 허용하는 경우도 있다.<br/>(네임스페이스 또는 범위(Scope)라는 개념을 통해 해결 가능, 단 권장하지 않음)
## 2.2. 헝가리안 표기법
- 헝가리안 표기법(Hungarian notation)은 변수 이름에 특정 접두어를 붙여 변수의 데이터 타입이나 목적을 명시하는 코딩 스타일입니다.
- 헝가리안 표기법은 크게 두 가지 종류로 나눌 수 있습니다: <br/>시스템 헝가리안 표기법(Systems Hungarian notation)과 애플리케이션 헝가리안 표기법(Apps Hungarian notation).

### 2.2.1. 시스템 헝가리안 표기법
- 시스템 헝가리안 표기법은 변수의 데이터 타입을 나타내는 접두어를 사용합니다.
- 예를 들어, 변수의 타입이 정수(integer)일 경우 i, 문자열(string)일 경우 str, 부동소수점(float)일 경우 f 등의 접두어를 붙입니다.
```c
int iCount: 정수를 나타내는 변수
char cLetter: 문자를 나타내는 변수
float fPrice: 부동소수점을 나타내는 변수
string strName: 문자열을 나타내는 변수
```
- 이 방식의 장점은 코드를 읽는 사람이 변수의 타입을 쉽게 파악할 수 있다는 점입니다.
- 현대의 많은 IDE(통합 개발 환경)들이 변수 타입을 쉽게 확인할 수 있는 기능을 제공하기 때문에, 이 표기법은 점차 덜 사용되고 있습니다.

### 2.2.2. 애플리케이션 헝가리안 표기법
- 애플리케이션 헝가리안 표기법은 변수의 데이터 타입 대신 그 변수의 목적이나 역할을 나타내는 접두어를 사용합니다.
- 이 방법은 변수의 의미를 더 명확하게 이해하는 데 도움을 줍니다.
```c
rwWidth: 읽기/쓰기 가능의 너비(Read/Write Width)
usUserCount: 사용자 수(User Count)
bIsVisible: 논리값 변수로서 보이는지 여부(Boolean Is Visible)
```
- 이 표기법의 장점은 변수의 용도를 쉽게 파악할 수 있다는 것입니다.
- 따라서, 코드의 가독성이 높아지고 유지보수가 용이해집니다.

#### 애플리케이션 헝가리안 표기법 사용 예시
```c
int iTotal = 0;
float fAverage = 0.0;
string strUserName = "John Doe";
bool bIsLoggedIn = false;

// 함수 사용 예시
void UpdateUserScore(int iScore) {
    // 함수 내부 로직
}
```
### 2.2.3. 정리
- 헝가리안 표기법은 코드를 더 명확하고 이해하기 쉽게 만들기 위한 방법으로, 변수의 타입이나 목적을 변수명에 포함시켜 사용하는 표기법입니다.
- 시스템 헝가리안 표기법은 변수의 데이터 타입을 나타내고, 애플리케이션 헝가리안 표기법은 변수의 역할이나 목적을 나타냅니다.
- 이 표기법은 특히 큰 규모의 프로젝트에서 코드의 가독성과 유지보수성을 향상시키는 데 유용할 수 있습니다.







