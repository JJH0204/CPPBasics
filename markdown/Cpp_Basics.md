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

| 자료형               | 설명                                                          | 크기 (대략)          |
| -------------------- | ------------------------------------------------------------- | -------------------- |
| `bool`               | 논리형 자료형으로 참(true) 또는 거짓(false) 값을 가짐         | 1 byte               |
| `char`               | 문자형 자료형으로 단일 문자를 저장                            | 1 byte               |
| `wchar_t`            | 와이드 문자형 자료형으로 더 큰 문자 집합을 저장 (유니코드 등) | 2 또는 4 bytes       |
| `char16_t`           | UTF-16 문자형 자료형                                          | 2 bytes              |
| `char32_t`           | UTF-32 문자형 자료형                                          | 4 bytes              |
| `short`              | 짧은 정수형 자료형                                            | 2 bytes              |
| `int`                | 정수형 자료형                                                 | 4 bytes              |
| `long`               | 긴 정수형 자료형                                              | 4 또는 8 bytes       |
| `long long`          | 더 긴 정수형 자료형                                           | 8 bytes              |
| `unsigned`           | 부호 없는 정수형 자료형 (`unsigned int`와 동일)               | 4 bytes              |
| `unsigned short`     | 부호 없는 짧은 정수형 자료형                                  | 2 bytes              |
| `unsigned long`      | 부호 없는 긴 정수형 자료형                                    | 4 또는 8 bytes       |
| `unsigned long long` | 부호 없는 더 긴 정수형 자료형                                 | 8 bytes              |
| `float`              | 단정밀도 부동소수점형 자료형 (소수점 이하 숫자 포함)          | 4 bytes              |
| `double`             | 배정밀도 부동소수점형 자료형 (더 큰 소수점 이하 숫자 포함)    | 8 bytes              |
| `long double`        | 확장 정밀도 부동소수점형 자료형                               | 8, 12, 또는 16 bytes |
| `void`               | 자료형이 없음을 나타내며 함수의 반환형으로 주로 사용          | 0 bytes              |
| `nullptr_t`          | C++11에서 도입된 자료형으로, null 포인터를 나타내기 위해 사용 | 구현에 따라 다름     |

- 이 표는 C++에서 사용되는 기본 자료형들을 설명하며, 각 자료형의 대략적인 크기를 제공합니다.
- 크기는 컴파일러와 시스템 아키텍처에 따라 달라질 수 있습니다.

## 2.1. C++의 변수 특징

- 동일한 이름의 변수를 허용하는 경우도 있다.<br/>(네임스페이스 또는 범위(Scope)라는 개념을 통해 해결 가능, 단 권장하지 않음)
- 실수 표현에서 뒤에 f를 붙이지 않으면 'double'형 데이터라 자동으로 인식한다.
- wchar_t는 문자열을 표현할 수 있지만 가능한 특별한 상황이 아니라면 char을 사용하자
- 개발환경에 따라 char의 형태가 'signed'와 'unsigned'로 달라질 수 있다.
-

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

## 2.3. 이스케이프 문자열(시퀀스)

| 이스케이프 시퀀스 | 설명                             |
| ----------------- | -------------------------------- |
| `\n`              | 새 줄 (Line feed)                |
| `\r`              | 캐리지 리턴 (Carriage return)    |
| `\t`              | 수평 탭 (Horizontal tab)         |
| `\v`              | 수직 탭 (Vertical tab)           |
| `\b`              | 백스페이스 (Backspace)           |
| `\f`              | 폼 피드 (Form feed)              |
| `\a`              | 경고음 (Alarm or bell)           |
| `\\`              | 백슬래시 (`\`) 자체              |
| `\'`              | 작은 따옴표 (`'`)                |
| `\"`              | 큰 따옴표 (`"`)                  |
| `\?`              | 물음표 (`?`) 자체                |
| `\0`              | 널 문자 (Null character, `\x00`) |
| `\xhh`            | 16진수 ASCII 문자 코드           |
| `\ooo`            | 8진수 ASCII 문자 코드            |

## 2.4. 형 변환

- C++에서 형변환은 여러 가지 방식으로 이루어질 수 있으며, 각각의 방식은 특정 상황에 적합합니다.
- C++의 형변환은 크게 두 가지로 나뉩니다: <br/>암시적 형변환(implicit type conversion)과 명시적 형변환(explicit type conversion).
- 명시적 형변환은 다시 C 스타일 형변환(C-style cast)과 C++ 스타일 형변환(C++ style cast)으로 나뉩니다.

### 2.4.1. 암시적 형변환 (Implicit Type Conversion)

- 컴파일러가 자동으로 수행하는 형변환입니다.
- 주로 기본 데이터 타입 간의 형변환에서 많이 발생합니다.

```cpp
int a = 10;
double b = a;  // int에서 double로 암시적 형변환
```

- 작은 범위의 타입에서 큰 범위의 타입으로 변환 (예: int에서 double로)
- 상수 표현식을 더 큰 타입의 변수에 대입 (예: char에서 int로)
- 위 조건은 아래 명시적 형변환에서도 유지된다.

### 2.4.2. 명시적 형변환 (Explicit Type Conversion)

- 프로그래머가 직접 형변환을 지정하는 방식입니다.
- 명시적 형변환에는 C 스타일 형변환과 C++ 스타일 형변환이 있습니다.

1. C 스타일 형변환 (C-Style Cast)

- C에서 사용하던 형변환 방식으로, C++에서도 사용할 수 있습니다.
- 문법은 (new_type)expression입니다.

```cpp
int a = 10;
double b = (double)a;  // C 스타일 형변환
```

2. C++ 스타일 형변환 (C++ Style Cast)

- C++에서는 보다 안전하고 명확한 형변환을 위해 네 가지의 형변환 연산자를 제공합니다.
- static_cast

  - 주로 기본 데이터 타입 간의 형변환이나 포인터 타입 간의 형변환에 사용됩니다.
  - 안전성을 보장하지 않지만, 컴파일 타임에 많은 오류를 잡아줍니다.

  ```cpp
    int a = 10;
    double b = static_cast<double>(a);
  ```

- dynamic_cast

  - 주로 다형성(pointers to base class)의 객체에 사용되며, 런타임에 타입을 체크합니다.
  - 실패하면 nullptr을 반환합니다.

  ```cpp
    class Base { virtual void foo() {} };
    class Derived : public Base {};
    Base* basePtr = new Derived;
    Derived* derivedPtr = dynamic_cast<Derived\*>(basePtr);
  ```

- const_cast

  - const 또는 volatile 속성을 추가하거나 제거할 때 사용됩니다.
  - 객체의 원래 타입을 변경하지 않습니다.

  ```cpp
    const int a = 10;
    int* b = const_cast<int*>(&a);
  ```

- reinterpret_cast
  - 주로 포인터 타입 간의 형변환에 사용되며, 비트 단위로 객체를 재해석합니다.
  - 매우 위험하며, 사용을 최소화해야 합니다.
  ```cpp
    int a = 10;
    int* ptr = &a;
    char* charPtr = reinterpret_cast<char*>(ptr);
  ```

### 2.4.3. 정리

- 형변환을 사용할 때는 항상 해당 형변환이 필요한지, 그리고 안전한지 고려해야 합니다.
- 암시적 형변환은 편리하지만, 예상치 못한 결과를 초래할 수 있기 때문에 주의가 필요합니다.<br/>(가능한 명시적인 방법으로 형변환 시도)
- 명시적인 방법 중에서도 dynamic_cast, const_cast, reinterpret_cast는 코드를 작성한 프로그래머의 의도와 다른 문제를 만들 수 있기에 주의해서 사용해야 한다.

## 2.5. 2진수 출력

- bitset 라이브러리 추가, (#include <bitset>)
- "bitset<출력하는 비트 수>(변수)" 방식으로 사용
- [예제코드](../project_Basics/source/includeBasics.cpp#L105)

# 3. 구조체 선언 응용

- c 에서도 가능해 보이긴 하나, 특이해서 기록하는 구조체 선언의 응용 방식
- [예제코드](../project_Basics/source/includeBasics.cpp#L119)

# 4. 빅 엔디안(Big-Endian)과 리틀 엔디안(Little-Endian)

- 컴퓨터 시스템에서 데이터를 메모리에 저장하거나 전송할 때 바이트 순서를 지정하는 두 가지 주요 방식입니다.
- 엔디안 방식은 특히 다중 바이트 데이터 타입(예: int, float)을 처리할 때 중요한 역할을 합니다.
- 빅 엔디안과 리틀 엔디안은 데이터의 메모리 저장 방식에 관한 중요한 개념입니다.
- 시스템이나 애플리케이션의 요구사항에 따라 적절한 엔디안 방식을 사용해야 하며, 특히 서로 다른 시스템 간의 데이터 전송이나 저장 시에는 엔디안 변환을 고려해야 합니다.
- 엔디안 방식의 차이는 시스템의 데이터 처리 효율성과 호환성에 큰 영향을 미칠 수 있습니다.
- 다음은 빅 엔디안과 리틀 엔디안의 차이점과 그 세부 사항입니다.

## 4.1. 빅 엔디안

- 가장 중요한 바이트(Most Significant Byte, MSB)를 메모리의 가장 낮은 주소에 저장합니다.
- 즉, 데이터의 가장 큰 부분이 메모리의 앞쪽에 위치합니다.
- 32비트 정수 0x12345678을 빅 엔디안 방식으로 저장하는 경우:
  ```
  메모리 주소:   0x00  0x01  0x02  0x03
  저장된 데이터:  12    34    56    78
  ```
- 네트워크 프로토콜 및 인터넷 표준에서 많이 사용됩니다. (예: TCP/IP)
- 네트워크 프로토콜의 경우를 “네트워크 바이트 오더(Network Byte Order)“라고도 합니다.<br/>호스트 시스템의 바이트 오더가 리틀 엔디안일 경우 네트워크 전송 전에 바이트 오더를 변환해야 합니다.
- 사람의 읽는 방식(왼쪽에서 오른쪽)과 비슷하여 직관적입니다.

## 4.2. 리틀 엔디안

- 가장 중요한 바이트(Most Significant Byte, MSB)를 메모리의 가장 높은 주소에 저장합니다.
- 즉, 데이터의 가장 작은 부분이 메모리의 앞쪽에 위치합니다.
- 32비트 정수 0x12345678을 리틀 엔디안 방식으로 저장하는 경우:
  ```
  메모리 주소:   0x00  0x01  0x02  0x03
  저장된 데이터:  78    56    34    12
  ```
- 인텔 x86 및 x86-64 아키텍처와 같은 많은 CPU 아키텍처에서 사용됩니다.
- 다중 바이트 읽기와 쓰기를 효율적으로 처리할 수 있습니다.

## 4.3. 예제코드

- C++에서 빅 엔디안과 리틀 엔디안을 확인하는 코드입니다.
- [예제코드](../project_Basics/source/includeBasics.cpp#L134)

# 5. 포인터와 const

- 포인터가 가리키는 메모리에 저장된 데이터를 수정하지 못하도록 하는 방법

```cpp
int iNumber = 10;
const int *p = &iNumber;
*p = 30; // 수정 불가능
```

- 포인터가 가리키는 메모리를 바꾸지 못하도록 하는 방법

```cpp
int iNum_1 = 10;
int iNum_2 = 20;
int *const p = &iNum_1;

p = &iNum_2;    // 수정 불가능
*p = 30         // 수정 가능
```

- 위 두 예제를 한번에 사용할 수 도 있다.

```cpp
int iNum_1 = 10;
int iNum_2 = 20;
const int *const p = &iNum_1;

p = &iNum_2;    // 수정 불가능
*p = 30         // 수정 불가능
```

# 6. 레퍼런스 변수

- 기존에 메모리에 할당된 변수에 접근할 수 있는 새로운 변수명을 설정하는 것
- 포인터와 동일한 동작을 수행하지만, 사용에 주의해야 한다.<br/>운영체제마다 동작이 달라질 수 있다.
- [예제코드](../project_Basics/source/includeBasics.cpp#L170)
- 주의!: 레퍼런스 변수는 반드시 초기화한 후 사용해야 한다.
- const 선언을 통해 변수의 안전성을 확보할 수 있다.<br/>const 속성을 가진 레퍼런스만 임시 변수로 생성한 상수를 참조할 수 있게 허용, 함수 호출 등으로 인한 기존 데이터의 변조를 막을 수 있다.

## 6.1. 레퍼런스를 함수의 매개변수로

- 포인터를 대체해 보다 안전한 방법으로 메모리에 접근할 수 있는 방법으로 사용하면 좋다.
- 포인터를 매개변수로 했을 때 단점을 해결할 수 있기 때문이다.<br/>포인터가 매개변수일 때 함수에서 'NULL' 값인지 확인하는 코드가 필수가 된다.
- 레퍼런스를 포인터의 대체제로 사용할 경우 'NULL' 값을 사전에 차단(프로그램 실행 전 오류가 검출)되기에 매우 안전하다.

# 7. CRT

- c의 표준라이브러리 처럼 c++과 함께 제공되는 라이브러리를 지칭
- [예제코드](../project_Basics/source/includeBasics.cpp#L204)

# 8. 함수 오버로딩(Overloading)

- 여러 함수들이 동일한 이름을 사용할 수 있는 기능

```cpp
int max(int a, int b);
float max(float a, float b);
```

- 위 두 함수는 같은 이름이지만 인자가 달라 구별된다.
- 함수의 인자 부분을 '함수의 시그니처'라고 부른다.
- 시그니처가 다르면 서로 다른 함수로 구분된다.
- [예제코드](../project_Basics/source/includeBasics.cpp#L215)
- 반환값으로는 함수를 구분할 수 없다.
- 레퍼런스로 시그니처를 구분할 수 없다.
- 인자 값을 전달할 때 데이터 타입을 명시적으로 선언하면 원하는 함수를 실행하기 훨 수월해진다.

## 8.1. 오버로딩 규칙

- 변수 자료형을 명시하지 않아도 컴퓨터가 나름의 규칙을 갖고 우선순위가 가장 높은 함수를 호출한다.
- 정확하게 일치하는 경우 > 승진에 의한 형변환 > 표준 형변환 > 사용자에 의한 형변환

## 8.2. 명칭 장식

- 내부적으로 오버로딩을 다루는 방법으로 원 함수이름 그대로 저장하지 않고 별도의 식별 가능한 데이터를 남기는 것을 의미

```cpp
void WhichOne(char c);      // ?WhichOne@@YAXH@Z
void WhichOne(double c);    // ?WhichOne@@YAXN@Z , 뒤 세번째 문자가 다름
```

# 9. 함수의 디폴트 인자(Default Arguments)

- 따로 값을 지정하지 않은 경우 선택하는 인자의 값을 정의 할 수 있다.
- [예제코드](../project_Basics/source/includeBasics.cpp#L245), [헤더파일](../project_Basics/include/includeBasics.h#15)
- 예제에서 볼 수 있듯 디폴트 인자 정의는 함수의 선언에만 추가할 수 있다. (헤더파일에 디폴트 인자 정의된 이유)
- 디폴트 인자 정의는 함수의 인자들 중에서 오른쪽에서 왼쪽으로 순차적으로 진행된다.
- 중간에 디폴트 인자가 비거나 건너뛰는 것은 불가능하다.

```cpp
/* 잘못된 디폴트 인자 정의 */
void DefaultArg(int a = 1, int b = 2, int c);
void DefaultArg(int a = 1, int b, int c = 3);
void DefaultArg(int a = 1, int b, int c);
```

- 함수를 호출할 때 전달하는 인자는 매개 변수의 좌측부터 순차로 적용된다.

```cpp
void DefaultArg(int a = 1, int b = 2, int c = 3);

DefaultArg(100, 200); // -> DefaultArg(100, 200, 3);
```

## 9.1. 오버로딩과 디폴트 인자의 충돌

```cpp
void DefaultArg(int a, int b = 100);
void DefaultArg(int a);

DefaultArg(100); // <- C++에서는 이러한 함수 사용을 허용하지 않다.
```

# 10. typedef를 사용한 함수 포인터 정의

```cpp
int (*Func1)(int, int);
int (*Func2)(int, int);
```

- 위 코드와 아래 코드는 같은 기능을 수행한다.

```cpp
typedef int (*FN_TYPE)(int, int);

FN_TYPE Func1;
FN_TYPE Func2;
```

# 11. 동적할당

```cpp
int *pA = new int [1];          // int 형 변수 1개를 동적으로 할당
/* int *pA = new int; 와 같다. */
int *pArray_10 = new int [10];  // int형 배열 (배열의 요소가 10개인) 동적 할당

/* 동적으로 할당한 메모리를 해제합니다. */
delete[] pA;        // delete pA; 와 같다.
delete[] pArray;    // 할당 크기를 알려주지 않아도 됨
```

- new, delete 는 한개의 변수만 / new[], delete[]는 다수의 변수를 동적할당 가능
- new와 delete, new[]와 delete[]는 짝을 맞춰서 사용해야 한다.
- 해제한 메모리를 해제 할 수 없다. (c와 동일)<br/>혹시 모를 상황을 대비해 해제 후 NULL값으로 대입하는 것이 좋다.

# 12. C 스타일과 C++스타일 문자열

- 기존의 문자열(C 스타일)에서 객체지향적으로 사용할 수 있도록 개선한 방법을 C++ 스타일이라 한다.
- cout 객체는 전달 받은 인자에서 '\0'가 나올 때까지 콘솔에 출력하는 기능을 수행한다.
- 문자열이 아닌 문자를 전달하게 될 경우 에러가 발생하게 된다.

## 12.1. string

- basic_string이라는 클래스를 typedef를 사용해 재정의한 타입
- C++에서 문자열을 쉽게 다룰 수 있게 해주는 클래스
- string 해더파일을 포함해야 사용이 가능하다.(#include <string>)
- [예제코드](../project_Basics/source/includeBasics.cpp#L253)

# 13. 서로 다른 파일에 선언된 동일한 이름의 구조체(변수, 클래스 등등) 사용
- 선언을 허용하지만 그 구조체들이 서로 다른 내용을 가지고 있을 경우 컴파일 시 문제를 일으킬 수 있습니다.
- 특히 동일한 이름의 구조체가 포함된 헤더 파일이 여러 소스 파일에서 포함되는 경우, 컴파일러는 이러한 구조체들이 같은 것으로 간주하고 충돌을 일으킬 수 있습니다.

# 13.1. 네임스페이스
- 네임스페이스를 통해 두 구조체를 구분할 수 있다.
- 네임스페이스 선언 방법
```cpp
// File1.h
#ifndef FILE1_H
#define FILE1_H

namespace File1Namespace {
    struct MyStruct {
        int a;
        float b;
    };
}

#endif // FILE1_H

// File2.h
#ifndef FILE2_H
#define FILE2_H

namespace File2Namespace {
    struct MyStruct {
        double c;
        char d;
    };
}

#endif // FILE2_H
```
- 원하는 소스 파일에서 네임스페이스를 사용한 호출
```cpp
// main.cpp
#include <iostream>
#include "File1.h"
#include "File2.h"

int main() {
    File1Namespace::MyStruct struct1;
    struct1.a = 10;
    struct1.b = 20.5f;

    File2Namespace::MyStruct struct2;
    struct2.c = 30.5;
    struct2.d = 'A';

    std::cout << "struct1: " << struct1.a << ", " << struct1.b << std::endl;
    std::cout << "struct2: " << struct2.c << ", " << struct2.d << std::endl;

    return 0;
}
```
# 13.2. 매크로 선언을 통한 해더 가드
- [예제코드](../project_Basics/include/includeBasics.h#L1)
- 매크로를 사용해 동일한 구조체가 서로다른 파일에 포함되어 에러를 발생시키는 것을 방지할 수 있다. (c 도 가능)

# 13.3. #pragma once 선언
- cpp에서 지원하는 헤더 파일 중복 포함을 방지할 또 다른 방법
- 헤더 가드와 같이 헤더 파일의 중복 포함을 방지 한다.
```cpp
// MyHeader.h
#pragma once

class MyClass {
public:
    void doSomething();
};
```

# 14. void *와 템플릿(template)
- C++의 템플릿(template)은 제네릭 프로그래밍을 지원하는 강력한 기능입니다.
- 템플릿을 사용하면 데이터 타입에 의존하지 않는 코드를 작성할 수 있어 코드 재사용성을 높이고 중복을 줄일 수 있습니다.
- 템플릿에는 함수 템플릿과 클래스 템플릿 두 가지 주요 유형이 있습니다.

# 14.1. 함수 템플릿
- 함수 템플릿은 다양한 데이터 타입을 처리할 수 있는 일반화된 함수를 정의하는 데 사용됩니다.
- 예를 들어, 두 값을 비교하는 함수를 다음과 같이 정의할 수 있습니다:
```cpp
#include <iostream>

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << getMax(10, 20) << std::endl; // 정수 비교
    std::cout << getMax(10.5, 20.5) << std::endl; // 실수 비교
    std::cout << getMax('a', 'z') << std::endl; // 문자 비교
    return 0;
}
```
- 위의 예제에서 getMax 함수는 T라는 템플릿 타입을 사용하여 정의되었습니다. 
- 이 함수는 두 값을 비교하여 큰 값을 반환합니다. 
- 함수가 호출될 때 컴파일러는 제공된 인수의 타입에 맞게 getMax 함수를 인스턴스화합니다.

## 14.2. 클래스 템플릿
- 클래스 템플릿은 다양한 데이터 타입을 처리할 수 있는 일반화된 클래스를 정의하는 데 사용됩니다. 
- 예를 들어, 간단한 스택 클래스를 다음과 같이 정의할 수 있습니다:
```cpp
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(T const& elem) {
        elements.push_back(elem);
    }

    void pop() {
        if (elements.empty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return;
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            std::cerr << "Stack is empty!" << std::endl;
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack; // int 타입을 사용하는 스택
    intStack.push(1);
    intStack.push(2);
    std::cout << "Top element: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Top element: " << intStack.top() << std::endl;

    Stack<std::string> stringStack; // std::string 타입을 사용하는 스택
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Top element: " << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << "Top element: " << stringStack.top() << std::endl;

    return 0;
}
```
- 위의 예제에서 Stack 클래스는 T라는 템플릿 타입을 사용하여 정의되었습니다. 
- 이 클래스는 템플릿 타입 T를 사용하여 요소를 저장하고 관리합니다. 
- intStack과 stringStack은 각각 int와 std::string 타입의 스택을 인스턴스화한 예입니다.

## 14.3. 템플릿의 장점
1.	재사용성: 템플릿을 사용하면 다양한 데이터 타입을 처리할 수 있는 범용 코드를 작성할 수 있어 코드 재사용성이 높아집니다.
2.	타입 안전성: 템플릿을 사용하면 컴파일 타임에 타입 검사가 이루어져 타입 안전성이 향상됩니다.
3.	유연성: 템플릿을 사용하면 함수나 클래스가 다양한 데이터 타입을 처리할 수 있어 유연한 코드를 작성할 수 있습니다.

## 14.4. 템플릿의 단점

1.	컴파일 시간 증가: 템플릿은 컴파일 타임에 인스턴스화되므로 컴파일 시간이 증가할 수 있습니다.
2.	디버깅의 복잡성: 템플릿 코드의 디버깅은 일반 코드보다 복잡할 수 있습니다.
3.	코드 복잡성: 템플릿을 사용하는 코드는 초기에는 이해하기 어려울 수 있습니다.

## 14.5. 결론 
템플릿은 C++의 강력한 기능 중 하나로, 잘 활용하면 코드의 재사용성과 유연성을 크게 향상시킬 수 있습니다.