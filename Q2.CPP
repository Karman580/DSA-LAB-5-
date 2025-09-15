#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) { head = newNode; return; }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void countAndDeleteOccurrences(int key) {
        int count = 0;
        while (head != nullptr && head->data == key) {
            Node* temp = head; head = head->next; delete temp; count++;
        }
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == key) {
                Node* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode; count++;
            } else temp = temp->next;
        }
        cout << "Count: " << count << endl;
        display();
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1); list.insert(2); list.insert(1); list.insert(2); list.insert(1); list.insert(3); list.insert(1);
    int key = 1;
    list.countAndDeleteOccurrences(key);
}
