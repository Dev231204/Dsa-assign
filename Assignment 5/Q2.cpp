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

    int deleteKeyAll(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* t = head;
        while (t && t->next) {
            if (t->next->data == key) {
                Node* temp = t->next;
                t->next = temp->next;
                delete temp;
                count++;
            } else {
                t = t->next;
            }
        }
        return count;
    }

    void display() {
        if (!head) { cout << "Empty List"; return; }
        Node* t = head;
        while (t) {
            cout << t->data;
            if (t->next) cout << "->";
            t = t->next;
        }
    }
};

int main() {
    SinglyList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(3);
    l.insertEnd(1);

    int key = 1;
    int count = l.deleteKeyAll(key);

    cout << "Count: " << count << " , Updated Linked List: ";
    l.display();
    cout << endl;

    return 0;
}
