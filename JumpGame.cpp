/*
* @Author: HeQing
* @Date:   2019-07-07 21:22:14
* @Last Modified by:   HeQing
* @Last Modified time: 2019-07-07 21:44:03
*/

#include <iostream>
#include <vector>

using namespace std;
bool canJump(vector<int>& nums);
int main()
{
    vector<int> v={2,0,0};
    cout<<canJump(v)<<endl;
    return 0;
}
bool canJump(vector<int>& nums)
{
    if(nums.empty())
        return false;
    if(nums.size()==1)
        return true;
    for(int i=0;i<nums.size()-1;++i)
    {
        if(nums[i]>0)
            continue;
        int j=i-1;
        for(;j>=0;--j)
        {
            if(nums[j]>i-j)
                break;
        }
        if(j==-1)
            return false;
    }
    return true;
}