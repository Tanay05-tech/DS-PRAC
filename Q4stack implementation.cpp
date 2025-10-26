// Tanay
// csc/24/52
// practical 4
// to implement stack as an ADT


#include <iostream>

class Stack {
private:
    int* arr;
    int capacity;
    int top;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Stack() {
        capacity = 2;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (top + 1 == capacity) {
            resize();
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);  // Will trigger resize
    std::cout << "Top: " << s.peek() << "\n"; // 15
    std::cout << "Pop: " << s.pop() << "\n";  // 15
    std::cout << "Pop: " << s.pop() << "\n";  // 10
    std::cout << "Pop: " << s.pop() << "\n";  // 5
    std::cout << "Pop: " << s.pop() << "\n";  // Underflow
    return 0;
}
