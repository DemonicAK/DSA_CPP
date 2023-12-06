#include <bits/stdc++.h> // Include every standard library
using namespace std;

//  * Definition for singly-linked list.
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
// public:
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *curr = head;
        vector<int> nums;
        int carry = 0;
        while (curr)
        {
            nums.emplace_back(curr->val);
            curr = curr->next;
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int currCarry = 0;
            if (nums[i] * 2 >= 10)
            {
                nums[i] = (nums[i] * 2) % 10;
                currCarry = 1;
            }
            else
            {
                nums[i] = nums[i] * 2;
                currCarry = 0;
            }
                if (carry)
                {
                    nums[i] += carry;
                }
                carry = currCarry;
        }
        ListNode *newlist = new ListNode(0);
        if (carry)
        {
            newlist->val = 1;
        }
        curr = newlist;
        int i = 0;
        while (i < nums.size())
        {
            ListNode *node = new ListNode(nums[i]);
            curr->next = node;
            curr = curr->next;
            i++;
        }
            return (carry) ? newlist : newlist->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    ListNode *newlist = s.doubleIt(head);
    while (newlist)
    {
        cout << newlist->val << " ";
        newlist = newlist->next;
    }
    return 0;
}