//https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if (!A)
        return A;
    if (!A->next)
        return NULL;
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode * second=A;
    ListNode * first = A;
    for(int i =0; i<B;i++) {
        if (second)
            second = second->next;
        else 
            return A->next;
    }
    while(second) {
        first = first->next;
        second = second->next;
        fakeHead = fakeHead->next;
    }
    
    fakeHead ->next = first->next;
    if (A == first)
        return fakeHead->next;
    return A;
     
}
