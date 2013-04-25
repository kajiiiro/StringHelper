#pragma once

#include <string>
#include <vector>

namespace kajiiiro
{

class StringHelper
{
public:
	StringHelper();
	~StringHelper();
	StringHelper(const StringHelper &copy) = delete;
	StringHelper operator=(const StringHelper &copy) = delete;

public:
	// return copy string. so, do not change member variable

	// if split "a,b,,d" by ",", result is "a", "b", "", "d".
	std::vector<std::string> split(const std::string &strTarget, const std::string &strDelimiter) const;
	// if split "a,b,,d" by ",", result is "a"
	std::string getBefore(const std::string &strTarget, const std::string &strKey) const;
	// if split "a,b,,d" by ",", result is "b,,d"
	std::string getAfter(const std::string &strTarget, const std::string &strKey) const;
	
	std::string trimWhiteSpace(const std::string &strTarget) const;
	std::string getBetween(const std::string &strTarget, const std::string &strStartKey, const std::string &strEndKey) const;
	std::string getUpperCase(const std::string &strTarget) const;
	std::string getLowerCase(const std::string &strTarget) const;
	std::vector<std::string::size_type> getIndexList(const std::string &strTarget, const std::string &strKey) const;
	// if iCount <= 0, return string is empty
	std::string repeat(const int &iCount) const;

private:
	class impl;
	impl *pImpl;
}

}; // namespace kajiiiro

