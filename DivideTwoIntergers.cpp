/*
* @Author: HeQing
* @Date:   2019-05-29 15:21:16
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-29 16:49:36
*/

#include <iostream>

using namespace std;
int divide(int dividend, int divisor);
int main()
{
    int a,b;
    while(cin>>a && cin>>b)
        cout<<divide(a,b)<<endl;
    return 0;
}
int divide(int dividend, int divisor)
{
    if((dividend==INT_MIN && divisor==-1))
        return INT_MAX;
    if(dividend==0)
        return 0;
    if(divisor==1)
        return dividend;
    if(divisor==-1)
        return -dividend;
    int rec=0,tmp=0;
    if(dividend>0 && divisor>0)//+,+
    {
        while(dividend>=tmp)
        {
            dividend-=divisor;
            tmp+=divisor;
            ++rec;
        }
        return rec;
    }
    else if(dividend<0 && divisor<0)//-,-
    {
        while(dividend-divisor<=0)
        {
            dividend-=divisor;
            if(rec==INT_MAX)
                return INT_MAX;
            ++rec;
        }
        return rec;
    }
    else if(dividend<0 && divisor>0)//-,+
    {
        while(dividend+divisor<=0)
        {
            dividend+=divisor;
            --rec;
        }
        return rec;
    }
    else//+,-
    {
        while(dividend+divisor>=0)
        {
            dividend+=divisor;
            --rec;
        }
        return rec;
    }
}