/*
* @Author: HeQing
* @Date:   2019-05-17 09:35:36
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-17 10:36:08
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;
int myAtoi(string str);

int main()
{
    string str;
    while(getline(cin,str))
    {
        // cout<<INT_MAX<<endl;
        // cout<<INT_MIN<<endl;
        cout<<myAtoi(str)<<endl;
    }
    return 0;
}

int myAtoi(string str)
{
    int rec=0;
    set<char> space={'\n',' ','\t','\0'};
    if(str.empty())
    {
        cout<<"str is empty"<<endl;
        return rec;
    }
    int i=0;
    bool flag=true;
    for(;i<str.size();++i)
    {
        if(space.find(str[i])!=space.end())
            continue;
        if(str[i]=='-' || str[i]=='+' || (str[i]>='0'&&str[i]<='9'))
            break;
        else
            return rec;
    }
    if(i<str.size())
    {
        flag=(str[i]=='-')?false:true;
        if(str[i]>='0'&&str[i]<='9')
            rec=str[i]-'0';
        for(++i;i<str.size();++i)
        {
            if(!(str[i]>='0'&&str[i]<='9'))
                break;
            if((flag&&rec>INT_MAX/10) || (flag&&rec==INT_MAX/10&&str[i]>'7') )
                return INT_MAX;
            if((!flag&&rec<INT_MIN/10) || (!flag&&rec==INT_MIN/10&&str[i]>'8'))
                return INT_MIN;
            if(flag)
                rec=rec*10+(str[i]-'0');
            else
                rec=rec*10-(str[i]-'0');
        }
    }
    return rec;

}