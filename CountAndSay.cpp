/*
* @Author: HeQing
* @Date:   2019-06-24 15:09:31
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-24 19:08:09
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if(n<=1)
            return "1";
        string str_pre=countAndSay(n-1);
        string str;
        char tmp=str_pre[0];
        int num=1;
        for(int i=1;i<str_pre.size();++i)
        {
            if(str_pre[i]==tmp)
                ++num;
            else
            {
                str+=to_string(num);
                str+=tmp;
                tmp=str_pre[i];
                num=1;
            }
        }
        str+=to_string(num);
        str+=tmp;
        return str;
    }
};

int main()
{
    int i;
    while(cin>>i)
        cout<<Solution().countAndSay(i)<<endl;
    return 0;
}

