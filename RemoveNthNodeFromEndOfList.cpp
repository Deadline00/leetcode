/*
* @Author: HeQing
* @Date:   2019-05-25 15:18:29
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-25 16:32:48
*/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n);
ListNode* removeNthFromEnd1(ListNode* head, int n);
int main()
{
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next=new ListNode(3);
    l1->next->next->next=new ListNode(4);
    l1->next->next->next->next=new ListNode(5);
    ListNode* l=removeNthFromEnd(l1,5);
    while(l)
    {
        cout<<l->val<<endl;
        l=l->next;
    }
    return 0;
}
ListNode* removeNthFromEnd1(ListNode* head, int n)
{
    ListNode* tmp=head;
    int num=0;
    while(tmp)
    {
        ++num;
        tmp=tmp->next;
    }
    tmp=head;
    if(num==n)
    {
        head=head->next;
        delete tmp;
    }
    else
    {
        while(num>n+1)
        {
            tmp=tmp->next;
            --num;
        }
        ListNode* x=tmp->next;
        tmp->next=tmp->next->next;
        delete x;
    }

    return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* pre=head,*after=head;
    while(n>0)
    {
        pre=pre->next;
        --n;
    }
    if(pre)
    {
        while(pre->next)
        {
            pre=pre->next;
            after=after->next;
        }
        after->next=after->next->next;
    }
    else
    {
        head=head->next;
    }
    return head;

}