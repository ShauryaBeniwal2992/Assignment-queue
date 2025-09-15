/*
Q2. Menu-driven program for Circular Queue operations:
enqueue, dequeue, isEmpty, isFull, display, peek
*/

#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int start, end, cap, count;

public:
    CircularQueue(int n) {
        cap = n;
        arr = new int[cap];
        start = 0;
        end = -1;
        count = 0;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == cap);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert!\n";
            return;
        }
        end = (end + 1) % cap;
        arr[end] = x;
        count++;
        cout << x << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to remove!\n";
            return;
        }
        cout << arr[start] << " removed from queue.\n";
        start = (start + 1) % cap;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << arr[start] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(start + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);

    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cout << (cq.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n");
            break;
        case 4:
            cout << (cq.isFull() ? "Queue is Full\n" : "Queue is not Full\n");
            break;
        case 5:
            cq.display();
            break;
        case 6:
            cq.peek();
            break;
        case 7:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}
