#include <iostream>
using namespace std;

struct Node {
    int BookID;
    char Title[50];
    char Author[50];
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    void cText(char dest[], const char src[]) {
        int i = 0;
        while (src[i] != '\0' && i < 49) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    DoublyLinkedList() {
        head = 0;
        tail = 0;
    }

    Node* createNode(int id, const char title[], const char author[]) {
        Node* n = new Node;
        n->BookID = id;
        cText(n->Title, title);
        cText(n->Author, author);
        n->next = 0;
        n->prev = 0;
        return n;
    }

    void addAtBeginning(int id, const char title[], const char author[]) {
        Node* n = createNode(id, title, author);
        if (head == 0) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addAtEnd(int id, const char title[], const char author[]) {
        Node* n = createNode(id, title, author);
        if (tail == 0) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void addAtPosition(int pos, int id, const char title[], const char author[]) {
        if (pos <= 1 || head == 0) {
            addAtBeginning(id, title, author);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != 0; i++)
            temp = temp->next;

        if (temp->next == 0) {
            addAtEnd(id, title, author);
            return;
        }

        Node* n = createNode(id, title, author);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }

    void deleteByID(int id) {
        if (head == 0) return;

        Node* temp = head;
        while (temp != 0 && temp->BookID != id)
            temp = temp->next;

        if (temp == 0) return;

        if (temp == head)
            head = head->next;
        if (temp == tail)
            tail = tail->prev;
        if (temp->prev != 0)
            temp->prev->next = temp->next;
        if (temp->next != 0)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != 0) {
            cout << "ID  " << temp->BookID << "  Title " << temp->Title << "  Author  " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp != 0) {
            cout << "ID  " << temp->BookID << "  Title " << temp->Title << "  Author  " << temp->Author << endl;
            temp = temp->prev;
        }
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head != 0) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.addAtEnd(101, "Night Hawk", "Ali");
    list.addAtEnd(102, "Learn c++", "Ahmed");
    list.addAtBeginning(100, "Pakistan History", "Javed");
    list.addAtPosition(2, 105, "Gujjar", "Ali");

    cout << "Books in Order" << endl;
    list.displayForward();

    cout << "\nBooks in Reverse Order" << endl;
    list.displayBackward();

    cout << "\nAfter Deleting Book ID 102" << endl;
    list.deleteByID(102);
    list.displayForward();

    return 0;
}
