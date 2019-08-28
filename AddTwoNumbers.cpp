/*
* @Author: HeQing
* @Date:   2019-05-13 20:40:49
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-14 15:01:42
*/

#include <iostream>
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int main()
{
    ListNode* l1=new ListNode(2);l1->next=new ListNode(4);l1->next->next=new ListNode(3);
    ListNode* l2=new ListNode(5);l2->next=new ListNode(6);l2->next->next=new ListNode(4);
    ListNode* l3=addTwoNumbers(l1,l2);
    vector<int> result;
    while(l3)
    {
        result.push_back(l3->val);
        l3=l3->next;
    }
    for(int i=result.size()-1;i>=0;--i)
    {
        cout<<result[i];
    }
    cout<<endl;
    return 0;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* result=new ListNode(0);
    ListNode* tmp=result;
    int sum=l1->val+l2->val;
    bool flag=(sum>9);
    tmp->val=flag?sum%10:sum;
    l1=l1->next;
    l2=l2->next;
    while(l1 && l2)
    {
        sum=flag?l1->val+l2->val+1:l1->val+l2->val;
        if(sum>9)
        {
            flag=true;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
        }
        else
        {
            flag=false;
            tmp->next=new ListNode(sum);
            tmp=tmp->next;
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l1)
    {
        sum=flag?l1->val+1:l1->val;
        if(sum>9)
        {
            flag=true;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
        }
        else
        {
            flag=false;
            tmp->next=new ListNode(sum);
            tmp=tmp->next;
        }
        l1=l1->next;
    }
    while(l2)
    {
        sum=flag?l2->val+1:l2->val;
        if(sum>9)
        {
            flag=true;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
        }
        else
        {
            flag=false;
            tmp->next=new ListNode(sum);
            tmp=tmp->next;
        }
        l2=l2->next;
    }
    if(flag)
        tmp->next=new ListNode(1);
    return result;
}