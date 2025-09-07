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

    void insertBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    bool insertBefore(int key, int x) {
        if (!head) return false;
        if (head->data == key) { insertBeginning(x); return true; }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (!t->next) return false;
        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
        return true;
    }

    bool insertAfter(int key, int x) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return false;
        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
        return true;
    }

    bool deleteBeginning() {
        if (!head) return false;
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }

    bool deleteEnd() {
        if (!head) return false;
        if (!head->next) { delete head; head = nullptr; return true; }
        Node* t = head;
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = nullptr;
        return true;
    }

    bool deleteValue(int key) {
        if (!head) return false;
        if (head->data == key) { return deleteBeginning(); }
        Node* t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (!t->next) return false;
        Node* d = t->next;
        t->next = d->next;
        delete d;
        return true;
    }

    int search(int key) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == key) return pos;
            t = t->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyList l;
    int ch;
    do {
        cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert BEFORE value\n4.Insert AFTER value\n5.Delete from beginning\n6.Delete from end\n7.Delete specific value\n8.Search value\n9.Display\n0.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            int x; cout << "Value: "; cin >> x; l.insertBeginning(x);
        } else if (ch == 2) {
            int x; cout << "Value: "; cin >> x; l.insertEnd(x);
        } else if (ch == 3) {
            int key,x; cout << "Insert value: "; cin >> x; cout << "Before value: "; cin >> key;
            if (!l.insertBefore(key,x)) cout << "Key not found\n";
        } else if (ch == 4) {
            int key,x; cout << "Insert value: "; cin >> x; cout << "After value: "; cin >> key;
            if (!l.insertAfter(key,x)) cout << "Key not found\n";
        } else if (ch == 5) {
            if (!l.deleteBeginning()) cout << "List empty\n";
        } else if (ch == 6) {
            if (!l.deleteEnd()) cout << "List empty\n";
        } else if (ch == 7) {
            int key; cout << "Delete value: "; cin >> key;
            if (!l.deleteValue(key)) cout << "Value not found\n";
        } else if (ch == 8) {
            int key; cout << "Search value: "; cin >> key;
            int p = l.search(key);
            if (p == -1) cout << "Not found\n"; else cout << "Position: " << p << "\n";
        } else if (ch == 9) {
            l.display();
        } else if (ch == 0) {
            cout << "Bye\n";
        } else {
            cout << "Invalid\n";
        }
    } while (ch != 0);
    return 0;
}
