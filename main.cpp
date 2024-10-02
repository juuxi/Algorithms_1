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
    if (op2 == '^' && op1 == '^')
        return false;
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
    bool flag = false;
    std::string str;
    Stack<char> main_stack;
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char operators[] = {'-', '+', '*', '/', '^'};
    char functions[] = {'s', 'c'};
    while (true)
    {
        system("clear");
        if (flag)
            break;
        std::cout << "1 - Алгоритм сортировочной станции" << std::endl;
        std::cout << "2 - Работа списка" << std::endl;
        std::cout << "3 - Работа динамического массива" << std::endl;
        std::cout << "4 - Выход" << std::endl;
        std::cout << "> ";
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
                        while(!main_stack.is_empty() &&  incl(main_stack.get_value(), operators, OP_SIZE) && is_op2_higher_priority(token, main_stack.get_value()))
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
                            if (main_stack.get_value() == 's')
                                std::cout << "sin";
                            if (main_stack.get_value() == 'c')
                                std::cout << "cos";
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
                        if (main_stack.get_value() == 's')
                            std::cout << "sin";
                        else if (main_stack.get_value() == 'c')
                            std::cout << "cos";
                        else 
                            std::cout << main_stack.get_value();
                        main_stack.pop_front();
                    }
                }

                if (!err)
                    std::cout << std::endl << "Complete!" << std::endl;
                break;
            }
            case '2':
            {
                List<int> list;
                char ch_list;
                bool list_flag = false;
                while(!list_flag)
                {
                    std::cout << std::endl;
                    std::cout << "1 - Добавить в начало" << std::endl;
                    std::cout << "2 - Добавить в конец" << std::endl;
                    std::cout << "3 - Узнать размер" << std::endl;
                    std::cout << "4 - Узнать значение элемента" << std::endl;
                    std::cout << "5 - Удалить элемент" << std::endl;
                    std::cout << "6 - Выход" << std::endl;
                    std::cout << "> ";
                    std::cin >> ch_list;
                    switch(ch_list)
                    {
                        case '1':
                        {
                            int val;
                            std::cout << "Введите значение" << std::endl;
                            std::cout << "> ";
                            std::cin >> val;
                            list.push_front(val);
                            break;
                        }
                        case '2':
                        {
                            int val;
                            std::cout << "Введите значение" << std::endl;
                            std::cout << "> ";
                            std::cin >> val;
                            list.push_back(val);
                            break;
                        }
                        case '3':
                        {
                            std::cout << list.size();
                            break;
                        }
                        case '4':
                        {
                            size_t pos;
                            std::cout << "Введите номер элемента" << std::endl;
                            std::cout << "> ";
                            std::cin >> pos;
                            std::cout << list.get_val(pos);
                            break;
                        }
                        case '5':
                        {
                            size_t pos;
                            std::cout << "Введите номер элемента" << std::endl;
                            std::cout << "> ";
                            std::cin >> pos;
                            list.remove(pos);
                            break;
                        }
                        case '6':
                            list_flag = true;
                            break;
                        default: 
                            break;
                    }
                }
                break;
            }

            case '3':
            {
                Vector<int> vec(10);
                char ch_vec;
                bool vec_flag = false;
                while(!vec_flag)
                {
                    std::cout << std::endl;
                    std::cout << "1 - Добавить элемент" << std::endl;
                    std::cout << "2 - Узнать значение элемента" << std::endl;
                    std::cout << "3 - Удалить элемент" << std::endl;
                    std::cout << "4 - Вывести весь массив" << std::endl;
                    std::cout << "5 - Выход" << std::endl;
                    std::cout << "> ";
                    std::cin >> ch_vec;
                    switch(ch_vec)
                    {
                        case '1':
                        {
                            int val;
                            size_t pos;
                            std::cout << "Введите значение" << std::endl;
                            std::cout << "> ";
                            std::cin >> val;
                            std::cout << "Введите позицию" << std::endl;
                            std::cout << "> ";
                            std::cin >> pos;
                            vec.add(pos, val);
                            break;
                        }
                        case '2':
                        {
                            size_t pos;
                            std::cout << "Введите номер элемента" << std::endl;
                            std::cout << "> ";
                            std::cin >> pos;
                            std::cout << vec.get_value(pos);
                            break;
                        }
                        case '3':
                        {
                            size_t pos;
                            std::cout << "Введите номер элемента" << std::endl;
                            std::cout << "> ";
                            std::cin >> pos;
                            vec.remove(pos);
                            break;
                        }
                        case '4':
                        {
                            for (size_t i = 0; i < vec.get_size(); i++)
                                std::cout << vec.get_value(i) << " ";
                        }
                        case '5':
                            vec_flag = true;
                            break;
                        default: 
                            break;
                    }
                }
                break;
            }

            case '4':
                flag = true;
                break;
            default:
            {
                std::cout << "Wrong!" << std::endl;
                break;
            }
        }
    }
    return 0;
}