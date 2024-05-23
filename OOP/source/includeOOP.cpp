#include <iostream>
#include <string>
#include "includeOOP.h"

template <typename T>
Node<T> *LinkedList<T>::get_header(void)
{
    return _header;
}

template <typename T>
int LinkedList<T>::get_Current(void)
{
    return _Current;
}

template <typename T>
void LinkedList<T>::PrintT(void)
{
    Node<T> *pCurNode = nullptr;
    int nLoop = 0;

    if ((pCurNode = get_header()) == nullptr)
        return;

    std::cout << "|index\t|data\t" << std::endl;

    for (; (nLoop < get_Current()) && pCurNode != nullptr; nLoop++)
    {
        std::cout << "|" << nLoop << "\t|";
    }
}
