#include <cctype>
#include <algorithm>
#include "StringHelper.h"

using namespace std;

namespace kajiiiro
{

class StringHelper::impl
{

};

StringHelper::StringHelper() : pImpl(new impl())
{

}

StringHelper::~StringHelper()
{
	delete pImpl;
}

vector<string> StringHelper::split(const string &strTarget, const string &strDelimiter) const
{
	if (("" == strTarget) || ("" == strDelimiter)) return vector<string>();
	string strBefore = this->getBefore(strTarget, strDelimiter);
	string strAfter = this->getAfter(strTarget, strDelimiter);
	vector<string> vecResult;
	while (false == strAfter.empty())
	{
		vecResult.push_back(strBefore);
		// これ以上分割できない場合は最後に分割したものを格納してループ終了
		if (this->getAfter(strAfter, strDelimiter).empty())
		{
			vecResult.push_back(strAfter);
			break;
		}
		// まだ分割できる場合は新しいものを設定して続行
		strBefore = this->getBefore(strAfter, strDelimiter);
		strAfter = this->getAfter(strAfter, strDelimiter);
	}
	return vecResult;
}

string StringHelper::getBefore(const string &strTarget, const string &strKey) const
{
	if (("" == strTarget) || ("" == strKey)) return string();
	std::string::size_type siIndex = strTarget.find(strKey);
	if (std::string::npos == siIndex)
		return std::string();
	return strTarget.substr(0, siIndex);
}

string StringHelper::getAfter(const string &strTarget, const string &strKey) const
{
	if (("" == strTarget) || ("" == strKey)) return string();
	std::string::size_type siIndex = strTarget.find(strKey);
	if (std::string::npos == siIndex)
		return std::string();
	return strTarget.substr(siIndex + strKey.size());
}

string StringHelper::trimWhiteSpace(const string &strTarget) const
{
	if ("" == strTarget) return string();
	std::string::size_type siStart;
	for (std::string::size_type i = 0;i < strTarget.size();++i)
	{
		if (' ' != strTarget.at(i))
		{
			siStart = i;
			break;
		}
	}
	std::string::size_type siEnd;
	for (std::string::size_type i = strTarget.size() - 1;0 <= i;--i)
	{
		if (' ' != strTarget.at(i))
		{
			siEnd = i;
			break;
		}
	}
	return strTarget.substr(siStart, siEnd - siStart + 1);
}

string StringHelper::getBetween(const string &strTarget, const string &strStartKey, const string &strEndKey) const
{
	return this->getBefore(this->getAfter(strTarget, strStartKey), strEndKey);
}

class ToUpper
{
public:
	char operator()(char c) {return toupper(c);}
};

class ToLower
{
public:
	char operator()(char c) {return tolower(c);}
};

string StringHelper::getUpperCase(const string &strTarget) const
{
	string strTmp = strTarget;
	transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ToUpper());
	return strTmp;
}

string StringHelper::getLowerCase(const string &strTarget) const
{
	string strTmp = strTarget;
	transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ToLower());
	return strTmp;
}

vector<string::size_type> StringHelper::getIndexList(const string &strTarget, const string &strKey) const
{
	if (("" == strTarget) || ("" == strKey)) return vector<string::size_type>();
	std::string::size_type siCurrent = 0;
	std::string::size_type siFound   = 0;
	vector<string::size_type> vecIndex;
	while (std::string::npos != (siFound = strTarget.find(strKey, siCurrent)))
	{
		vecIndex.push_back(siFound);
		siCurrent = siFound + strKey.size();
	}
	return vecIndex;
}

string StringHelper::repeat(const std::string &strTarget, const int &iCount) const
{
	if (iCount <= 0) return string();
	string strTmp;
	for (int i = 0;i < iCount;++i)
		strTmp += strTarget;
	return strTmp;
}

}; // namespace kajiiiro

