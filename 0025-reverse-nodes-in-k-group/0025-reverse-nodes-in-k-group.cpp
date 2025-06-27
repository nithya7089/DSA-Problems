class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = 0;
        ListNode* temp = head;
        ListNode* ans = head;
        
        while (temp != nullptr) { 
            temp = temp->next;
            c++;
        }  
        
        int b = c / k;
        int d = 0;
        c = 0;
        temp = head;
        ListNode* prevTail = nullptr;  
        ListNode* newHead = nullptr;   
        while (c < b) {
            ListNode* prev = nullptr;
            ListNode* curr = temp;
            ListNode* groupHead = temp;
            
            for (d = 0; d < k && curr != nullptr; d++) {  
                ListNode* ne = curr->next;
                curr->next = prev;
                prev = curr;
                curr = ne;
            }
            
            if (newHead == nullptr) {
                newHead = prev;  
            }
            
            if (prevTail != nullptr) {
                prevTail->next = prev;
            }
            prevTail = groupHead;
            temp = curr;
            c++;
        }
        
        if (prevTail != nullptr) {
            prevTail->next = temp;
        }
        
        return newHead ? newHead : head;
    }
};
