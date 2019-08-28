/*
* @Author: HeQing
* @Date:   2019-05-22 10:05:13
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-22 10:53:24
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int threeSumClosest(vector<int>& nums, int target);
int main()
{
    vector<int> v1={-1,2,1,-4,0,8,3};
    cout<<threeSumClosest(v1,1)<<endl;
    return 0;
}
int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    int len=nums.size(),result=nums[0]+nums[1]+nums[len-1],sum=result,tmp=sum-target>0?sum-target:target-sum,min=tmp;
    for(int i=0;i<len-2;++i)
    {
        if(i>0&&nums[i]==nums[i-1])
            continue;
        int start=i+1,stop=len-1;
        while(start<stop)
        {
            sum=nums[i]+nums[start]+nums[stop];
            tmp=sum-target>0?sum-target:target-sum;
            min=tmp<min?result=sum,tmp:min;
            if(sum<target)
                ++start;
            else if(sum>target)
                --stop;
            else
                return target;
        }
    }
    return result;
}