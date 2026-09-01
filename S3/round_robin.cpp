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

    T pop() {
        if (front == nullptr) {
            throw std::underflow_error("Queue esta vacio");
        }
        T value = front -> data;
        if (front == back) {
            Node<T>* temp = front;
            front = back = nullptr;
            delete temp;
        }
        else {
            Node<T>* temp = front;
            front = front -> next;
            delete temp;
        }
        count--;
        return value;
    }

    T top() {
        if (front == nullptr) {
            throw std::underflow_error("Queue esta vacio");
        }
        return front->data;
    }

    bool empty() {
        return front == nullptr;
    }

    int size() {
        return count;
    }
};

struct Process{
    string name;
    long long time;
};

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int n;
    long long q;
    cin >> n >> q;

    Queue<Process> cola;
    for (int i=0; i<n; i++) {
        string name;
        long long t;
        cin >> name >> t;
        cola.push(Process{name, t});
    }

    long long tiempo_actual = 0;

    while (!cola.empty()) {
        Process p = cola.pop();
        if (p.time <= q) {
            tiempo_actual += p.time;
            cout << p.name << ' ' << tiempo_actual << '\n';
        } else {
            tiempo_actual += q;
            p.time -= q;
            cola.push(p);
        }
    }

    return 0;
}