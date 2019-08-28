/*
* @Author: HeQing
* @Date:   2019-05-24 15:30:01
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-24 16:47:27
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target);
int main()
{
    vector<int> v1={-5,5,4,-3,0,0,4,-2};
    vector<int> v2={-2,-1,1,0,0,2};
    vector<vector<int>> v=fourSum(v1,4);
    return 0;
}
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    if(nums.size()<4)
        return result;
    sort(nums.begin(),nums.end());
    int len=nums.size(),first=0,sec=1,third=3,forth=len-1;
    if(4*nums[0]>target||4*nums[len-1]<target)
        return result;
    vector<int> tmp;
    for(;first<len-3;++first)
    {
        if(first && nums[first]==nums[first-1])
            continue;
        if(nums[first]+3*nums[first+1]>target||nums[first]+3*nums[len-1]<target)
            continue;
        tmp.push_back(nums[first]);
        for(sec=first+1;sec<len-2;++sec)
        {
            if(sec!=first+1 && nums[sec]==nums[sec-1])
                continue;
            if(nums[first]+nums[sec]+2*nums[sec+1]>target||nums[first]+nums[sec]+2*nums[len-1]<target)
                continue;
            tmp.push_back(nums[sec]);
            third=sec+1;
            forth=len-1;
            while(third<forth)
            {
                if(nums[first]+nums[sec]+nums[third]+nums[forth]==target)
                {
                    if(result.empty()||result.back()[0]!=nums[first]||result.back()[1]!=nums[sec]||result.back()[2]!=nums[third]||result.back()[3]!=nums[forth])
                    {
                        tmp.push_back(nums[third]);
                        tmp.push_back(nums[forth]);
                        result.push_back(tmp);
                        cout<<nums[first]<<" "<<nums[sec]<<" "<<nums[third]<<" "<<nums[forth]<<" "<<endl;
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                    ++third;
                }
                else if(nums[first]+nums[sec]+nums[third]+nums[forth]<target)
                {
                    ++third;
                }
                else
                {
                    --forth;
                }
            }
            tmp.pop_back();
        }
        tmp.pop_back();
    }
    return result;
}