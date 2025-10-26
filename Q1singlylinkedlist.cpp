// Tanay
// csc/24/52
// practical 1
// to implement singly linked list as an ADT

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    // Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Insert at i-th position (1-based)
    void insertAtPosition(int pos, int x) {
        if (pos == 1) {
            insertAtBeginning(x);
            return;
        }
        Node* newNode = new Node(x);
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove from beginning
    void removeFromBeginning() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove from i-th position
    void removeFromPosition(int pos) {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }
        if (pos == 1) {
            removeFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range!\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search element
    Node* search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == x)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtPosition(2, 7);
    list.display();

    list.removeFromPosition(2);
    list.display();

    Node* found = list.search(10);
    if (found) cout << "Element found: " << found->data << endl;
    else cout << "Element not found\n";

    return 0;
}
