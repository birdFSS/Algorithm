#include <iostream>
class Solution {
public:
    bool isNumeric(char* string)
    {
        char* p = string;
        char* pe = string;
        while('e' != *pe && 'E' != *pe && '\0' != *pe)
        {
            ++pe;

        }

        if('+' == *p || '-' == *p)
        {
            ++p;

        }
        if(!isNumberNoChar(p, pe))
        {
            return false;

        }

        if('\0'  == *pe)
        {
            return true;

        }

        p = pe;
        while(*p != '\0')
        {
            ++p;

        }

        ++pe;
        if('+' == *pe || '-' == *pe)
        {
            ++pe;

        }

        if(!isNumberNoChar(pe, p, false))
        {
            return false;

        }

        return true;

    }

    bool isNumberNoChar(char* begin, char* end, bool HavePoint = true)
    {
        if('\0' == *begin || nullptr == begin || nullptr == end)
        {
            return false;

        }

        bool flag = true;
        while(begin != end)
        {
            if('.' == *begin)
            {
                if(HavePoint)
                {
                    HavePoint = false;

                }else{
                    flag = false;
                    break;

                }

            }else if(!(*begin >= '0' && *begin <= '9'))
            {
                flag = false;
                break;

            }
            ++begin;

        }
        return flag;

    }

};

int main()
{
    char num[10] = "+100";
    num[4] = '\0';
    Solution s;
    cout << s.isNumeric(num) << endl;
    return 0;
}

