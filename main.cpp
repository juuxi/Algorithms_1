#include "list.cpp"
#include "vector.cpp"
#include "stack.cpp"
#include <iostream>

int main()
{
    Stack<char> s;
    s.push_front('h');
    s.push_front('1');
    std::cout << s.get_value() << std::endl;
    s.pop_front();
    std::cout << s.get_value() << std::endl;
    return 0;
}