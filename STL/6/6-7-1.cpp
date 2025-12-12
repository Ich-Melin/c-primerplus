#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

template <class T>
struct display{
    void operator() (const T& x)const
    {
        cout << x << " ";
    }
};

struct even {
    bool operator() (int x) const
    { return x%2 ? false: true;}
};

class even_by_two {
public:
    int operator() () const
    { return _x += 2; }
private:
    static int _x;
};

int even_by_two::_x = 0;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,6,6,7,8};
    vector<int> iv(ia,ia+sizeof(ia)/sizeof(int));

    //找出iv之中相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(),iv.end()) << endl; //6
    cout << *adjacent_find(iv.begin(),iv.end(),equal_to<int>()) << endl;

    //找出iv之中元素值为6的元素个数
    cout << count(iv.begin(),iv.end(),6) << endl; //3

    //找出iv中小于7的元素个数
    cout << count_if(iv.begin(),iv.end(),bind2nd(less<int>(),7)) << endl; //9
    
    //找出iv中元素值为4的第一个元素所在的位置的值
    cout << *find(iv.begin(),iv.end(),4) << endl; //4

    //找出iv中大于2的第一个元素的所在位置的值
    cout << *find_if(iv.begin(),iv.end(),bind2nd(greater<int>(),2)) << endl; //3

    //找出iv中子序列iv2所出现的最后一个位置（再往后3个位置的值）
    vector<int> iv2(ia+6,ia+8);
    cout << *(find_end(iv.begin(),iv.end(),iv2.begin(),iv2.end()) + 3) << endl; //8

    //找出iv中子序列iv2所出现的第一个位置（再往后3个位置的值）
    cout << *(find_first_of(iv.begin(),iv.end(),iv2.begin(),iv2.end()) + 3) << endl; //7

    //迭代遍历整个iv区间，对每个元素实行display操作（不得改变元素内容
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl; //iv:0,1,2,3,4,5,6,6,6,7,8

    //以下错误：：generate的第三个参数（仿函数）本身不得有任何参数
    //generate（iv.begin(),iv.end(),bind2nd(plus<int>,3)); //error
    //以下，迭代遍历整个iv2区间，对每个元素施行even_by_two操作（得改变元素内容
    generate(iv2.begin(),iv2.end(),even_by_two());
    for_each(iv2.begin(),iv2.end(),display<int>());
    cout << endl; //iv2:2 4

    //迭代遍历指定区间（起点与长度），对每个元素施行even_by_two操作（得改变元素值）
    generate_n(iv.begin(),3,even_by_two());
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl; //iv:6 8 10 3 4 5 6 6 6 7 8
    
    //删除（但不删除）元素6，尾端可能有残余数据（可另一容器erase 函数去除）
    remove(iv.begin(),iv.end(),6);
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl; 

    //删除（但不删除）元素6，结果置于另一区间
    vector<int> iv3(12);
    remove_copy(iv.begin(),iv.end(),iv3.begin(),6);
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl; //iv3 8 10 3 4 5 7 8 7 0 0 0

    //删除（但不删除）小于6的元素。尾端可能有参与数据
    remove_if(iv.begin(),iv.end(),bind2nd(less<int>(),6));
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl; //

    //删除（但不删除）小于7得元素，结果置于另一区间
    remove_copy_if(iv.begin(),iv.end(),iv3.begin(),bind2nd(less<int>(),7));
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl;

    //将所有元素值6，改为3
    replace(iv.begin(),iv.end(),6,3);
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;

    //将所有元素值3，改为5，结果置于另一区间
    replace_copy(iv.begin(),iv.end(),iv3.begin(),3,5);
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl;

    //将所有小于5得元素，改为2
    replace_if(iv.begin(),iv.end(),bind2nd(less<int>(),5),2);
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;

    //将所有等于8得元素，改为9，结果置于另一区间
    replace_copy_if(iv.begin(),iv.end(),iv3.begin(),(equal_to<int>(),8),9);
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl;

    //逆向重排每一个元素
    reverse(iv.begin(),iv.end());
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;

    //逆向重排每一个元素，结果置于另一区间
    reverse_copy(iv.begin(),iv.end(),iv3.begin());
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl;

    //旋转（互换元素）【first，middle）和【middle，last）
    rotate(iv.begin(),iv.begin() + 4,iv.end());
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;

    //旋转（互换元素）【first，middle）和【middle，last）,结果置于另一区间
    rotate_copy(iv.begin(),iv.begin() + 5,iv.end(),iv3.begin());
    for_each(iv3.begin(),iv3.end(),display<int>());
    cout << endl;

    //查找某个子序列第一次出现地点
    int ia2[3] = {2,8};
    vector<int> iv4(ia2,ia2+2);
    cout << *search(iv.begin(),iv.end(),iv4.begin(),iv4.end()) << endl; //2

    //查找连续出现2个8得子序列起点
    cout << *search_n(iv.begin(),iv.end(),2,8) << endl; //8

    //查找连续出现3个小于8得子序列起点
    cout << *search_n(iv.begin(),iv.end(),3,8,less<int>()) << endl; // 7

    //将两个区间内得元素互换，第二个区间得元素个数不应小于第一区间得元素个数
    swap_ranges(iv4.begin(),iv4.end(),iv.begin());
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;
    for_each(iv4.begin(),iv4.end(),display<int>());
    cout << endl;

    //改变区间得值，全部减2
    transform(iv.begin(),iv.end(),iv.begin(),bind2nd(minus<int>(),2));
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;

    // 改变区间得值，令第二区间得值加到第一区间得对应元素身上
    transform(iv.begin(),iv.end(),iv.begin(),iv.end(),plus<int>());
    for_each(iv.begin(),iv.end(),display<int>());
    cout << endl;


    //********** */
    vector<int> iv5(ia,ia+sizeof(ia) / sizeof(int));
    vector<int> iv6(ia+4,ia+8);
    vector<int> iv7(15);
    for_each(iv5.begin(),iv5.end(),display<int>());
    cout << endl;
    for_each(iv6.begin(),iv6.end(),display<int>());
    cout << endl;

    cout << *max_element(iv5.begin(),iv5.end()) << endl; //8
    cout << *min_element(iv5.begin(),iv5.end()) << endl; //0

    //判断是否iv6内得元素都出现在iv5中
    //注意：两个序列都必须是 sorted ranges
    cout << includes(iv5.begin(),iv5.end(),iv6.begin(),iv6.end()) << endl; //1(true
    
    //将两个序列合并为一个序列
    //注意： 两个序列都必须是sorted ranges 获得得结果也是sorted
    merge(iv5.begin(),iv5.end(),iv6.begin(),iv6.end(),iv7.begin());
    for_each(iv7.begin(),iv7.end(),display<int>());
    cout << endl;

    //符合条件得元素放在容器前段，不符合得元素放在后端
    //不保证保留原相对次序
    partition(iv7.begin(),iv7.end(),even());
    for_each(iv7.begin(),iv7.end(),display<int>());
    cout << endl;

    //去除“连续而重复”得元素
    //注意：：获得得结果可能有残余数据
    unique(iv5.begin(),iv5.end());
    for_each(iv5.begin(),iv5.end(),display<int>());
    cout << endl;

    //去除 连续而重复得元素， 将结果置于另一处
    unique_copy(iv5.begin(),iv5.end(),iv7.begin());
    for_each(iv7.begin(),iv7.end(),display<int>());
    cout << endl;

}