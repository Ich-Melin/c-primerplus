#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

struct eqstr
{
    bool operator() (const char* s1, const char* s2) const{
        return strcmp(s1,s2) == 0;
    }
};

int main()
{
    unordered_map<const char*,int,hash<const char*>,eqstr> days;
    days["jan"] = 31;
    days["feb"] = 28;
    days["mar"] = 30;

    cout << "jan ->" << days["jan"] << endl;


    unordered_map<const char*,int,hash<const char*>,eqstr>::iterator ite1 = days.begin();
    unordered_map<const char*,int,hash<const char*>,eqstr>::iterator ite2 = days.end();
    for(;ite1 != ite2; ite1++)
    {
        cout << ite1->first << " ";
    }
    cout << endl;
}
