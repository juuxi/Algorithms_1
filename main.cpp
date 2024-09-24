#include "list.cpp"
#include "vector.cpp"
#include "stack.cpp"
#include <iostream>

int main()
{
    Vector<int> v(5);
    v.add(1, 10);
    v.add(2, 15);
    std::cout << v.get_value(2) << std::endl;
    v.add(3, 24);
    v.remove(2);
    std::cout << v.get_value(2) << std::endl;
    return 0;
}