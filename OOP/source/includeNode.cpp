#include <iostream>
#include "includeNode.h"

/* 객체 생성 및 사용 예제 */
void ex_class(void)
{
    Node<int> intNode(10);   /* 객체 초기화 */
    Node intNode2 = intNode; /* intNode 객체를 이용해 intNode2 객체 초기화 */
    std::cout << "intNode: " << intNode.get_data() << '\n'
              << "intNode2: " << intNode2.get_data() << std::endl;
    intNode2.set_data(20); /* 멤버 함수를 이용해 intNode2 객체의 데이터 수정 */
    std::cout << "intNode: " << intNode.get_data() << '\n'
              << "intNode2: " << intNode2.get_data() << std::endl;
    intNode = intNode2; /* 객체 intNode2를 intNode에 대입 */
    std::cout << "intNode: " << intNode.get_data() << '\n'
              << "intNode2: " << intNode2.get_data() << std::endl;

    /* 두 객체의 데이터를 더한 후 임시 객체를 생성해 intNode3를 초기화*/
    Node intNode3(Node(intNode.get_data() + intNode2.get_data()));
    std::cout << "intNode: " << intNode.get_data() << '\n'
              << "intNode2: " << intNode2.get_data() << '\n'
              << "intNode3: " << intNode3.get_data() << std::endl;
    return;
}
