/*
* @Author: HeQing
* @Date:   2019-07-15 21:51:16
* @Last Modified by:   HeQing
* @Last Modified time: 2019-08-06 21:39:06
*/

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
int main()
{
    vector<vector<int>> v1={{1,2},{6,9}};
    vector<int> v2={2,5};
    vector<vector<int>> v=insert(v1,v2);
    for(auto &x:v)
    {
        for(auto xx:x)
            cout<<xx<<" ";
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    if(newInterval.empty())
        return intervals;
    vector<vector<int>> rec;
    if(intervals.empty())
    {
        rec.push_back(newInterval);
        return rec;
    }
    int i=0;
    for(;i<intervals.size() && intervals[i][1]<newInterval[0];++i)
    {
        rec.push_back(intervals[i]);
    }
    vector<int> tmp;
    int left=i<intervals.size()?(intervals[i][0]<newInterval[0]?intervals[i][0]:newInterval[0]):newInterval[0],right=newInterval[1];
    for(;i<intervals.size() && intervals[i][0]<=newInterval[1];++i)
    {
        if(left>newInterval[0])
            left=newInterval[0];
        if(intervals[i][1]>=right)
            right=intervals[i][1];
    }
    tmp.push_back(left);
    tmp.push_back(right);
    rec.push_back(tmp);
    for(;i<intervals.size();++i)
    {
        rec.push_back(intervals[i]);
    }
    return rec;
}