// Tanay
// csc/24/52
// practical 3
// to implement circular linked list as an ADT


#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr; 
    }
};

class CircularLinkedList {
private:
    Node* head; 

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl; // Indicate the circular nature
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* oldHead = head;
        head = head->next;
        temp->next = head;
        delete oldHead;
    }

    ~CircularLinkedList() {
        if (head == nullptr) {
            return;
        }
        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
        head = nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Circular Linked List: ";
    cll.display();

    cll.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    cll.display();

    return 0;
}