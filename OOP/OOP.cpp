#include <iostream>
#include "includeOOP.h"

int main(int argc, char *argv[])
{
    // ex_class();
    LinkedList<int> *intLinkedList = new LinkedList<int>;
    intLinkedList->Add(Node(10), 0);
    intLinkedList->Add(Node(20), 1);
    intLinkedList->Add(Node(30), 2);
    intLinkedList->Add(Node(40), 3);
    intLinkedList->PrintT();
    intLinkedList->Destruct();
    return 0;
}