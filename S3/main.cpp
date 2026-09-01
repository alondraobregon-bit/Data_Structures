#include <iostream>
using namespace::std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode *next;

    LinkedNode() {
        next = nullptr;
    }

    LinkedNode(data_type data, LinkedNode* next=nullptr) : data(data), next(next) {}
};

template<typename data_type>
struct DoublyLinkedNode {
    data_type data;
    DoublyLinkedNode *next;
    DoublyLinkedNode *prev;

    DoublyLinkedNode() {
        next = prev = nullptr;
    }
};


template<typename data_type>
struct LinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;

    LinkedList() {
        head = tail = nullptr;
    }

    void push_front(data_type value) {
        //Inserta un nodo con informacion "value"
        //al inicio de la lista
        LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, head);
        if (head == nullptr) {
            tail = new_node;
        }
        head = new_node;
    }

    void push_back(data_type value) {
        if (tail == nullptr) {
            head = tail = new LinkedNode<data_type>(value);
        }
        else {
            tail -> next = new LinkedNode<data_type>(value);
            tail = tail -> next;
        }
    }

    void insert(LinkedNode<data_type>* node, data_type value) {
        //Inserta un nodo con información "value"
        //Despues del nodo "node"
        LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, node->next);
        if (node == tail) {
            tail = new_node;
        }
    }

    void insert(int k, data_type value) {
        //Inserta "value" como el k_ésimo valor en la nueva secuencia
        //0-indexed
        if (k==0) push_front(value);
        else {
            LinkedNode<data_type>* current = head;
            for (int i=0; i <k-1; ++i) {
                current = current->next;
            }
            insert(current, value);
        }
    }

    void pop_front() {
        LinkedNode<data_type>* current = head;
        head = head -> next;
        if (head == nullptr) tail = nullptr;
        delete current;
    }

    void erase(LinkedNode<data_type>* node) {
        //Elimina el siguiente al node "node"
        if (node -> next) {
            LinkedNode<data_type>* current = node -> next;
            node -> next = node -> next->next;
            delete current;
        }
    }

    void erase(int k) {
        if (k==0) pop_front();
        else {
            LinkedNode<data_type>* current = head;
            for (int i=0; i <k-1; ++i) {
                current = current->next;
            }
            erase(current);
        }
    }

    void print() {
        LinkedNode<data_type>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current -> next;
        }
        cout << '\n';
    }
};

struct DoublyLinkedList {
};

struct CircularLinkedList {

};

int main() {
    LinkedList<int> L;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        if (op[0] == 'I') {
            int k, x;
            cin >> k >> x;
            L.insert(k, x);
        }
        else {
            int k;
            cin >> k;
            L.erase(k);
        }
    }
    L.print();
    return 0;
}