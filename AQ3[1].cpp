/*
Program to interleave the first half of the queue with the second half.
Example:
Input:  4 7 11 20 5 9
Output: 4 20 7 5 11 9
*/

#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements!\n";
        return;
    }

    queue<int> firstHalf;
    int half = n / 2;

    // store first half in another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // interleave elements
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    interleave(q);

    cout << "\nInterleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
