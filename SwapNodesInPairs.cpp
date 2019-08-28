/*
* @Author: HeQing
* @Date:   2019-05-28 16:04:43
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-28 16:25:07
*/

#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swapPairs(ListNode* head);
int main()
{
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);
    // l1->next->next=new ListNode(3);
    // l1->next->next->next=new ListNode(4);
    ListNode* l=swapPairs(l1);
    while(l)
    {
        cout<<l->val<<" ";
        l=l->next;
    }
    cout<<endl;
    return 0;
}
ListNode* swapPairs(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode* odd=head,*even=odd->next;
    head=even;
    while(even)
    {
        odd->next=even->next;
        even->next=odd;
        ListNode* pre=odd;
        odd=odd->next;
        if(!odd)
            break;
        even=odd->next;
        if(!even)
            break;
        pre->next=even;
    }
    return head;
}