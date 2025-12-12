#include <iostream>
#include <unordered_set>
#include <cstring>
#include <set>
using namespace std;

struct eqstr
{
    bool operator() (const char* s1,const char* s2)const
        {
            return strcmp(s1,s2) == 0;
        }
};
void lookup(const unordered_set<const char*, hash<const char*>,eqstr>& set, const char* word)
{

}
int main()
{
    unordered_set<const char*,hash<const char*>,eqstr>set;
    set.insert("kiwi");
    set.insert("plum");
    lookup(set,"kiwi");
    lookup(set,"apple");
    
    unordered_set<const char*,hash<const char*>,eqstr>::iterator ite1 = set.begin();
    unordered_set<const char*,hash<const char*>,eqstr>::iterator ite2 = set.end();
    for(;ite1 != ite2;ite1++)
        cout << *ite1 << " ";
    cout << endl;
    
}