/*
* @Author: HeQing
* @Date:   2019-08-06 21:40:46
* @Last Modified by:   HeQing
* @Last Modified time: 2019-08-06 21:53:41
*/

#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string s);
int main()
{
    string str="w ";
    cout<<lengthOfLastWord(str);
    return 0;
}
int lengthOfLastWord(string s)
{
    if(s.empty())
        return 0;
    int len=s.size()-1;
    int i=len;
    for(;i>=0 && s[i]==' ';--i);
    len=i;
    for(;i>=0 && s[i]!=' ';--i);
    return len-i;
}