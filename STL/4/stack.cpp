#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;
int main()
{
    stack<int,list<int>> istack;
    cout << istack.empty() << endl;
    istack.push(1);
    istack.push(3);
    istack.push(5);
    istack.push(7);

    cout << istack.size() << endl;
    cout << istack.top() << endl;

    istack.pop(); cout << istack.top() << endl;
    istack.emplace(5);
    cout <<  istack.size() << endl;
    cout << istack.empty() << endl;
    return 0;
}