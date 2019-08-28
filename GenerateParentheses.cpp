/*
* @Author: HeQing
* @Date:   2019-05-25 16:41:28
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-26 21:58:03
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
vector<string> generateParenthesis(int n) ;

int main()
{
    // cout<<sizeof(int)<<endl;
    vector<string> v=generateParenthesis(1);
    for(auto x:v)
        cout<<x<<endl;
    return 0;
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    if(n<=0)
        return result;
    string str;

    return result;
}