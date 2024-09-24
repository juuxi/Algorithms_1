#include "list.cpp"
#include "vector.cpp"
#include "stack.cpp"
#include <iostream>

int main()
{
    List<int> a;
    a.push_front(1);
    a.push_back(7);
    a.push_back(5);
    std::cout << a.get_val(1) << std::endl;
    std::cout << a.get_val(2) << std::endl;
    a.remove(2);
    std::cout << a.get_val(2) << std::endl;
    return 0;
}