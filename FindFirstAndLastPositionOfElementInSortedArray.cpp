/*
* @Author: HeQing
* @Date:   2019-06-15 14:29:25
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-15 14:58:13
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int main()
{
    vector<int> v={5,7,7,8,8,10};
    vector<int> r=searchRange(v,10);
    for(auto x:r)
        cout<<x<<endl;
    return 0;
}
vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> rec={-1,-1};
    if(nums.empty())
        return rec;
    int start=0,stop=nums.size()-1,index=0;
    while(start<=stop)
    {
        index=start+(stop-start)/2;
        if(nums[index]==target)
            break;
        else if(nums[index]<target)
            start=index+1;
        else
            stop=index-1;
    }
    if(nums[index]!=target)
        return rec;
    start=0;stop=index;
    while(start<=stop)
    {
        int mid=start+(stop-start)/2;
        if(nums[mid]<target)
            start=mid+1;
        else if(mid==0)
        {
            rec[0]=0;break;
        }
        else if(nums[mid-1]!=target)
        {
            rec[0]=mid;break;
        }
        else
            stop=mid-1;
    }
    start=index;stop=nums.size()-1;
    while(start<=stop)
    {
        int mid=start+(stop-start)/2;
        if(nums[mid]>target)
            stop=mid-1;
        else if(mid==nums.size()-1)
        {
            rec[1]=nums.size()-1;break;
        }
        else if(nums[mid+1]!=target)
        {
            rec[1]=mid;break;
        }
        else
            start=mid+1;
    }
    return rec;
}