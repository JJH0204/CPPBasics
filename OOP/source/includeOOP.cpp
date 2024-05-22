#include <iostream>
#include <string>
#include "includeOOP.h"

Node::Node(void)
{
    _data = nullptr;
    _pNext = nullptr;
}

Node::Node(void *data, Node *pNext)
{
    set_data(data);
    set_next(pNext);
}

void Node::set_data(void *data)
{
    _data = data;
}

void Node::set_next(Node *pNext)
{
    _pNext = pNext;
}

Node *Node::get_next(void)
{
    return _pNext;
}

Node *LinkedList::get_header(void)
{
    return _header;
}

int LinkedList::get_Current(void)
{
    return _Current;
}

void LinkedList::PrintT(void)
{
    Node *pCurNode = nullptr;
    int nLoop = 0;

    if ((pCurNode = get_header()) == nullptr)
        return;

    std::cout << "|index\t|data\t" << std::endl;

    for (; (nLoop < get_Current()) && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|";
    }
}
