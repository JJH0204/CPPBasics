#include <iostream>
#include "includeOOP.h"

int main(int argc, char *argv[])
{
    // ex_class();
    LinkedList<int> intLinkedList1;
    intLinkedList1.Add(10, 0);
    intLinkedList1.Add(20, 1);
    intLinkedList1.Add(30, 2);
    intLinkedList1.Add(40, 3);

    LinkedList<int> intLinkedList2 = intLinkedList1;

    std::cout << "intListedList1:" << std::endl;
    intLinkedList1.PrintT();
    std::cout << "intListedList2:" << std::endl;
    intLinkedList2.PrintT();
    
    intLinkedList1.Destruct();
    intLinkedList2.Destruct();
    // delete intLinkedList;
    return 0;
}
/*
intListedList1:
|index  |data   |
|0      |10     |
|1      |20     |
|2      |30     |
|3      |40     |
intListedList2:
|index  |data   |
|0      |10     |
|1      |20     |
|2      |30     |
|3      |40     |
*/