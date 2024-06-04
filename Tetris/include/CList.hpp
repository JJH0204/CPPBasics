#ifndef __CLIST__
#define __CLIST__

template <typename T>
class Node
{
private:
    T _data;
    Node *_next;

public:
    Node() : _data(T()), _next(nullptr) {}
    Node(const T data, Node *pNext = nullptr) : _data(data), _next(pNext) {}
    Node(const Node &node) : _data(node._data), _next(node._next) {}
    ~Node(void) {}

    void setData(const T data) { _data = data; }
    T getData(void) { return _data; }

    void setNext(Node *pNext) { _pNext = pNext; }
    Node *getNext(void) { return _pNext; }
};

template <typename T>
class CList
{
private:
    Node<T> *_Header;
    int _Current;

public:
    LinkedList(void) : _Header(nullptr), _Current(0) {}
    ~LinkedList() {}

    int getCurrent() { return _Current; }
    Node<T> *getHeader() { return _Header; }

    void setCurrent() {}


    void add(const T &data, const int index = -1);
};

// template <typename T>
// void CList<T>::add(const T &data, const int index)
// {
//     Node<T> *pNewNode = new (std::nothrow) Node<T>;

//     if (pNewNode == nullptr)
//         return;

//     pNewNode->setData(data);

//     if (index < 0)
//         index = 
// }
#endif