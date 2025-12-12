#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <functional>

using namespace std;

int main()
{
    int ia[5] = {1,2,3,4,5};
    vector<int>iv (ia,ia+5);
    cout << accumulate(iv.begin(),iv.end(),0) << endl;

    cout << accumulate(iv.begin(),iv.end(),0,minus<int>()) << endl;
    cout << accumulate(iv.begin(),iv.end(),0,[](int a,int b){return a - b;}) << endl;

    cout << inner_product(iv.begin(),iv.end(),iv.begin(),10) << endl;
    cout << inner_product(iv.begin(),iv.end(),iv.begin(),10,minus<int>(),[](int a, int b){return a+ b;})  <<  endl;

    ostream_iterator<int> oite(cout, " ");
    partial_sum(iv.begin(),iv.end(),oite);
    cout << endl;
    partial_sum(iv.begin(),iv.end(),oite,minus<int>());
    cout << endl;
    adjacent_difference(iv.begin(),iv.end(),oite);
    cout << endl;
    adjacent_difference(iv.begin(),iv.end(),oite,plus<int>());
    cout << endl;
    //cout << power(10,3) << endl;
    int n = 3;
    iota(iv.begin(),iv.end(),n);
    for(auto a : iv)
        cout << a << " ";
    cout << endl;
     
}
