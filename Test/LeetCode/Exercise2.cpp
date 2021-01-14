#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>
using namespace std;
/**
 * Definition for singly-linked list.
 *  */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *l3 = new ListNode();
        ListNode *l3_curr = l3;
        ListNode *next_l1 = l1;
        ListNode *next_l2 = l2;
        int carrier = 0;

        while (next_l1 != nullptr || next_l2 != nullptr)
        {
            ListNode *temp;
            int sum = 0;
            if (next_l1 == nullptr)
            {
                sum = next_l2->val + carrier;
                next_l2 = next_l2->next;
            }
            else if (next_l2 == nullptr)
            {
                sum = next_l1->val + carrier;
                next_l1 = next_l1->next;
            }
            else
            {
                sum = (next_l1->val + next_l2->val + carrier);
                next_l1 = next_l1->next;
                next_l2 = next_l2->next;
            }

            int val = sum % 10;
            carrier = sum / 10;
            l3_curr->next = new ListNode(val);
            l3_curr = l3_curr->next;
        }
        if (carrier > 0)
        {
            l3_curr->next = new ListNode(carrier);
        }
        return l3->next;
    }
};

int main()
{
    ListNode a(5);
    ListNode b(7);
    a.next = &b;

    ListNode c(1);
    ListNode d(1);
    ListNode dd(3);
    c.next = &d;
    d.next = &dd;

    ListNode *e = Solution::addTwoNumbers(&a, &c);
    ListNode *itr = e;
    while (itr != nullptr)
    {
        cout << itr->val << " ";
        itr = itr->next;
    }

     unordered_map <string,int> smap;
     smap["a"]=5;
     auto t=smap.find("a");
     cout<<t->first<<endl;
     int au=10;
     int bu=8;
     int tu=ceil((float)au/bu);
     cout<< tu;



}