#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <cmath>
/*
 *=== STL Showcase Program ===
Project: Compiler Dev
Sorted vector: 1 2 3 5 8 
List contents: Zoe Alice Bob Charlie 
Deque: 0 1 2 3 4 
Alice's age from map: 30
Set contents (no duplicates): 1 2 3 5 
Capital of France: Paris
Unordered set: 3 2 1 
Stack top: d
Queue front: 10, back: 20
Max in priority queue: 5
3 found in vector at index 2
Sum of vector: 19
Number of 3s in vector: 1
Pair: (1, one)
Tuple: (42, Answer, 3.14)
Sqrt of 25: 5.00
After swap: a = 10, b = 5
avaneeth@avaneeth-virtual-
 * */
using namespace std;

int main() {
    // Basic I/O and formatting
    cout << fixed << setprecision(2);
    cout << "=== STL Showcase Program ===\n";

    // string
    string name = "Compiler Dev";
    cout << "Project: " << name << endl;

    // vector
    vector<int> v = {5, 3, 8, 1, 2};
    sort(v.begin(), v.end());
    cout << "Sorted vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // list
    list<string> names = {"Alice", "Bob", "Charlie"};
    names.push_front("Zoe");
    cout << "List contents: ";
    for (auto& s : names) cout << s << " ";
    cout << endl;

    // deque
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);
    dq.push_back(4);
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // map
    map<string, int> age;
    age["Alice"] = 30;
    age["Bob"] = 25;
    cout << "Alice's age from map: " << age["Alice"] << endl;

    // set
    set<int> s = {5, 3, 1, 2, 3};
    cout << "Set contents (no duplicates): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // unordered_map
    unordered_map<string, string> capitals = {
        {"India", "New Delhi"},
        {"France", "Paris"}
    };
    cout << "Capital of France: " << capitals["France"] << endl;

    // unordered_set
    unordered_set<int> us = {1, 2, 2, 3};
    cout << "Unordered set: ";
    for (int x : us) cout << x << " ";
    cout << endl;

    // stack
    stack<char> st;
    for (char c : string("abcd")) st.push(c);
    cout << "Stack top: " << st.top() << endl;

    // queue
    queue<int> q;
    q.push(10); q.push(20);
    cout << "Queue front: " << q.front() << ", back: " << q.back() << endl;

    // priority_queue
    priority_queue<int> pq;
    pq.push(1); pq.push(5); pq.push(3);
    cout << "Max in priority queue: " << pq.top() << endl;

    // algorithm: find
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) cout << "3 found in vector at index " << distance(v.begin(), it) << endl;

    // algorithm: accumulate
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of vector: " << sum << endl;

    // algorithm: count
    int count3 = count(v.begin(), v.end(), 3);
    cout << "Number of 3s in vector: " << count3 << endl;

    // utility: pair
    pair<int, string> p = make_pair(1, "one");
    cout << "Pair: (" << p.first << ", " << p.second << ")\n";

    // utility: tuple
    tuple<int, string, double> t = make_tuple(42, "Answer", 3.14);
    cout << "Tuple: (" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")\n";

    // math
    double num = 25.0;
    cout << "Sqrt of 25: " << sqrt(num) << endl;

    // swap
    int a = 5, b = 10;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}

