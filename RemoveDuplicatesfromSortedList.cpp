﻿/**
 * Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* temp_head = head;

		while (head)
		{
			if (!head->next) {
				return temp_head;
			}

			if (head->val == head->next->val) {
				ListNode* to_del = head->next;
				head->next = head->next->next;
				delete to_del;
			}
			else {
				head = head->next;
			}
		}

		return temp_head;
	}
};