/*
* @Author: HeQing
* @Date:   2019-05-21 10:49:10
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-21 20:38:15
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums);
int main()
{
    vector<int> v1={-1,0,1,2,-1,-4};
    vector<int> v2={0,0,0,0,0};
    vector<int> v3={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> v=threeSum(v3);
    return 0;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    if(nums.size()<3)
        return result;
    sort(nums.begin(),nums.end());
    vector<int> tmp;
    int len=nums.size(),index=0,begin=1,stop=len-1;
    for(index=0;index<len-2;++index)
    {
        if(index>0&&nums[index]==nums[index-1])
            continue;
        begin=index+1;
        stop=len-1;
        while(begin<stop)
        {
            if(nums[index]+nums[begin]+nums[stop]<0)
                ++begin;
            else if(nums[index]+nums[begin]+nums[stop]>0)
                --stop;
            else
            {
                if(result.empty()||result.back()[0]!=nums[index]||result.back()[1]!=nums[begin]||result.back()[2]!=nums[stop])
                {
                    tmp.push_back(nums[index]);
                    tmp.push_back(nums[begin]);
                    tmp.push_back(nums[stop]);
                    result.push_back(tmp);
                    cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
                    tmp.clear();
                }
                ++begin;
            }
        }
    }
    return result;
}