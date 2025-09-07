#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        if (ch == ' ') continue; // ignore spaces

        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << "Output: ";
    firstNonRepeating(s);

    return 0;
}
