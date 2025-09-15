#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) { head = newNode; return; }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (head == nullptr) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) temp = temp->next;
        if (temp->next == nullptr) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) temp = temp->next;
        if (temp == nullptr) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (head == nullptr) return;
        if (head->data == key) { deleteFromBeginning(); return; }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) temp = temp->next;
        if (temp->next == nullptr) return;
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void search(int key) {
        Node* temp = head; int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) { cout << "Found at position " << pos << endl; return; }
            temp = temp->next; pos++;
        }
        cout << "Not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list; int choice, val, key;
    do {
        cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert before\n4.Insert after\n5.Delete from beginning\n6.Delete from end\n7.Delete node\n8.Search\n9.Display\n0.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; list.insertAtBeginning(val); break;
            case 2: cin >> val; list.insertAtEnd(val); break;
            case 3: cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteFromBeginning(); break;
            case 6: list.deleteFromEnd(); break;
            case 7: cin >> key; list.deleteNode(key); break;
            case 8: cin >> key; list.search(key); break;
            case 9: list.display(); break;
        }
    } while (choice != 0);
}
