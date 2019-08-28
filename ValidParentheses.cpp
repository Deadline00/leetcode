/*
* @Author: HeQing
* @Date:   2019-05-23 10:28:39
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-23 11:03:49
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s);
int main()
{
    string str;
    while(getline(cin,str))
        cout<<isValid(str)<<endl;

    return 0;
}
bool isValid(string s)
{
    if(s.empty())
        return true;
    stack<char> brack;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            brack.push(s[i]);
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(brack.empty())
                return false;
            else if((s[i]==')'&& brack.top()=='(') || (s[i]==']'&& brack.top()=='[') ||(s[i]=='}'&& brack.top()=='{'))
                brack.pop();
            else
                return false;
        }
    }
    if(brack.empty())
        return true;
    return false;
}
