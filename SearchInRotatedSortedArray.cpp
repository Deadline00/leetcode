/*
* @Author: HeQing
* @Date:   2019-06-10 15:52:16
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-10 16:49:20
*/

#include <iostream>
#include <vector>

using namespace std;
int search(vector<int>& nums, int target);

int main()
{
    vector<int> v={8,9,2,3,4};
    // cout<<search(v,2)<<endl;
    cout<<search(v,2)<<endl;
    return 0;
}
int helpsearch(vector<int>& nums, int target,int start,int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]<target)
            start=mid+1;
        else if(nums[mid]>target)
            end=mid-1;
        else
            return mid;
    }
    return -1;
}
int search(vector<int>& nums, int target)
{
    if(nums.empty())
        return -1;
    int start=0,end=nums.size()-1,max=end;
    if(nums[start]>nums[end])
    {
        int mid=0;
        int tmp=nums[end];
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]>nums[mid+1])
                break;
            if(nums[mid]>tmp)
                start=mid+1;
            else
                end=mid-1;
        }
        max=mid;
    }
    end=nums.size()-1;
    if(target<nums[0])
        return helpsearch(nums,target,max+1,end);
    else if(target>nums[0])
        return helpsearch(nums,target,0,max);
    else
        return 0;
}