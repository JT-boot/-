/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {    //递归终点
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {     //判断结点大小
            l1->next = mergeTwoLists(l1->next, l2); //l1->next与l2继续比较
            return l1;  //返回l1
        } else {
            l2->next = mergeTwoLists(l1, l2->next); //l2->next与l1继续比较
            return l2;  //返回l2
        }
    }
};