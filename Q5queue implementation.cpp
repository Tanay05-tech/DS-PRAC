// Tanay
// csc/24/52
// practical 5
// to implement queue as an ADT


#include <iostream>

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        
        // Copy elements to new array in correct order
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }
        
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    Queue() {
        capacity = 2;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (size == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);  // resize triggered here
    std::cout << "Front: " << q.getFront() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 2
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 3
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // Underflow
    return 0;
}
