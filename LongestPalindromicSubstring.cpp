/*
* @Author: HeQing
* @Date:   2019-05-15 16:03:11
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-15 17:01:35
*/

#include <iostream>
#include <string>

using namespace std;
string longestPalindrome(string s);
string palindrome(string& s,int i);
int main()
{
    string str;
    while(getline(cin,str))
    {
        cout<<longestPalindrome(str)<<endl;
        // cout<<palindrome(str,2)<<endl;
    }
    return 0;
}
string palindrome(string& s,int i)
{
    string str;
    int length=s.size();
    if(i>=length)
        return str;
    int j=0;
    for(j=1;i-j>=0 && i+j<length;++j)
    {
        if(s[i+j]!=s[i-j])
            break;
    }
    string tmp(s.substr(i-j+1,2*j-1));
    for(j=0;i-j>=0 && i+1+j<length;++j)
    {
        if(s[i+1+j]!=s[i-j])
            break;
    }
    str=tmp.size()>2*j?tmp:s.substr(i-j+1,2*j);
    return str;
}
string longestPalindrome(string s)
{
    string result;
    if(s.empty())
        return result;
    int length=s.size();
    for(int i=0;i<length;++i)
    {
        string tmp=palindrome(s,i);
        if(tmp.size()>result.size())
            result=tmp;
    }
    return result;
}