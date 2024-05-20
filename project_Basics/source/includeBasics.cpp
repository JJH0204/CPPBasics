#include <iostream>
#include <string>
#include <cstring>
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

/* --- 데이터 타입 할당 크기 출력 */
#define PrintDataSize(DataType)                                            \
    do                                                                     \
    {                                                                      \
        cout << #DataType << " : " << sizeof(DataType) << " byte" << endl; \
    } while (0)
/* DataType이 문자열로 인식되지 않음:
- 매크로 인수로 전달된 DataType은 문자열이 아니기 때문에, DataType 자체를 출력하려고 하면 오류가 발생합니다.
- # 연산자를 사용하여 매크로 인수를 문자열로 변환해야 합니다. */

/* --- 모든 자료형의 메모리 할당 사이즈 출력 --- */
void ex_PrintAllDataSize(void)
{
    PrintDataSize(bool);
    PrintDataSize(char);
    PrintDataSize(wchar_t);
    PrintDataSize(char16_t);
    PrintDataSize(char32_t);
    PrintDataSize(short);
    PrintDataSize(int);
    PrintDataSize(long);
    PrintDataSize(long long);
    PrintDataSize(unsigned);
    PrintDataSize(unsigned short);
    PrintDataSize(unsigned long);
    PrintDataSize(unsigned long long);
    PrintDataSize(float);
    PrintDataSize(double);
    PrintDataSize(long double);
    PrintDataSize(nullptr_t);
}

/* --- 형 변환 예제 --- */
void ex_Conversion(void)
{
    int a = 10;
    double b = a;

    cout << "암시적 형변환: " << endl;
    cout << a << b << endl;

    cout << "명시적 형변환: " << endl;
    int c = 10;
    cout << "before: " << c << endl;
    double d = (double)c; // c 방식 형변환
    cout << "C style: " << d << endl;
    double e = static_cast<double>(c); // c++ 방식의 형변환
    cout << "C++ style: " << c << endl;

    const int f = 20;
    int *g = const_cast<int *>(&f); // const 선언을 해제하거나 추가하는 형변환
    cout << "const cast : " << *g << *g + 10 << endl;

    int *h = &a;
    char *i = reinterpret_cast<char *>(h); // 포인터간 형변환
    cout << "reinterpret cast : " << *h << *i << endl;

    /* dynamic_cast: 객체 간의 형변환도 가능하지만 현재 객체(class)에 대한 개념이 정립되지 않아 추후에 작성하기로 한다. */
}

#include <bitset>
/* --- 이진법 출력 예제 --- */
void ex_BitSet(void)
{
    char c = 1;
    short int si = 2;
    int i = 4;

    cout << "c = " << bitset<sizeof(char) * 8>(c) << "<" << static_cast<int>(c) << ">" << endl;
    cout << "si = " << bitset<sizeof(short int) * 8>(si) << "<" << si << ">" << endl;
    cout << "i = " << bitset<sizeof(int) * 8>(i) << "<" << i << ">" << endl;
}

/* --- 특이한 구조체 활용 --- */
void ex_struct(void)
{
    struct Point
    {
        int x;
        int y;
    } pt1 = {30, 50}, pt2;

    pt2 = pt1;

    cout << "pt1 : (" << pt1.x << ", " << pt1.y << ")" << endl;
    cout << "pt2 : (" << pt2.x << ", " << pt2.y << ")" << endl;
}

/* --- 엔디안 확인 예제 --- */
void ex_CheckEndian(void)
{
    unsigned int num = 0x12345678;
    unsigned char *ptr = reinterpret_cast<unsigned char *>(&num);

    cout << "Byte order: ";
    for (int i = 0; i < sizeof(num); ++i)
        printf("%02x ", ptr[i]);
    cout << endl;

    if (ptr[0] == 0x78)
        cout << "System is Little-Endian" << endl;
    else if (ptr[0] == 0x12)
        cout << "System is Big-Endian" << endl;
    else
        cout << "Unknown Endian" << endl;
}
/* 맥 실행 결과
Byte order: 78 56 34 12
System is Little-Endian
*/

/* --- 포인터와 배열의 관계 예제 --- */
void ex_PointerNArray(void)
{
    int nArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p = nArray;

    while (p != &nArray[10])
    {
        cout << p << " : " << *p << endl;
        p++;
    }
}

/* --- 레퍼런스 변수의 활용 예제 --- */
void ex_reference(void)
{
    int iTarget = 20;
    int &ref = iTarget;

    cout << "iTarget: " << iTarget << endl;
    cout << "ref: " << ref << endl;
    cout << "&iTarget: " << &iTarget << endl;
    cout << "&ref: " << &ref << endl;

    ref += 100;
    cout << "iTarget: " << iTarget << endl;
    cout << "ref: " << ref << endl;

    int *pTarget = &iTarget;
    int *&pRef = pTarget; // int 포인터 변수에 대한 참조
    cout << "pTarget: " << pTarget << endl;
    cout << "pRef: " << pRef << endl;
    cout << "*pTarget: " << *pTarget << endl;
    cout << "*pRef: " << *pRef << endl;

    const int &constRef = iTarget;
    iTarget -= 100; // 가능
    // constRef -= 100; // 불가능
    cout << "iTarget: " << iTarget << endl;
    cout << "constRef: " << constRef << endl;

    char c = 'a';
    const int &rci = c; // char 값을 int 타입으로 형 변환 > 임시 변수에 저장 후 참조
    // int &ri = c; // int 형 레퍼런스틑 char 형 변수를 가리킬 수 없다.
    cout << "c: " << c << endl;
    cout << "rci: " << rci << endl;
}

#include <cmath>

/* --- CRT 사용 예제 --- */
void ex_CRT(void)
{
    double sqrt_2 = sqrt(2.0);    /* 2의 제곱근 */
    double pow_12_2 = pow(12, 2); /* 12의 2제곱 */
    cout << "2의 제곱근: " << sqrt_2 << endl;
    cout << "12의 2제곱: " << pow_12_2 << endl;
}

static int max(int a, int b)
{
    return (a > b) ? a : b;
}

static float max(float a, float b)
{
    return (a > b) ? a : b;
}

/* --- 함수 오버로딩 예제 --- */
void ex_Overloading(void)
{
    int a = 10;
    int b = 20;
    int c = max(a, b);

    cout << "a: " << a << '\n'
         << "b: " << b << '\n'
         << "c: " << c << endl;

    float fA = 1.1f;
    float fB = 1.2f;
    float fC = max(fA, fB);
    cout << "fA: " << fA << '\n'
         << "fB: " << fB << '\n'
         << "fC: " << fC << endl;
}

/* --- 디폴트 인자 사용 예제 --- */
void ex_DefaultArg(int i)
{
    cout << "i = " << i << endl;
}

/* --- string 클래스 예제 --- */
void ex_string(void)
{
    string s = "C++ String"; /* string 클래스의 객체 s 생성 */
    cout << s << endl;

    string sCopy = s; /* 문자열 복사 */
    cout << sCopy << endl;

    cout << "size: " << sCopy.size() << endl; /* 문자열 길이 출력 */

    string s2 = "\nI love it!";
    s = sCopy + s2; /* 문자열 결합 */

    cout << s << endl;

    cout << (s == "C++ String\nI love it!") << endl; /* 문자열 비교 연산 */
    cout << (s == "I'm so sexy~") << endl;           /* 문자열 비교 연산 */

    cout << s.find(s2) << endl; /* 문자열 검색 */
    // strstr() 과 유사 대신 strstr()은 찾은 위치의 주소를 반환

    string s3byte = s.substr(s.size() - 3, 3);
    cout << s3byte << endl; /* 문자열 s의 맨 뒤쪽 3 문자만 추출*/

    const char *cString = s.c_str(); /* Cpp 스타일 문자열을 C 스타일로 변환(읽기용) */
    cout << cString << endl;
    char *NewString = "new string";
    s = NewString; /* C 스타일 문자열 Cpp 스타일로 변환 */
    cout << s << endl;

    /* 읽기 쓰기 가능한 char * 문자열 만드는 방법 */
    char *cstyle = new char[s.size() + 1];
    strcpy(cstyle, s.c_str());
    cstyle[0] = 'z';
    cout << "cstyle: " << cstyle << endl;


}