#include <iostream>
using namespace std;

class Stack {
    int arr[100], top;

public:
    Stack() { top = -1; }

    // Push - O(1)
    void push(int x) {
        if (top >= 99) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop - O(1)
    void pop() {
        if (top < 0) {
            cout << "Underflow\n";
            return;
        }
        top--;
    }

    // Search - O(n)
    bool search(int key) {
        for (int i = 0; i <= top; i++)
            if (arr[i] == key) return true;
        return false;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Search 20: " << s.search(20) << endl;

    s.pop();
    s.display();

    return 0;
}