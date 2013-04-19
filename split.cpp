#include "split.h"

bool splitStringList(const std::string& str_list, const std::string& str_delimiter, std::vector<std::string>& vec_str)
{
    if (("" == str_list) || ("" == str_delimiter)) return false;
    std::string::size_type si_current = 0;
    std::string::size_type si_found   = 0;
    while (std::string::npos != (si_found = str_list.find(str_delimiter, si_current)))
    {
        vec_str.push_back(str_list.substr(si_current, si_found - si_current));
        si_current = si_found + str_delimiter.size();
    }
    vec_str.push_back(str_list.substr(si_current));
    return true;
}
