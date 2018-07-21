//https://www.interviewbit.com/problems/rotate-list/ 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (!A)
        return A;
    if (!A->next)
        return A;
    ListNode * second=A;
    ListNode * first = A;
    ListNode * fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode * pre = fakeHead;
    for(int i =1; i<B;i++) {
        if (second->next)
            second = second->next;
        else 
            second = A;
    }
    while (second->next) {
        first = first->next;
        second = second->next;
        pre = pre->next;
    }
    if (first == A)
        return A;
    second->next = A;
    pre->next = NULL;
    return first;
}
