#include <iostream>
using namespace std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;

    LinkedNode() {
        next = nullptr;
    }

    LinkedNode(data_type data, LinkedNode<data_type>* next = nullptr): data(data), next(next) {}
};

template<typename data_type>
struct CircularLinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;

    CircularLinkedList() {
        head = tail = nullptr;
    }

    data_type front() {
        return head->data;
    }

    void send_front_to_back(int quantum) {
        head -> data -= quantum;
        head = head -> next;
        tail = tail -> next;
    }
    void pop_front() {
        LinkedNode<data_type>* current = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head -> next;
            tail -> next = head;
        }
        delete current;
    }

    void push_back(data_type value) {
        if (head == nullptr) {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value);
            head = tail = new_node;
            new_node -> next = head;
        }
        else {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value,
            head);
            tail -> next = new_node;
            tail = tail -> next;
        }
    }
    bool empty() {
        return head == nullptr;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n;
    cin >> n;

    CircularLinkedList<long long> L;

    for (long long i = 0; i < n; i++) {
        L.push_back(i+1);
    }

    long long remain = n;

    LinkedNode<long long>* cur = L.head;
    LinkedNode<long long>* trail = L.tail;

    while (remain > 1) {
        trail = cur;
        cur = cur -> next;
        cout << cur -> data << " ";
        trail->next = cur -> next;
        if (cur == L.head) {
            L.head = cur->next;
        }
        if (cur == L.tail) {
            L.tail = trail;
        }

        LinkedNode<long long>* to_delete = cur;
        cur = cur -> next;
        delete to_delete;
        remain--;
    }
    cout << L.head -> data << " ";

    return 0;
}