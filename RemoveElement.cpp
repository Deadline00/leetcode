/*
* @Author: HeQing
* @Date:   2019-05-29 16:42:00
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-29 16:50:35
*/

#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int>& nums, int val);
int main()
{
    vector<int> v={2};//{3,2,2,5,3,1,2};
    cout<<removeElement(v,2)<<endl;
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
int removeElement(vector<int>& nums, int val)
{
    int len=nums.size();
    int i=0;
    while(i<len)
    {
        if(nums[i]==val)
            swap(nums[i],nums[--len]);
        else
            ++i;
    }
    return len;
}