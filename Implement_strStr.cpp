/*
* @Author: HeQing
* @Date:   2019-06-26 21:23:59
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-26 21:33:37
*/

#include <iostream>
#include <string>

using namespace std;
int strStr(string haystack, string needle);

int main()
{
    string str1="hello",str2="ol";
    cout<<strStr(str1,str2)<<endl;
    return 0;
}

int strStr(string haystack, string needle)
{
    if(needle.empty())
        return 0;
    if(haystack.size()<needle.size())
        return -1;
    for(int i=0;i<haystack.size()-needle.size()+1;++i)
    {
        if(haystack[i]==needle[0])
        {
            int j=1;
            for(;j<needle.size();++j)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==needle.size())
                return i;
        }
    }
    return -1;
}