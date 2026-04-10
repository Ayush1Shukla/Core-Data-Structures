#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head = NULL;

    // Insert at beginning - O(1)
    void insert(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // Delete a value - O(n)
    void remove(int val) {
        Node *temp = head, *prev = NULL;

        while (temp != NULL && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;
    }

    // Search - O(n)
    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

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
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display();

    cout << "Search 20: " << list.search(20) << endl;

    list.remove(20);
    list.display();

    return 0;
}