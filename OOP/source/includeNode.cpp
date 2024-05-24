#include <iostream>
#include "includeNode.h"

/* 객체 생성 및 사용 예제 */
void ex_class(void)
{
    Node<int> intNode1(10);   /* 객체 초기화 */
    Node intNode2 = intNode1; /* intNode 객체를 이용해 intNode2 객체 초기화 */
    std::cout << "intNode1: " << intNode1.getData() << '\n'
              << "intNode2: " << intNode2.getData() << std::endl;
    intNode2.setData(20); /* 멤버 함수를 이용해 intNode2 객체의 데이터 수정 */
    std::cout << "intNode1: " << intNode1.getData() << '\n'
              << "intNode2: " << intNode2.getData() << std::endl;
    intNode1 = intNode2; /* 객체 intNode2를 intNode에 대입 */
    std::cout << "intNode1: " << intNode1.getData() << '\n'
              << "intNode2: " << intNode2.getData() << std::endl;

    /* 두 객체의 데이터를 더한 후 임시 객체를 생성해 intNode3를 초기화*/
    Node intNode3(Node(intNode1.getData() + intNode2.getData()));
    // Node intNode3(intNode1.getData() + intNode2.getData());
    std::cout << "intNode1: " << intNode1.getData() << '\n'
              << "intNode2: " << intNode2.getData() << '\n'
              << "intNode3: " << intNode3.getData() << std::endl;
    return;
}
