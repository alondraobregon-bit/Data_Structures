#include <iostream>
using namespace ::std;

template<typename data_type>
struct DoublyLinkedNode {
    data_type data;
    DoublyLinkedNode *next;
    DoublyLinkedNode *prev;

    DoublyLinkedNode() {
        next=prev=nullptr;
    }
    DoublyLinkedNode(data_type data, DoublyLinkedNode<data_type>* next = nullptr, DoublyLinkedNode<data_type>* prev = nullptr) : data(data), next(next), prev(prev)
    {}
};

template<typename data_type>
struct DoublyLinked {
    DoublyLinkedNode<data_type> *head;
    DoublyLinkedNode<data_type> *tail;

    DoublyLinked() {
        head=tail=nullptr;
    }

    void insert(data_type value) {
        DoublyLinkedNode<data_type>* new_node = new DoublyLinkedNode<data_type>(value, head);
        if (head == nullptr) {
            tail=new_node;
        }
        else {
            head->prev=new_node;
        }
        head=new_node;
    }

    void erase(DoublyLinkedNode<data_type>* node){
        if (node == head) {
            delete_front();
        }
        else if (node == tail) {
            delete_back();
        }
        else {
            DoublyLinkedNode<data_type>* pred = node -> prev;
            DoublyLinkedNode<data_type>* suce = node -> next;

            pred->next=suce;
            suce->prev=pred;
            delete node;
        }
    }
    void delete_first(data_type key) {
        DoublyLinkedNode<data_type>* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                erase(current);
                break;
            }
            current = current->next;
        }
    }

    void delete_front() {
        DoublyLinkedNode<data_type>* node = head;
        if (head == tail) {
            delete node;
            head = tail = nullptr;
        }
        else {
            head = head -> next;
            head->prev = nullptr;
            delete node;
        }
    }

    void delete_back() {
        DoublyLinkedNode<data_type>* node = tail;
        if (head == tail) {
            delete node;
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
            delete node;
        }
    }

    void print() {
        DoublyLinkedNode<data_type>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current -> next;
        }
        cout << "\n";
    }
};

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    DoublyLinked<int> L;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        if (op[0] == 'i') {
            int x;
            cin >> x;
            L.insert(x);
        }
        else if (op.size() == 6) {
            int x;
            cin >> x;
            L.delete_first(x);
        }
        else if (op[6] == 'F') {
            L.delete_front();
        }
        else {
            L.delete_back();
        }
    }
    L.print();
    return 0;
}