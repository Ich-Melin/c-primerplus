#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

template<class T>
struct display
{
    void operator()(const T& x)
    {
        cout << x << " ";
    }
};

int main()
{
    int ia1[6] = {1,3,5,7,9,11};
    int ia2[7] = {1,1,2,3,5,8,13};

    multiset<int> s1(ia1,ia1+6);
    multiset<int> s2(ia2,ia2+7);

    for_each(s1.begin(),s1.end(),display<int>());
    cout << endl;
    for_each(s2.begin(),s2.end(),display<int>());
    cout  << endl;

    multiset<int>::iterator first1 = s1.begin();
    multiset<int>::iterator last1 = s1.end();
    multiset<int>::iterator first2 = s2.begin();
    multiset<int>::iterator last2 = s2.end();

    cout << "Union of s1 and s2: ";
    set_union(first1,last1,first2,last2,ostream_iterator<int>(cout," "));
    cout << endl;

    first1 = s1.begin();
    first2 = s2.begin();
    cout << "Intersection of s1 and s2 : ";
    set_intersection(first1,last1,first2,last2,ostream_iterator<int>(cout, " "));
    cout << endl;
    
    first1 = s1.begin();
    first2 = s2.begin();
    cout << "Difference of s1 and s2 (s1-s2): ";
    set_difference(first1,last1,first2,last2,ostream_iterator<int>(cout, " "));
    cout << endl;

    first1 = s1.begin();
    first2 = s2.begin();
    cout << "Symmetric difference of s1 and s2: ";
    set_symmetric_difference(first1,last1,first2,last2,ostream_iterator<int>(cout," "));
    cout << endl;

    first1 = s2.begin();
    first1 = s1.begin();
    last1 = s2.end();
    last2 = s1.end();
    cout << "Difference of s2 and s1 (s2-s1): ";
    set_difference(first1,last1,first2,last2,ostream_iterator<int>(cout, " "));
    cout << endl;
}
