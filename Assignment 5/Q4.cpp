#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class SinglyList {
    Node* head;
public:
    SinglyList() : head(nullptr) {}

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);

    cout << "Original List: ";
    l.display();

    l.reverse();

    cout << "Reversed List: ";
    l.display();

    return 0;
}
