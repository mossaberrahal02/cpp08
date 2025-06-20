/**
* in c++ linked lists are implemented as doubly linked list
*/

#include <iostream>
#include <stdexcept>

template <typename T>
class MyList
{
    private:
        struct Node
        {
            T data;
            Node * next;
            Node * prev;
            Node (const T & data):data(data), next(NULL), prev(NULL){}
        };
        Node * head;
        Node * tail;
        size_t size;
    public:
        MyList(): head(NULL), tail(NULL), size(0)
        {
        }
        ~MyList()
        {
            clear();
        }
        void push_front(const T & value)
        {
            Node * new_node = new Node(value);
            if(!head)
                head = tail = new_node;
            else
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            size++;
        }
        void push_back(const T & value)
        {
            Node * new_node = new Node(value);
            if(!head)
                head = tail = new_node;
            else
            {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
            ++size;
        }
        void pop_front()
        {
            if(head)
            {
                Node * tmp = head;
                head = head->next;
                if(head)
                    head->prev = NULL;
                else
                    tail = NULL;
                delete tmp;
            }
            size--;
        }
        void pop_back()
        {
            if(tail)
            {
                Node * tmp = tail;
                tail = tail->prev;
                if(tail)
                    tail->next = NULL;
                else
                    head = NULL;//the list became empty after poping from the back
                delete tmp;
            }
            size--;
        }
        T& front()
        {
            if (!head)
                throw std::out_of_range("List is empty");
            return head->data;
        }

        T& back()
        {
            if (!tail)
                throw std::out_of_range("List is empty");
            return tail->data;
        }
        size_t get_size() const
        {
            return size;
        }
        bool empty() const {
            return size == 0;
        }
        void clear() {
            while (head != NULL) {
                pop_front();
            }
        }
            void print() const
            {
                Node* current = head;
                while (current != NULL) {
                    std::cout << current->data << " ";
                    current = current->next;
                }
                std::cout << std::endl;
            }
};

int main() {
    MyList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.push_back(30);

    std::cout << "List: ";
    list.print();

    std::cout << "Size of list: " << list.get_size() << std::endl;
    std::cout << "Front element: " << list.front() << std::endl;
    std::cout << "Back element: " << list.back() << std::endl;

    list.pop_front();
    list.pop_back();

    std::cout << "After popping front and back: ";
    list.print();

    list.clear();
    std::cout << "After clearing, list is empty: " << (list.empty() ? "Yes" : "No") << std::endl;

    return 0;
}