/*
* @Author: HeQing
* @Date:   2019-05-17 10:48:38
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-17 11:12:27
*/

#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(int x);

int main()
{
    int i;
    while(cin>>i)
    {
        cout<<isPalindrome(i)<<endl;
    }
    return 0;
}
bool isPalindrome(int x)
{
    if(x<0)
        return false;
    string str;
    while(x!=0)
    {
        str+=('0'+x%10);
        x/=10;
    }
    int len=str.size(),i=len/2;;
    if(len%2)
    {
        for(int j=1;i-j>=0&&i+j<len;++j)
            if(str[i-j]!=str[i+j])
                return false;
    }
    else
    {
        i-=1;
        for(int j=0;i-j>=0&&i+1+j<len;++j)
            if(str[i-j]!=str[i+1+j])
                return false;
    }
    return true;


}