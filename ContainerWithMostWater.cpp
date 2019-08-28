/*
* @Author: HeQing
* @Date:   2019-05-18 21:07:03
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-19 20:43:30
*/

#include <iostream>
#include <vector>

using namespace std;
int maxArea(vector<int>& height);
int main()
{
    vector<int> v={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(v)<<endl;
    return 0;
}
int maxArea(vector<int>& height)
{
    if(height.size()<2)
        return 0;
    int i=0,j=height.size()-1,cap=0,tmp=0;
    while(i<j)
    {
        int wid=j-i;
        tmp=(height[i]<height[j]?height[i++]:height[j--])*wid;
        cap=tmp>cap?tmp:cap;
    }
    return cap;
}