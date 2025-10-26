
// Tanay
// CSC/24/52
// Practical 2
// Implement Doubly Linked List as an ADT

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }

    // Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (head != NULL)
            head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Remove from beginning
    void removeFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    // Remove from end
    void removeFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
    }

    // Display list
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(20);
    dll.insertAtEnd(25);

    dll.display();

    dll.removeFromBeginning();
    dll.display();

    dll.removeFromEnd();
    dll.display();

    return 0;
}
