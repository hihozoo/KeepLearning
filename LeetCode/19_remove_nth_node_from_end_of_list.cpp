/**
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

struct ListNode
{
	int val;
	ListNode* next;
};


class Solution {
public:
	/*
		分成多种情况
		1）删除的是第一个元素时，快指针应该走到了链表尾部，所以当 fast == nullptr 的时候，就意味着要删除
		2）删除不是第一个元素时，只需要删除的前一个节点修改指针指向即可
	*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (n >= 1){
			fast = fast->next;
			n--;
		}

		while (fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next;
		}

		if (fast == nullptr){
			head = head->next;
		}
		else{
			slow->next = slow->next->next;
		}

		return head;
    }
};

