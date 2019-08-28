/*
* @Author: HeQing
* @Date:   2019-08-11 20:45:54
* @Last Modified by:   HeQing
* @Last Modified time: 2019-08-11 21:19:17
*/

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> generateMatrix(int n);
int main()
{
    int i;
    while(cin>>i)
    {
        vector<vector<int>> rec;
        rec=generateMatrix(i);
        for(auto &tmp:rec)
        {
            for(auto x:tmp)
                cout<<x<<" "；
            cout<<endl;
        }
    }
    return 0;
}
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> rec(n,vector<int>(n));
    int num=0;
    int start=0,end=n-1;
    while(start<=end)
    {
        int i=start,j=start;
        rec[i][j]=++num;
        while(++i<=end)
            rec[i][j]=++num;
        --i;
        while(++j<=end)
            rec[i][j]=++num;
        --j;
        while(--i>=start)
            rec[i][j]=++num;
        ++i;
        while(--j>start)
            rec[i][j]=++num;
        ++start;
        --end;
    }
    return rec;

}