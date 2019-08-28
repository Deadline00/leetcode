/*
* @Author: HeQing
* @Date:   2019-05-23 09:41:50
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-23 10:17:22
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string> letterCombinations(string digits);
map<char,vector<char>> digit2letter={   {'2',{'a','b','c'}},
                                        {'3',{'d','e','f'}},
                                        {'4',{'g','h','i'}},
                                        {'5',{'j','k','l'}},
                                        {'6',{'m','n','o'}},
                                        {'7',{'p','q','r','s'}},
                                        {'8',{'t','u','v'}},
                                        {'9',{'w','x','y','z'}}
                                    };
int main()
{
    string str;
    while(getline(cin,str))
    {
        vector<string> s=letterCombinations(str);
        for(auto x:s)
            cout<<x<<endl;
    }
    return 0;
}
void helpletterCombinations(string& digits,int i,string& str,vector<string>& result)
{
    if(i>=digits.size())
        result.push_back(str);
    else
    {
        char num=digits[i];
        for(int j=0;j<digit2letter[num].size();++j)
        {
            str+=digit2letter[num][j];
            helpletterCombinations(digits,i+1,str,result);
            str.pop_back();
        }
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> result;
    if(digits.empty())
        return result;
    string str;
    helpletterCombinations(digits,0,str,result);
    return result;
}