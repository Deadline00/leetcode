/*
* @Author: HeQing
* @Date:   2019-05-14 10:48:15
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-14 15:27:46
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;
int lengthOfLongestSubstring(string s);

int main()
{
    string str;
    while(getline(cin,str))
    {
        cout<<lengthOfLongestSubstring(str)<<endl;
    }
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    if(s.empty())
        return 0;
    int max=0,tmp=0,substart=0;
    map<char,int> chars;
    for(int i=0;i<s.size();++i)
    {
        if(chars.find(s[i])==chars.end() || chars.find(s[i])->second<substart)
        {
            ++tmp;
        }
        else
        {
            tmp=tmp-chars[s[i]]+substart;
            substart=chars[s[i]]+1;
        }
        chars[s[i]]=i;
        max=max>tmp?max:tmp;
    }
    return max;
}