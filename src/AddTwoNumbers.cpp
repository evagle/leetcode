#include <iostream>

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = new ListNode(0);
        ListNode *head = p;
        int num = 0;
        while (l1 || l2) {
            p->next = new ListNode(0);
            p = p->next;
            
            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }
            
            if (num >= 10){
                p->val = num % 10;
## num=num/10运行时间220ms
//                num = num/10;
## num=1运行时间50ms，除法消耗的时间不容小觑
                num = 1;
            } else {
                p->val = num;
                num = 0;
            }
        }
       
        if (num > 0) {
            p->next = new ListNode(0);
            p = p->next;
            p->val = num;
        }
        return head->next;
    }
};
int main(int argc, char *argv[]) {
	// Example
	// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	// Output: 7 -> 0 -> 8
}