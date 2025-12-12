#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    queue<int,list<int>> iqueue;
    iqueue.push(1);
    iqueue.push(2);
    iqueue.push(3);
    cout << iqueue.back() << endl;
    cout << iqueue.size() << endl;
    cout << iqueue.front() << endl;
    iqueue.pop(); cout << iqueue.front() << endl;
    cout << iqueue.size() << endl;

}