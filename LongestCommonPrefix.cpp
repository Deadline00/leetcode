/*
* @Author: HeQing
* @Date:   2019-05-20 17:31:53
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-20 17:40:16
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string longestCommonPrefix(vector<string>& strs);

int main()
{
    vector<string> input1={"flower","flow","flight"},input2={"dog","racecar","car"};
    cout<<"input1: "<<longestCommonPrefix(input1)<<endl;
    cout<<"input2: "<<longestCommonPrefix(input2)<<endl;
    return 0;
}
string longestCommonPrefix(vector<string>& strs)
{
    string str;
    if(strs.empty()||strs[0].empty())
        return str;
    for(int i=0;i<strs[0].size();++i)
    {
        int j=1;
        char tmp=strs[0][i];
        while(j<strs.size())
        {
            if(strs[j][i]==tmp)
                ++j;
            else
                break;
        }
        if(j==strs.size())
            str+=tmp;
        else
            break;
    }
    return str;
}