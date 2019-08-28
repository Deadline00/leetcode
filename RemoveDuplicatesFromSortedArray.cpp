/*
* @Author: HeQing
* @Date:   2019-05-24 17:01:24
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-24 17:18:21
*/

#include <iostream>
#include <vector>

using namespace std;
int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> v={0,0,1,1,1,2,2,3,3,4};
    int i=removeDuplicates(v);
    cout<<i<<endl;
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
int removeDuplicates(vector<int>& nums)
{
    int rec=0;
    if(nums.empty())
        return rec;
    int index=0;
    for(int i=1;i<nums.size();++i)
    {
        if(nums[i]==nums[index])
            continue;
        else
            swap(nums[++index],nums[i]);
    }
    return index+1;
}