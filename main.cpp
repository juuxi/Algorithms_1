#include "list.cpp"
#include "vector.cpp"
#include "stack.cpp"
#include <iostream>

#define NUM_SIZE 10
#define OP_SIZE 5
#define FUNC_SIZE 2

bool incl (char token, char* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (token == arr[i])
            return true;
    }
    return false;
}

bool is_op2_higher_priority(char op1, char op2)
{
    if (op2 == '^')
        return true;
    if (op1 == '^')
        return false;
    if (op2 == '*' || op2 == '/')
        return true;
    if (op1 == '*' || op1 == '/')
        return false;
    return true;
}

int main()
{
    char ch;
    std::string str;
    Stack<char> main_stack;
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char operators[] = {'-', '+', '*', '/', '^'};
    char functions[] = {'s', 'c'};
    std::cout << "1 - Алгоритм сортировочной станции" << std::endl << "> ";
    std::cin >> ch;
    switch(ch)
    {
        case '1':
        {
            bool err = false;
            char token;
            std::cout << "Введите данные" << std::endl;
            std::cin.ignore(256, '\n');
            getline(std::cin, str);
            while (!str.empty() && !err)
            {
                token = str[0];
                str.erase(0, 1);
                if (str[0] == ' ')
                    str.erase(0, 1);
                if (incl(token, numbers, NUM_SIZE))
                    std::cout << token;
                if (incl(token, functions, FUNC_SIZE))
                    main_stack.push_front(token);
                if (incl(token, operators, OP_SIZE))
                {
                    while(!main_stack.is_empty() && is_op2_higher_priority(token, main_stack.get_value()))
                    {
                        std::cout << main_stack.get_value();
                        main_stack.pop_front();
                    }
                    main_stack.push_front(token);
                }
                if (token == '(')
                    main_stack.push_front('(');
                if (token == ')')
                {
                    while (!main_stack.is_empty() && incl(main_stack.get_value(), operators, OP_SIZE))
                    {
                        std::cout << main_stack.get_value();
                        main_stack.pop_front();
                    }
                    if (main_stack.is_empty())
                    {
                        std::cout << std::endl << "Error";
                        err = true;
                    }
                    if (incl(main_stack.get_value(), functions, FUNC_SIZE))
                    {
                        std::cout << main_stack.get_value();
                        main_stack.pop_front();
                    }
                    if (main_stack.get_value() == '(')
                        main_stack.pop_front();
                }
            }

            while (!main_stack.is_empty() && !err)
            {
                if (main_stack.get_value() == '(')
                {
                    std::cout << std::endl << "Error";
                    err = true;
                }
                else 
                {
                    std::cout << main_stack.get_value();
                    main_stack.pop_front();
                }
            }

            if (!err)
                std::cout << std::endl << "Complete!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wrong!" << std::endl;
            break;
        }
    }
    return 0;
}