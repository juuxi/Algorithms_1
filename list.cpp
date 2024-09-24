#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
    Node () {};
    Node (Node* _next, Node* _prev, T _value) {next = _next; prev = _prev; value = _value;}
};

template <typename T>
class List {
    Node<T>* head;
    Node<T>* tail;
    Node<T>* get(size_t);
public:
    List() {head = nullptr; tail = nullptr;}
    bool is_empty() {if (head) return false; return true;}
    void push_front(T);  
    void push_back(T);  
    Node<T>* front() {return head;}
    Node<T>* back() {return tail;}
    size_t size();
    T get_val(size_t);
    void remove(size_t);
};

template <typename T>
void List<T>::push_front(T _val)
{
    if(!head)
    {
      head = new Node<T>;
      head->next = nullptr;
      head->prev = nullptr;
      tail = head;
      head->value = _val;
      return;
    }
    Node<T>* new_head = new Node<T>;
    new_head->next = head;
    head->prev = new_head;
    new_head->prev = nullptr;
    head = new_head;
    new_head->value = _val;
}

template <typename T>
void List<T>::push_back(T _val)
{
    if(!head)
    {
      head = new Node<T>;
      head->next = nullptr;
      head->prev = nullptr;
      tail = head;
      head->value = _val;
      return;
    }
    Node<T>* new_tail = new Node<T>;
    new_tail->prev = tail;
    tail->next = new_tail;
    new_tail->next = nullptr;
    tail = new_tail;
    new_tail->value = _val;
}

template <typename T>
size_t List<T>::size()
{
    Node<T>* curr = head;
    if (curr == nullptr)
        return 0;
    size_t counter = 1;
    while(curr != tail)
    {
        counter++;
        curr = curr->next;
    }
    return counter;
}

template <typename T>
Node<T>* List<T>::get(size_t pos)
{
    if (pos <= size()/2)
    {
        Node<T>* curr = head;
        for (int i = 0; i < pos-1; i++)
            curr = curr->next;
        return curr;
    }
    Node<T>* curr = tail;
    for (int i = size(); i > pos; i--)
        curr = curr->prev;
    return curr;
}

template <typename T>
void List<T>::remove(size_t pos)
{
    Node<T>* curr = get(pos);
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

template <typename T>
T List<T>::get_val(size_t pos)
{
    Node<T>* curr = get(pos);
    return curr->value;
}