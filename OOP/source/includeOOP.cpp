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
        std::cout << "|" << nLoop << "\t|" << pCurNode->get_data() << "\t|" << endl;
        pCurNode = pCurNode->get_next();
    }
    return;
}

template <typename T>
void LinkedList<T>::Add(Node<T> &data, const int index)
{
    Node<T> *currentNode = _header;
    if (currentNode == nullptr || index <= 0)   /* 리스트의 가장 처음에 데이터 넣기 */
    {
        Node<T> *newNode = new Node<T> *(data);
        newNode->set_next(_header);
        _header = newNode;
        _Current++;
        return;
    }
    else if (get_Current() + 1 < index)         /* 리스트의 가장 마지막에 데이터 넣기 */
    {
        /* code */
    }
    else                                        /* 원하는 위치 index에 데이터 넣기 */
    {
        // for (int nLoop = 0; currentNode->get_next() != nullptr && nLoop < get_Current() && nLoop < index - 1; nLoop++)
        // {
        //     /* code */
        // }
        // if (index <= 0)
        // {
        // }
        // else
        // {
        // }
    }
}

template <typename T>
void LinkedList<T>::Add(T &data, const int index)
{

}