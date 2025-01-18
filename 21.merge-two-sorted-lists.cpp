/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
        /**Plan
         * combine lists into 1 big list
         * poll list 2, keep seperate variable for its index
         */

        ListNode* currNode = list1;
        ListNode* currlist2 = list2;
        while(currNode->next != nullptr) {
            std::cout << "Looped" << std::endl;
            std::cout << "currNode->next: " << currNode->next << std::endl;
            /**
             * if above list1, insert list 2, iterate list 2, iterate list 1
             * else iterate list 1
             */
            // if list 2 has a higher value
            if (currlist2->val > currNode->val) {
                //link to other linked list
                ListNode* temp = currNode->next;
                ListNode* temp2 = currlist2->next;
                currNode->next = currlist2;
                currlist2->next = temp;
                currlist2 = temp2;
            } else {
                currNode = currNode->next;
            }
        }

        //CHANGE CHANGE CHANGE CHANGE CHANGE
        return list1;
    }
};
// @lc code=end

