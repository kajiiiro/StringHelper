#include <iostream>
#include "StringHelper.h"

using namespace std;

#define P(x) cout << x << endl
#define E(x) cerr << x << endl

void splitTest()
{
	kajiiiro::StringHelper helper;
	string strTarget = "  {a,B},,d  ";
	vector<string> vecStr = helper.split(strTarget, ",");
	P("target [" << strTarget << "]");
	P("split by \",\", result");
	for (auto it = vecStr.begin();it != vecStr.end();++it)
	{
		P("\t" << "[" << *it << "]");
	}
	P("get before \",,\", result");
	P("\t" << "[" << helper.getBefore(strTarget, ",,") << "]");
	P("get after \",,\", result");
	P("\t" << "[" << helper.getAfter(strTarget, ",,") << "]");
	P("trim white space, result");
	P("\t" << "[" << helper.trimWhiteSpace(strTarget) << "]");
	P("get between \"{}\", result");
	P("\t" << "[" << helper.getBetween(strTarget, "{", "}") << "]");
	P("get upper case, result");
	P("\t" << "[" << helper.getUpperCase(strTarget) << "]");
	P("get lower case, result");
	P("\t" << "[" << helper.getLowerCase(strTarget) << "]");
	vector<string::size_type> vecSize = helper.getIndexList(strTarget, ",");
	P("get index list by \",\", result");
	for (auto it = vecSize.begin();it != vecSize.end();++it)
	{
		P("\t" << "[" << *it << "]");
	}
	P("repeat 3, result");
	P("\t" << "[" << helper.repeat(strTarget, 3) << "]");
}

int main()
{
	splitTest();
	return 0;
}

