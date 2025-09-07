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

    int findMiddle() {
        if (!head) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main() {
    SinglyList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);

    cout << "Middle: " << l.findMiddle() << endl;

    return 0;
}
