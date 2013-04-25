#include <iostream>
#include "StringHelper.h"

using namespace std;

#define P(x) cout << x << endl
#define E(x) cerr << x << endl

void splitTest()
{
	string str_list = "a,b,c!.d!.e!.f";
	P("target string[" << str_list << "]");
	vector<string> vec_str;
	P("split \",\"");
	if (false == splitStringList(str_list, ",", vec_str))
	{
		E("NG");
		return;
	}
	P("result");
	for (auto it = vec_str.begin();it != vec_str.end();++it)
	{
		P("\t" << *it);
	}
	P("");
	vec_str.clear();
	P("split \"!.\"");
	if (false == splitStringList(str_list, "!.", vec_str))
	{
		E("NG");
		return;
	}
	P("result");
	for (auto it = vec_str.begin();it != vec_str.end();++it)
	{
		P("\t" << *it);
	}
}

int main()
{
	splitTest();
	return 0;
}
