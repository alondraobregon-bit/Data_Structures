#include <iostream>
using namespace ::std;

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* back;
    int count;
public:
    Queue() : front(nullptr), back(nullptr), count(0){}

    void push(T value) {
        Node<T>* newNode = new Node<T>{value, nullptr};
        if (front == nullptr and back == nullptr) {
            front = back = newNode;
        }
        else {
            back -> next = newNode;
            back = newNode;
        }
        count++;
    }
};