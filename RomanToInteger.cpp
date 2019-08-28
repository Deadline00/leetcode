/*
* @Author: HeQing
* @Date:   2019-05-20 16:49:41
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-20 17:23:11
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;
int romanToInt(string s);
int romanToInt1(string s);

int main()
{
    string str;
    while(getline(cin,str))
        cout<<romanToInt(str)<<" "<<romanToInt1(str)<<endl;
    return 0;
}
int romanToInt(string s)
{
    int num=0;
    for(int i=0;i<s.size();++i)
    {
        switch(s[i])
        {
            case 'M':
                num+=1000;
                continue;
            case 'C':
                if(s[i+1]=='M'||s[i+1]=='D')
                    num-=100;
                else
                    num+=100;
                continue;
            case 'D':
                num+=500;
                continue;
            case 'X':
                if(s[i+1]=='L'||s[i+1]=='C')
                    num-=10;
                else
                    num+=10;
                continue;
            case 'L':
                num+=50;
                continue;
            case 'I':
                if(s[i+1]=='V'||s[i+1]=='X')
                    num-=1;
                else
                    num+=1;
                continue;
            case 'V':
                num+=5;
                continue;
            default:
                return -1;
        }
    }
    return num;
}
int romanToInt1(string s)
{
    map<char, int> T = { { 'I' , 1 },
                         { 'V' , 5 },
                         { 'X' , 10 },
                         { 'L' , 50 },
                         { 'C' , 100 },
                         { 'D' , 500 },
                         { 'M' , 1000 } };

   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i)
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }

   return sum;
}