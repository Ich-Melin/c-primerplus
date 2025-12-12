#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    ostream_iterator<int> outite(cout, " ");

    int ia[6] = {2,21,12,7,19,23};
    vector<int> iv(ia,ia+6);

    for_each(iv.begin(),iv.end(),compose1(bind2nd(multiplies<int>(),3),bind2nd(plus<int>(),2)));
}