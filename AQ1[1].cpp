
/*Q1. Menu driven program for queue operations:
enqueue, dequeue, isEmpty, isFull, display, peek
*/

#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity, count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
        cout << x << " inserted into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << arr[front] << " removed from queue.\n";
        front = (front + 1) % capacity;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, choice, value;
    cout << "Enter size of queue: ";
    cin >> n;

    Queue q(n);

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 4:
            cout << (q.isFull() ? "Queue is Full\n" : "Queue is Not Full\n");
            break;
        case 5:
            q.display();
            break;
        case 6:
            q.peek();
            break;
        case 7:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}
