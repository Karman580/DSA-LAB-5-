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

    void findMiddle() {
        Node* slow = head; Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; fast = fast->next->next;
        }
        cout << "Middle: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1); list.insert(2); list.insert(3); list.insert(4); list.insert(5);
    list.findMiddle();
}
