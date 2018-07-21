//https://www.interviewbit.com/problems/partition-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if (!A) 
        return A;
        
        //definition of pointer
        ListNode * fakeHead  = new ListNode(0);
        fakeHead->next= A;
        ListNode * ptr1 = fakeHead;
        ListNode * curr = A;
        ListNode * ptr2 = A->next;
        ListNode * prePtr2 = A;
        
        while(curr && curr->val < B) {
            ptr1 = ptr1->next;
            curr = curr->next;
            prePtr2 = prePtr2->next;
            if (ptr2)
                ptr2 = ptr2->next;
        }
        
        while(ptr2) {
            if (ptr2->val <B) {
                prePtr2->next = ptr2->next;
                ptr1->next = ptr2;
                ptr1 = ptr2;
                ptr1->next = curr;
                ptr2 = prePtr2->next;
                continue;
            }
            ptr2 = ptr2->next;
            prePtr2 = prePtr2->next;
        }
        return fakeHead->next;
        
}