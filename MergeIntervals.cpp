/*
* @Author: HeQing
* @Date:   2019-07-10 21:48:39
* @Last Modified by:   HeQing
* @Last Modified time: 2019-07-10 22:03:26
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals);
int main()
{
    vector<vector<int>> v={{1,4},{2,4},{18,19},{15,18}};
    vector<vector<int>> output=merge(v);
    for(auto &x:output)
    {
        for(auto xx:x)
            cout<<xx<<" ";
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> rec;
    if(intervals.empty())
        return rec;
    sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0];});
    vector<int> tmp;
    tmp.push_back(intervals[0][0]);
    int right=intervals[0][1];
    for(int i=1;i<intervals.size();++i)
    {
        if(intervals[i][0]<=right)
        {
            right=intervals[i][1]>right?intervals[i][1]:right;
        }
        else
        {
            tmp.push_back(right);
            rec.push_back(tmp);
            tmp.clear();
            tmp.push_back(intervals[i][0]);
            right=intervals[i][1];
        }
    }
    tmp.push_back(right);
    rec.push_back(tmp);
    return rec;
}