/*
* @Author: HeQing
* @Date:   2019-05-27 09:35:54
* @Last Modified by:   HeQing
* @Last Modified time: 2019-05-28 16:01:49
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists);
int main()
{
    vector<ListNode*> l;
    ListNode* l1=new ListNode(1);l1->next=new ListNode(4);l1->next->next=new ListNode(5);
    l.push_back(l1);
    l1=new ListNode(1);l1->next=new ListNode(3);l1->next->next=new ListNode(4);
    l.push_back(l1);
    l1=new ListNode(2);l1->next=new ListNode(6);
    l.push_back(l1);
    ListNode* l2=mergeKLists(l);
    while(l2)
    {
        cout<<l2->val<<" ";
        l2=l2->next;
    }
    cout<<endl;
    return 0;
}
struct cmp
{
    bool operator()(ListNode* l1,ListNode* l2)
    {
        return l1->val>l2->val;
    }
};

ListNode* mergeKLists1(vector<ListNode*>& lists)
{
    ListNode* rec=NULL;
    if(lists.empty())
        return rec;
    if(lists.size()==1)
        return lists[0];

    ListNode* tmp=NULL;
    int min=INT_MAX,index=0;
    bool flag=false;
    do
    {
        flag=false;
        min=INT_MAX;
        for(int i=0;i<lists.size();++i)
        {
            if(lists[i] && lists[i]->val<=min)
            {
                index=i;
                min=lists[i]->val;
                flag=true;
            }
        }
        if(!flag)
            break;
        if(!rec)
        {
            rec=lists[index];
            tmp=rec;
        }
        else
        {
            tmp->next=lists[index];
            tmp=tmp->next;
        }
        lists[index]=lists[index]->next;
    }while(flag);

    return rec;
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    ListNode* rec=NULL;
    if(lists.empty())
        return rec;
    if(lists.size()==1)
        return lists[0];

    ListNode* tmp=NULL;
    priority_queue<ListNode*,vector<ListNode*>,cmp> x;
    for(int i=0;i<lists.size();++i)
    {
        if(lists[i])
            x.push(lists[i]);
    }
    while(!x.empty())
    {
        if(!rec)
        {
            rec=x.top();
            tmp=rec;
        }
        else
        {
            tmp->next=x.top();
            tmp=tmp->next;
        }
        x.pop();
        if(tmp->next)
            x.push(tmp->next);
    }

    return rec;
}