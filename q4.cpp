#include <iostream>
using namespace std;

struct Node {
    int customerID;
    char name[50];
    int tickets;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

    void copyText(char dest[], const char src[]) {
        int i = 0;
        while (src[i] != '\0' && i < 49) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    Node* createNode(int id, const char n[], int t) {
        Node* temp = new Node;
        temp->customerID = id;
        copyText(temp->name, n);
        temp->tickets = t;
        temp->next = 0;
        return temp;
    }

    void enqueue(int id, const char n[], int t) {
        Node* temp = createNode(id, n, t);
        if (rear == 0) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Customer " << n << " added to queue\n";
    }

    void dequeue() {
        if (front == 0) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Serving Customer ID " << temp->customerID << " Name " << temp->name << endl;
        front = front->next;
        if (front == 0)
            rear = 0;
        delete temp;
    }

    void displayQueue() {
        if (front == 0) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "\nCurrent Queue \n";
        while (temp != 0) {
            cout << "ID  " << temp->customerID << "  Name  " << temp->name
                 << "  Tickets  " << temp->tickets << endl;
            temp = temp->next;
        }
    }

    ~Queue() {
        Node* temp;
        while (front != 0) {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Ahmed", 4);
    q.enqueue(3, "Sufiyan", 1);

    q.displayQueue();

    cout << "\nAfter one customer\n";
    q.dequeue();

    q.displayQueue();

    cout << "\nUpdated Again customer:\n";
    q.dequeue();

    q.displayQueue();

    return 0;
}
