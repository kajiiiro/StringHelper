#include <iostream>
#include "split.h"

using namespace std;

#define P(x) cout << x << endl
#define E(x) cerr << x << endl

int main()
{
    string str_list = "a,b,c!.d!.e!.f";
    vector<string> vec_str;
    if (false == splitStringList(str_list, ",", vec_str))
    {
        E("NG");
        return 1;
    }
    for (auto it = vec_str.begin();it != vec_str.end();++it)
    {
        P(*it);
    }
    P("");
    vec_str.clear();
    if (false == splitStringList(str_list, "!.", vec_str))
    {
        E("NG");
        return 1;
    }
    for (auto it = vec_str.begin();it != vec_str.end();++it)
    {
        P(*it);
    }
    return 0;
}
