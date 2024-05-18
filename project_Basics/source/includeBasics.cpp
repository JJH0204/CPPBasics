#include <iostream>
#include "includeBasics.h"
using namespace std;

void ex_main (void)
{
    /* 변수 정의 및 데이터 저장 */
    int a = 100, b = 200, c = 300;
    string str;
    /* console output의 약자, 전달 받은 값을 콘솔창에 출력 */
    cout << "Please input your name: ";
    cin >> str;
    cout << "Hi " << str << "~!" << endl;
    /* 변수에 저장된 값 출력 */
    cout << a << b << c << c << std::endl;
}