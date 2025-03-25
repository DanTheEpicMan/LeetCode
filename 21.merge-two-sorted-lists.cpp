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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //Checks for NULL-ness
        if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        }

        
        //Assumes both not null
        ListNode* head;
        if (list1->val < list2->val) {
            head = new ListNode(list1->val, list1->next);
            list1 = list1->next;
        } else {
            head = new ListNode(list2->val, list2->next);
            list2 = list2->next;
        }

        ListNode* headStart = head;
        
        while(true) {
            //Handaling NULL
            if (list1 == NULL) {
                head->next = list2;
                break;
            }
            
            if (list2 == NULL) {
                head->next = list1;
                break;
            }

            //Checking for list2 > list1
            //Sets the value of new listnode
            //Itterates LN
            ListNode* newLN = new ListNode();
            if (list2->val < list1->val) {
                newLN->val = list2->val;
                list2 = list2->next;
            } else {
                newLN->val = list1->val;
                list1 = list1->next;
            }

            //Sets previous LN to point to new LN
            head->next = newLN;

            //Pointer now points to a new value in memory
            head = head->next;
        }
        return headStart;
    }
};
