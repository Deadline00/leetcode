/*
* @Author: HeQing
* @Date:   2019-06-17 15:29:16
* @Last Modified by:   HeQing
* @Last Modified time: 2019-06-17 17:10:32
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool isValidSudoku(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> input={{'.','.','.','.','.','.','5','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'9','3','.','.','2','.','4','.','.'},
                                {'.','.','7','.','.','.','3','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','.','3','4','.','.','.','.'},
                                {'.','.','.','.','.','3','.','.','.'},
                                {'.','.','.','.','.','5','2','.','.'}
                               };
    cout<<isValidSudoku(input)<<endl;
    return 0;
}
bool isValidSudoku(vector<vector<char>>& board)
{
    map<char,int> nums;
    // cow
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            if(board[i][j]!='.')
            {
                if(++nums[board[i][j]]>1)
                    // cout<<i<<" "<<j<<": "<<nums[board[i][j]]<<endl;
                    return false;
            }
        }
        nums.clear();
    }
    // col
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            if(board[j][i]!='.')
            {
                if(++nums[board[j][i]]>1)
                    return false;
            }
        }
        nums.clear();
    }
    // col
    for(int row=0,col=0;row<9 && col<9;)
    {
        int i=row,j=col;
        while(i<row+3&&j<col+3)
        {
            if(board[j][i]!='.')
            {
                if(++nums[board[j][i]]>1)
                    return false;
            }
            j=i==row+2?j+1:j;
            i=i==row+2?row:i+1;
        }
        nums.clear();
        col=row==6?col+3:col;
        row=row==6?0:row+3;
    }
    return true;
}