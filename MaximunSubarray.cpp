/*
* @Author: HeQing
* @Date:   2019-07-06 19:56:37
* @Last Modified by:   HeQing
* @Last Modified time: 2019-07-06 20:05:13
*/

#include <iostream>
#include <vector>

using namespace std;
int maxSubArray(vector<int>& nums);

int main()
{
    vector<int> v={-2,-1,-3,4};
    cout<<maxSubArray(v)<<endl;
    return 0;
}
int maxSubArray(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int max=nums[0],tmp=nums[0];
    for(int i=1;i<nums.size();++i)
    {
        tmp=tmp>0?tmp+nums[i]:nums[i];
        max=tmp>max?tmp:max;
    }
    return max;
}