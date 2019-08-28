/*
* @Author: HeQing
* @Date:   2019-05-16 10:46:40
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-16 14:13:43
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string convert(string s, int numRows);

int main()
{
    string str="abcda";
    int numRows = 4;
    cout<<convert(str,numRows)<<endl;
    return 0;
}
string convert(string s, int numRows)
{
    string str;
    if(s.empty() || numRows<1)
        return str;
    if(numRows==1)
        return s;
    int len=s.size(),cols=(s.size()/(numRows+numRows-2)+1)*(numRows-1);
    char ch[numRows][cols];
    memset(ch,'\0',numRows*cols);
    int index=0,i=0,j=0;
    while(index<len)
    {
        while(i<numRows)
        {
            if(index>=len)
                break;
            ch[i++][j]=s[index++];
            // cout<<i-1<<","<<j<<":"<<ch[i-1][j]<<endl;
        }
        if(index>=len)
            break;
        --i;
        while(i>1)
        {
            if(index>=len)
                break;
            ch[--i][++j]=s[index++];
            // cout<<i<<","<<j<<":"<<ch[i][j]<<endl;
        }
        --i;++j;
    }
    for(i=0;i<numRows;++i)
        for(j=0;j<cols;++j)
        {
            if(ch[i][j]!='\0')
                str+=ch[i][j];
        }
    return str;
}