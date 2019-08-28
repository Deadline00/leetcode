/*
* @Author: HeQing
* @Date:   2019-05-30 20:52:35
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-04 20:32:15
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void nextPermutation(vector<int>& nums);

int main()
{
    vector<int> v={1,3,2};
    nextPermutation(v);
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
int binfind(int i,int len,vector<int>& v,int target)//寻找比nums[i]大的最小的数
{
    if(v[i]>target)
        return i;
    int index=i;
    while(i<len)
    {
        index=i+(len-i)/2;
        if(v[index]<target)
            i=++index;
        else if(v[index]>target)
            len=--index;
        else
            return index;
    }
    if(v[index]<target)
        ++index;
    return index;
}
void nextPermutation(vector<int>& nums)
{
    if(nums.size()<2)
        return;
    int len=nums.size()-1;
    for(int i=len-1;i>=0;--i)
    {
        if(nums[i]<nums[i+1])
        {
            sort(nums.begin()+i+1,nums.end());
            int index=i+1;
            while(index<=len&&nums[index]<=nums[i])
                ++index;
            swap(nums[i],nums[index]);
            return;
        }
    }
    for(int j=0,k=len;j<k;++j,--k)
        swap(nums[j],nums[k]);
}