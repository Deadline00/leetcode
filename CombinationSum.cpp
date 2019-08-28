/*
* @Author: HeQing
* @Date:   2019-06-24 20:27:50
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-26 21:32:23
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) ;

int main()
{
    vector<int> v={2,3,5};
    vector<vector<int>> rec=combinationSum(v,7);
    if(!rec.empty())
    {
        for(auto & tmp:rec)
        {
            if(!tmp.empty())
                for(auto x:tmp)
                {
                    cout<<x<<" ";
                }
                cout<<endl;
        }
    }

    return 0;
}
void help(vector<int>& candidates,int target,int i,vector<int>& tmp,vector<vector<int>>& rec)
{
    for(;i<candidates.size();++i)
    {
        if(candidates[i]>target)
            break;

        tmp.push_back(candidates[i]);
        target-=candidates[i];

        if(target==0)
            rec.push_back(tmp);
        else
        {
            for(int j=i;j<candidates.size();++j)
            {
                if(candidates[j]>target)
                    break;
                if(candidates[j]==target)
                {
                    tmp.push_back(candidates[j]);
                    rec.push_back(tmp);
                    tmp.pop_back();
                    break;
                }
                help(candidates,target,j,tmp,rec);
            }
        }

        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> rec;
    if(candidates.empty())
        return rec;
    sort(candidates.begin(),candidates.end());
    if(candidates.front()>target)
        return rec;
    vector<int> tmp;
    help(candidates,target,0,tmp,rec);
    return rec;
}