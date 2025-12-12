#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

template<typename T>
struct display
{
    void operator()(const T& x)const
    { cout << x << " ";}
};


int main()
{
    int ia[9] = {0,1,2,3,4,5,6,7,8};
    vector<int> iv1(ia,ia+5);
    vector<int> iv2(ia,ia+9);

    //判断两个区间的第一个不匹配点，其中返回两个迭代器，first第一个区间的不匹配点，second第二个区间的不匹配点
    cout << *(mismatch(iv1.begin(),iv1.end(),iv2.begin()).first) << endl;
    cout <<*(mismatch(iv1.begin(),iv1.end(),iv2.begin()).second) << endl;

    //两个序列在【first，last）区间相等，返回true;
    cout << equal(iv1.begin(),iv1.end(),iv2.begin()) << endl;
    cout << equal(iv1.begin(),iv1.end(),&ia[3]) << endl;
    cout << equal(iv1.begin(),iv1.end(),&ia[3],less<int>()) << endl;
    //全填9
    fill(iv1.begin(),iv1.end(),9);
    for_each(iv1.begin(),iv1.end(),display<int>());
    cout << endl;
    //从begin填3个7
    fill_n(iv1.begin(),3,7);
    for_each(iv1.begin(),iv1.end(),display<int>());
    cout << endl;
    vector<int>::iterator ite1 = iv1.begin();
    vector<int>::iterator ite2 = ite1;
    advance(ite2,3);
    //交换迭代器
    iter_swap(ite1,ite2);
    cout << *ite1 << " " << *ite2 << endl;
    for_each(iv1.begin(),iv1.end(),display<int>());
    cout << endl;
    //最大最小
    cout << max(*ite1,*ite2) << endl;
    cout << min(*ite1,*ite2) << endl;
    //交换数值
    swap(*iv1.begin(),*iv2.begin());
    for_each(iv1.begin(),iv1.end(),display<int>());
    cout << endl;
    for_each(iv2.begin(),iv2.end(),display<int>());
    cout << endl;
    string stra1[] = {"jamie", "jjHou", "jason"};
    string stra2[] = {"jamie", "jjhou", "jerry"};
    //默认小于 1
    cout << lexicographical_compare(stra1,stra1+2,stra2,stra2+2) << endl;
    //不大于 1
    cout << lexicographical_compare(stra1,stra1+2,stra2,stra2+2,greater<string>()) << endl;
}