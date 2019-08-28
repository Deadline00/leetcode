/*
* @Author: HeQing
* @Date:   2019-04-25 17:32:16
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-11 15:51:26
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
    vector<int> v1,v2={3,2,4};
    v1=twoSum(v2,6);
    if(!v1.empty())
        cout<<v1[0]<<" "<<v1[1]<<endl;
    return 0;
}
vector<int> twoSum1(vector<int>& nums, int target)
{
    vector<int> result;
    if(nums.size()<=1)
        return result;
    multimap<int,int> index;
    for(int i=0;i<nums.size();++i)
    {
        index.insert({nums[i],i});
    }
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;
    while(i<j)
    {
        if(nums[i]+nums[j]<target)
        {
            ++i;
            continue;
        }
        else if(nums[i]+nums[j]==target)
        {
            result.push_back(index.find(nums[i])->second);
            (nums[i]==nums[j])?result.push_back((++index.find(nums[j]))->second):result.push_back(index.find(nums[j])->second);
            break;
        }
        else
        {
            --j;
            continue;
        }
    }
    return result;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    if(nums.size()<=1)
        return result;
    multimap<int,int> index;
    for(int i=0;i<nums.size();++i)
    {
        index.insert({nums[i],i});
    }
    for(int i=0;i<nums.size();++i)
    {
        if(index.find(target-nums[i])!=index.end())
        {
            if(nums[i]==target-nums[i] && index.count(nums[i])>1)
            {
                result.push_back(index.find(nums[i])->second);
                result.push_back((++index.find(nums[i]))->second);
                break;
            }
            else if(nums[i]==target-nums[i] && index.count(nums[i])<=1)
                continue;
            else
            {
                result.push_back(index.find(nums[i])->second);
                result.push_back(index.find(target-nums[i])->second);
            }
        }
        else
            continue;
    }
    return result;
}