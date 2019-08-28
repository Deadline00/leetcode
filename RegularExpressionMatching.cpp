/*
* @Author: HeQing
* @Date:   2019-05-18 16:08:31
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-18 17:15:38
*/

#include <iostream>
#include <string>

using namespace std;
bool isMatch(string s, string p);
int main()
{
    string str1,str2;
    while(getline(cin,str1) && getline(cin,str2))
    {
        cout<<isMatch(str1,str2)<<endl;
    }
    return 0;
}
bool isMatch(string s, string p)
{
    if(s.empty() || p.empty())
        return false;
    int i=0,j=0;
    while(s[i]!='\0' && p[j]!='\0')
    {
        if(s[i]==p[j] || p[j]=='.')
        {
            ++i;++j;
        }
        else if(p[j]=='*')
            ++j;
        else if(p[j+1]=='*')
        {
            ++j;++j;
        }
        else if(s[i]==s[i-1] && p[j-1]=='*')
        {
            ++i;
        }
        else
            return false;
    }
    while(s[i]!='\0')
    {
        if(p[j-1]!='*' || s[i]!=s[i-1])
            return false;
        ++i;
    }
    while(p[j]!='\0')
    {
        if(p[j]=='*')
            ++j;
        else if(p[j+1]=='*')
        {
            ++j;++j;
        }
        else
            return false;
    }
    return true;
}
// "bccbbabcaccacbcacaa"
// ".*b.*c*.*.*.c*a*.c"