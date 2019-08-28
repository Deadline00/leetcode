/*
* @Author: HeQing
* @Date:   2019-05-16 16:03:14
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-16 16:28:38
*/

#include <iostream>

using namespace std;
int reverse(int x);
int main()
{
    // cout<<sizeof(int)<<endl;
    // cout<<INT_MAX<<endl;
    int i;
    while(cin>>i)
    {
        cout<<reverse(i)<<endl;
    }
    return 0;
}
int reverse(int x)
{
    int result=0;
    while(x!=0)
    {
        if(result>INT_MAX/10 || result<INT_MIN/10 || (result==INT_MAX/10 && x%10>7) || (result==INT_MIN/10 && x%10<-8))
            return 0;
        result=result*10+x%10;
        x/=10;
    }
    return result;
}