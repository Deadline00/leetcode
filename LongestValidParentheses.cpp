/*
* @Author: HeQing
* @Date:   2019-06-04 20:42:10
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-04 21:07:19
*/

#include <iostream>
#include <string>

using namespace std;
int longestValidParentheses(string s);
int main()
{
    string str;
    while(getline(cin,str))
    {
        cout<<longestValidParentheses(str)<<endl;
    }
    return 0;
}
int longestValidParentheses(string s)
{
    int max=0,num=0,tmp=0,pre=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(')
            ++num;
        if(s[i]==')')
        {
            if(num>0)
            {
                --num;
                ++tmp;
                max=tmp>max?tmp:max;
                if(num==0)
                {
                    max=tmp+pre>max?tmp+pre:max;
                    pre=tmp;
                    tmp=0;
                }

            }
            else if(num==0)
            {
                pre=0;
                tmp=0;
            }
        }
    }
    return max*2;
}
//(()(((()