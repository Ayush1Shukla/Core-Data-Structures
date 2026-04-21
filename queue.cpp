#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue - O(1)
    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    // Dequeue - O(1)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    // Search - O(n)
    bool search(int key) {
        for (int i = front; i <= rear; i++) {
            if (arr[i] == key) return true;
        }
        return false;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Search 20: " << q.search(20) << endl;

    q.dequeue();
    cout << "After dequeue: ";
    q.display();

    return 0;
}