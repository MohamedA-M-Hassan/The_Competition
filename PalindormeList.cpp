/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://www.interviewbit.com/problems/palindrome-list/
ListNode* getMiddleNode(ListNode* head) {
    struct ListNode * slowPtr = head;
    struct ListNode * fastPtr = head;
    while(fastPtr != NULL && fastPtr->next!=NULL ) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;

    }
    return slowPtr;
}
ListNode* reverseList (ListNode* start ) {
    ListNode *current = start;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    return prev;
}



int Solution::lPalin(ListNode* A) {
    //get mid node 
    //struct ListNode* C = new ListNode;
    //*C = {3,NULL};
    //struct ListNode* B = new ListNode;
    //*B = {2,C};
    //struct ListNode* A = new ListNode;
    //*A = {1,B};
    
     //get mid node 
     //get mid node 
    struct ListNode* midNode = getMiddleNode(A);

    //reverse second part 
    struct ListNode* secondReversed = reverseList(midNode);
    
    while (secondReversed && A) {
        if (secondReversed->val != A->val) {
            //std::cout << "not palindrome" <<std::endl;
            return 0;
        }

        secondReversed = secondReversed->next;
        A = A->next;
    }
        //std::cout << "palimdrome" << std::endl;
        return 1 ;

    return 0;
 }
