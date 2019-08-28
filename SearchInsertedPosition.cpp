/*
* @Author: HeQing
* @Date:   2019-06-15 15:11:47
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-15 15:54:04
*/

#include <iostream>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target);

int main()
{
    vector<int> v={1,3,5,7,10};
    cout<<searchInsert(v,6)<<endl;
    return 0;
}
int searchInsert(vector<int>& nums, int target)
{
    if(nums.empty() || nums[0]>=target)
        return 0;
    if(nums[nums.size()-1]<target)
        return nums.size();
    int start=0,stop=nums.size()-1,mid=0;
    while(start<=stop)
    {
        mid=start+(stop-start)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            start=mid+1;
        else
            stop=mid-1;
    }
    if(nums[mid]>target)
        return mid;
    else
        return mid+1;
}