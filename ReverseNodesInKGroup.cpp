/*
* @Author: HeQing
* @Date:   2019-05-29 10:43:40
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-29 15:08:59
*/

#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseKGroup(ListNode* head, int k);
int main()
{
    ListNode* l1=new ListNode(1);
    // l1->next=new ListNode(2);
    // l1->next->next=new ListNode(3);
    // l1->next->next->next=new ListNode(4);
    // l1->next->next->next->next=new ListNode(5);
    ListNode* l=reverseKGroup(l1,3);
    while(l)
    {
        cout<<l->val<<" ";
        l=l->next;
    }

    // ListNode* start=l1,*stop=l1->next->next->next->next,*cur=start->next;
    // start->next=NULL;
    // while(start!=stop)
    // {
    //     ListNode* tmp=cur->next;
    //     cur->next=start;
    //     start=cur;
    //     cur=tmp;
    // }
    // l1=stop;
    // while(l1)
    // {
    //     cout<<l1->val<<" ";
    //     l1=l1->next;
    // }
    cout<<endl;
    return 0;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    if(!head || k==1)
        return head;
    ListNode* rec=NULL;
    ListNode* start=head,*stop=head,*before=NULL;
    while(stop)
    {
        int i=1;
        while(i<k)
        {
            stop=stop->next;
            if(!stop)
                break;
            ++i;
        }
        if(i<k)
            break;
        if(!rec)
        {
            rec=stop;
        }
        else
            before->next=stop;
        ListNode* after=stop->next;
        ListNode* cur=start->next;
        start->next=after;
        before=start;
        while(start!=stop)
        {
            ListNode* tmp=cur->next;
            cur->next=start;
            start=cur;
            cur=tmp;
        }
        stop=after;
        start=stop;
    }
    return rec?rec:head;
}