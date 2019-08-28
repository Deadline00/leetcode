/*
* @Author: HeQing
* @Date:   2019-05-19 20:48:53
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-19 21:49:20
*/

#include <iostream>
#include <string>

using namespace std;
string intToRoman(int num);
int main()
{
    int i;
    while(cin>>i)
    {
        cout<<intToRoman(i)<<endl;
    }
    return 0;
}
string intToRoman(int num)
{
    string str;
    int i=0;
    i=num/1000;
    while(i-- >0)
        str+='M';

    num%=1000;
    i=num/100;
    if(i==9)
        str+="CM";
    else if(i>4)
        str+='D'+string(i-5,'C');
    else if(i==4)
        str+="CD";
    else
        str+=string(i,'C');

    num%=100;
    i=num/10;
    if(i==9)
        str+="XC";
    else if(i>4)
        str+='L'+string(i-5,'X');
    else if(i==4)
        str+="XL";
    else
        str+=string(i,'X');

    num%=10;
    i=num;
    if(i==9)
        str+="IX";
    else if(i>4)
        str+='V'+string(i-5,'I');
    else if(i==4)
        str+="IV";
    else
        str+=string(i,'I');

    return str;
}