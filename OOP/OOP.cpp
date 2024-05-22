#include <iostream>
#include "includeOOP.h"

void ex_class(void)
{
    int iData = 10;
    Node intNode(&iData);
    std::cout << "iData: " << iData << "\nintNode: " << intNode.get_data<int>() << std::endl;
    iData++;
    std::cout << "iData: " << iData << "\nintNode: " << intNode.get_data<int>() << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    ex_class();
    return 0;
}