#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> ide(20,9);
    cout << "size = " << ide.size() << endl;

    for(int i = 0; i < ide.size(); i++)
        ide[i] = i;
    
    for(int i = 0; i < ide.size(); i++)
        cout << ide[i] << " ";
    cout << endl;

    for(int i = 0; i < 3; i++)
        ide.push_back(i);
    for(int i = 0; i < ide.size(); i++)
        cout << ide[i] << " ";
    cout << endl;
    cout << "size = " << ide.size() << endl;
    
    ide.push_back(3);
    for(int i = 0;i < ide.size(); i++)
        cout << ide[i] << " ";
    cout << endl;
    cout << "size = " << ide.size() << endl;

    ide.push_front(99);
    for(int i = 0; i < ide.size(); i++)
        cout << ide[i] << " ";
    cout << endl;
    cout << "size = " << ide.size() << endl;

    deque<int>::iterator itr;
    itr = find(ide.begin(),ide.end(),99);
    cout << *itr << endl;
   // cout << *(itr.cur) << endl;
}