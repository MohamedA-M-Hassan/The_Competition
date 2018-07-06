//https://www.interviewbit.com/problems/merge-two-sorted-lists/
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode* prev = fakeHead;
    while (A&&B){
        if (B->val<A->val) {
            ListNode * tempB = B->next;
            prev->next = B;
            B->next = A;
            A = B;
            B = tempB;
        } 
        else {
           prev  = A;
           A= A->next; 
        }
        
    }
    if (B) {
        prev->next = B;
    }
    //while(fakeHead->next) {
    //    std::cout << fakeHead->next->val << std::endl;
    //    fakeHead = fakeHead->next;
    //}
    return fakeHead->next;
}
