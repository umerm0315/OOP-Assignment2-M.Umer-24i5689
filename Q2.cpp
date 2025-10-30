#include <iostream>
using namespace std;

class Feature {
protected:
    char Name[50];
public:
    Feature(const char name[]) {
        int i = 0;
        while (name[i] != '\0' && i < 49) {
            Name[i] = name[i];
            i++;
        }
        Name[i] = '\0';
    }
    virtual void analyze() = 0;
    virtual Feature* clone() const = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(const char name[]) : Feature(name) {}
    void analyze() override {
        cout << "Land Feature: " << Name << " detected." << endl;
    }
    Feature* clone() const override {
        return new LandFeature(*this);
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(const char name[]) : Feature(name) {}
    void analyze() override {
        cout << "Water Feature: " << Name << " detected." << endl;
    }
    Feature* clone() const override {
        return new WaterFeature(*this);
    }
};

struct Node {
    int FeatureID;
    Feature* f;
    Node* next;
    Node(int id, Feature* feature) {
        FeatureID = id;
        f = feature;
        next = 0;
    }
    ~Node() {
        delete f;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = 0;
    }
    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);
        if (head == 0) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != 0)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void deleteByID(int featureID) {
        if (head == 0)
            return;
        if (head->FeatureID == featureID) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next != 0 && temp->next->FeatureID != featureID)
            temp = temp->next;
        if (temp->next != 0) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
    void displayAll() {
        Node* temp = head;
        while (temp != 0) {
            cout << "Feature ID: " << temp->FeatureID << " -> ";
            temp->f->analyze();
            temp = temp->next;
        }
    }
    void reverseList() {
        Node* prev = 0;
        Node* curr = head;
        Node* next = 0;
        while (curr != 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    ~SinglyLinkedList() {
        Node* temp;
        while (head != 0) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Lake"));
    cout << " Before editingList " << endl;
    list.displayAll();
    cout << "\n After Deleting Feature ID 2 " << endl;
    list.deleteByID(2);
    list.displayAll();
    cout << "\nAfter Reversing  List" << endl;
    list.reverseList();
    list.displayAll();
    return 0;
}
