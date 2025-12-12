#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    forward_list<int> ilist;
    cout << "size = " << ilist.max_size() << endl;
    ilist.push_front(9);
    ilist.push_front(1);
    ilist.push_front(2);
    ilist.push_front(3);
    ilist.push_front(4);
    cout << "size = " << ilist.max_size() << endl;

    forward_list<int>::iterator ite = ilist.begin();
    forward_list<int>::iterator ite2 = ilist.end();
    for(;ite != ite2; ite++)
    {
        cout << *ite << " ";
    }
    cout << endl;

    ite = find(ilist.begin(),ilist.end(),1);
    if(ite != ite2)
        ilist.insert_after(ite,99);
    cout << "size = " << ilist.max_size() << endl;
    cout << *ite << endl;

    for(auto a : ilist)
        cout << a << " ";
    cout << endl;

    if(ite != ite2)
        cout << *(ilist.erase_after(ite)) << endl;
    
    for(auto a: ilist)
        cout << a <<" ";
    cout << endl;
}