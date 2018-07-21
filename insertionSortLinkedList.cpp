//https://www.interviewbit.com/problems/insertion-sort-list/

 /* struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x, ListNode* n) : val(x), next(n) {}
 };
 
 ListNode *CreateLinkedList(int* arr, int ln)
 {
    ListNode *temp = new ListNode(arr[ln-1], NULL);
    for(int i = ln-2; i >= 0; i--) {
        temp = new ListNode(arr[i], temp);
    }
    return temp;
 } */

ListNode* Solution::insertionSortList(ListNode* A) {
    if (!A)
        return A;
    if(!A->next)
        return A;
    ListNode *ptr1,*ptr2,*ptr3;
    ptr1 = A;
    ptr2 = A;
    ptr3 = ptr1->next;

    while(ptr3) {
        if (ptr3->val <= ptr1->val) {
            ptr2->next = ptr3->next;
            ptr3->next = ptr1;
            ptr1 = ptr3;
            ptr3 = ptr2->next;
        }
        else if (ptr3->val >= ptr2->val) {
            ptr2 = ptr3;
            ptr3 = ptr3->next;
            ptr2->next = ptr3;
        }
        else {
            ListNode* temp = ptr1->next;
            ListNode* preTemp = ptr1;
            while(temp->val < ptr3->val) {
                temp = temp->next;
                preTemp = preTemp->next;
            }
            preTemp->next = ptr3;
            ptr2->next = ptr3->next;
            ptr3->next = temp;
            ptr3= ptr2->next;
        }
    } 
    return ptr1;
    
}
/* int main()
{
    int arr[] = {5 , 66 , 68 , 42 , 73 , 25 , 84 , 63 , 72 , 20 , 77 , 38 , 8 , 99 , 92 , 49 , 74 , 45 , 30 , 51 , 50 , 95 , 56 , 19 , 31 , 26 , 98 , 67 , 100 , 2 , 24 , 6 , 37 , 69 , 11 , 16 , 61 , 23 , 78 , 27 , 64 , 87 , 3 , 85 , 55 , 22 , 33 , 62 };
    ListNode* head = CreateLinkedList(arr, 48);
    insertionSortList(head);
    
    while(head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }

    return 0;
}

 */
 