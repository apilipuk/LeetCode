#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;

        while(nodeA!=nodeB){
            nodeA = nodeA ? nodeA->next : headB;
            nodeB = nodeB ? nodeB->next : headA;
        }

        return nodeA;
    }
};

// class Solution {
//    public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *nodeA = headA;
//         ListNode *nodeB = headB;
//         ListNode *nodeInter = nullptr;

//         int sizeMin = std::min(size(headA), size(headB));

//         while(sizeMin < size(nodeA)) {
//             nodeA = nodeA->next;
//         }

//         while(sizeMin < size(nodeB)) {
//             nodeB = nodeB->next;
//         }

//         while(nodeA && nodeB) {
//             if(nodeA == nodeB) {
//                 if(!nodeInter) {
//                     nodeInter = nodeA;
//                 }
//             } else {
//                 nodeInter = nullptr;
//             }

//             nodeA = nodeA->next;
//             nodeB = nodeB->next;
//         }

//         return nodeInter;
//     }

//    private:
//     int size(ListNode *node) {
//         int size = 0;

//         while(node) {
//             node = node->next;
//             size++;
//         }

//         return size;
//     }
// };