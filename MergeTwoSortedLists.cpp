#include<iostream>
#include<conio.h>


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	void set() {
		int n = 0;
		std::cout << "\nEnter data. Stop Ctrl+Z" << "\n? ";

		while (std::cin >> n) {

			if (!next) {
				if (!val) {
					val = n;
				}
				else {
					next = new ListNode(n);
				}
			}
			else {
				ListNode* tempNext = next;

				while (tempNext->next) {
					tempNext = tempNext->next;
				}
				tempNext->next = new ListNode(n);
			}

			std::cout << "? ";
		}

		std::cin.clear();
		std::cout << "list complete.";
	}

	void show() {

		std::cout << "\nlist = " << val;

		ListNode* tempNext = next;

		while (tempNext) {
			std::cout << ' ' << tempNext->val;
			tempNext = tempNext->next;
		}
	}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* result = new ListNode();
		ListNode* head = result;


		while (list1 && list2)
		{
			if (list1->val < list2->val) {
				result->next = list1;
				list1 = list1->next;
			}
			else {
				result->next = list2;
				list2 = list2->next;
			}
			result = result->next;
		}

		if (list1) {
			result->next = list1;
		}
		else if (list2) {
			result->next = list2;
		}

		return head->next;
	}
};

int main() {
	ListNode list1;
	list1.set();
	list1.show();

	ListNode list2;
	list2.set();
	list2.show();

	ListNode* list = Solution().mergeTwoLists(&list1, &list2);
	list->show();

	return 0;
}