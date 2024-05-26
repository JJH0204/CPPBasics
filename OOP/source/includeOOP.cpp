#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "includeOOP.h"

/* 리스트 예제 */
void exLinkedList1(void)
{
    LinkedList<int> intLinkedList1;
    intLinkedList1.Add(10, 0);
    intLinkedList1.Add(20, 2);
    intLinkedList1.Add(30, 1);
    intLinkedList1.Add(40, 3);
    LinkedList<int> intLinkedList2 = intLinkedList1;

    std::cout << "intListedList1:" << std::endl;
    intLinkedList1.PrintT();
    std::cout << "intListedList2:" << std::endl;
    intLinkedList2.PrintT();

    intLinkedList1.Destruct();
    intLinkedList2.Destruct();
}

/* 오름차순 비교 함수 */
static int intCmp(const int &a, const int &b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

/* 내림차순 비교 함수 */
static int intCmpR(const int &a, const int &b)
{
    return intCmp(a, b) * -1;
}

/* 리스트 정렬하는 예제 */
void exLinkedList2(void)
{
    std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<> dis(0, 99);

    LinkedList<int> intLinkedList;
    intLinkedList.Add(dis(gen), 0);
    intLinkedList.Add(dis(gen), 1);
    intLinkedList.Add(dis(gen), 2);
    intLinkedList.Add(dis(gen), 3);
    intLinkedList.Add(dis(gen), 4);
    intLinkedList.Add(dis(gen), 5);

    std::cout << "Before:" << std::endl;
    intLinkedList.PrintT();
    intLinkedList.Sort(intCmp);
    std::cout << "After:" << std::endl;
    intLinkedList.PrintT();
    intLinkedList.Destruct();
}

void exStack1(void)
{
    Stack<int> intStack1;
    intStack1.Push(10);
    intStack1.Push(20);
    intStack1.Push(30);
    intStack1.Push(40);
    Stack<int> intStack2 = intStack1;
    intStack1.Push(50);

    std::cout << "intStack1.Peek(): " << intStack1.Peek() << std::endl;
    std::cout << "intStack2.Pop(): " << intStack2.Pop() << std::endl;

    std::cout << "intStack1:" << std::endl;
    intStack1.PrintT();
    std::cout << "intStack2:" << std::endl;
    intStack2.PrintT();

    intStack1.Destruct();
    intStack2.Destruct();
}

void exStack2(void)
{

}