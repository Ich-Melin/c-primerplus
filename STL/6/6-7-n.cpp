#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

struct even
{
    bool operator()(int x) const
    { return x % 2? false: true;}
};

int main()
{
    int ia[] = {12,17,20,22,23,30,33,40};
    vector<int>iv (ia,ia+sizeof(ia)/sizeof(int));

    cout << *lower_bound(iv.begin(),iv.end(),21) << endl; //22
    cout << *upper_bound(iv.begin(),iv.end(),21) << endl; //22
    cout << *lower_bound(iv.begin(),iv.end(),22) << endl; //22
    cout << *upper_bound(iv.begin(),iv.end(),22) << endl; //23

    //面对有序区间，可以二分查找法寻找某个元素
    cout << binary_search(iv.begin(),iv.end(),33) << endl; //true 1
    cout << binary_search(iv.begin(),iv.end(),34) << endl; //0 false

    //下一个排列组合
    next_permutation(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    //12,17,20,22,23,30,33,40
    
    //随机重排
    random_shuffle(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout," "));
    cout <<endl;
    //33 12 30 20 17 23 22 40

    //将iv.begin() + 4 - iv.begin()个元素排序，
    //放进[iv.begin(),iv.begin) + 4]区间内，剩余元素不保持维持原相对顺序
    partial_sort(iv.begin(),iv.begin()+4,iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    //12 17 20 22 33 30 23 40

    //排序（缺省为递增排序）
    sort(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    // 12 17 20 22 23 30 33 40

    //排序（指定为递减排序）
    sort(iv.begin(),iv.end(),greater<int>());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    //40 33 30 23 22 20 17 12

    //在iv尾端附加新元素，使成为40 33 30 23 22 20 17 12 22 30 17
    iv.push_back(22);
    iv.push_back(30);
    iv.push_back(17);

    //排序、并保持“原相对位置”
    stable_sort(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    //12 17 17 20 22 22 23 30 30 33 40

    //面对一个有序区间，找出其中的一个子区间，其中每个元素都与其特定元素值相同：
    //返回该子区间的头尾迭代器
    //如果没有这样的子区间，返回的头尾迭代器均指向该特定元素可插入
    //（并保持排序）的地点
    pair<vector<int>::iterator, vector<int>::iterator> pairIte;
    pairIte = equal_range(iv.begin(),iv.end(),22);
    cout << *(pairIte.first) << endl; //22 lower_bound
    cout << *(pairIte.second) << endl; //23 upper_bound

    pairIte = equal_range(iv.begin(),iv.end(),25);
    cout << *(pairIte.first) << endl; //30 lower_bound
    cout << *(pairIte.second) << endl; //30 upper_bound

    random_shuffle(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl; //22 30 30 17 33 40 17 23 22 12 20

    //将小于*（iv.begin() + 5)本例为40的元素置于该元素之左
    //其余置于该元素之右，不保证维持原有的相对位置
    nth_element(iv.begin(),iv.begin() + 5, iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl; //20 12 22 17 17 22 23 30 30 33 40

    //将大于*（iv.begin() + 5)本例为22的元素置于该元素之左
    //其余置于该元素之右，不保证维持原有的相对位置
    nth_element(iv.begin(),iv.begin() + 5,iv.end(),greater<int>());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout, " "));
    cout << endl; // 40 33 30 30 23 22 17 17 22 12 20

    //以“是否符合even（）条件”为依据，将符合者置于左段，不符合者置于右段
    //保证维持原有的相对位置。如不需要“维持原有的相对位置”，可改用partition（
    stable_partition(iv.begin(),iv.end(),even());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout , " "));
    cout << endl; // 40 30 30 22 22 12 20 33 23 17 17
    
}
