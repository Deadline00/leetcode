/*
* @Author: HeQing
* @Date:   2019-07-06 20:12:13
* @Last Modified by:   HeQing
* @Last Modified time: 2019-07-07 21:10:39
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> m={{1,2,3,4,5}};
    vector<int> relt=spiralOrder(m);
    if(!relt.empty())
    {
        for(auto x:relt)
            cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> relt;
    if(matrix.empty())
        return relt;
    int rstart=0,cstart=0,rend=matrix.size()-1,cend=matrix[0].size()-1;
    while(rstart<=rend && cstart<=cend)
    {
        int i=rstart,j=cstart;
        for(;j>=cstart && j<=cend;++j)
            relt.push_back(matrix[i][j]);
        ++rstart;
        if(rstart>rend || cstart>cend)
            break;
        for(i=rstart,j=cend;i>=rstart && i<=rend;++i)
            relt.push_back(matrix[i][j]);
        --cend;
        if(rstart>rend || cstart>cend)
            break;
        for(i=rend,j=cend;j>=cstart && j<=cend;--j)
            relt.push_back(matrix[i][j]);
        --rend;
        if(rstart>rend || cstart>cend)
            break;
        for(i=rend,j=cstart;i>=rstart && i<=rend;--i)
            relt.push_back(matrix[i][j]);
        ++cstart;
    }
    return relt;
}