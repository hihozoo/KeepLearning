/**
 *给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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

struct ListNode{
	int val;
	ListNode *next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode();
		ListNode* head = dummy;

		int carry = 0;
		while (l1 || l2){
			int val1 = 0;
			int val2 = 0;
			if (l1){
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2){
				val2 = l2->val;
				l2 = l2->next;
			}
			int temp = val1 + val2 + carry;
			carry = temp / 10;

			ListNode* node = new ListNode();
			node->val = temp % 10;
			head->next = node;
			head = node;
		}
		if (carry > 0){
			ListNode* node = new ListNode();
			node->val = carry;
			head->next = node;
		}
		head = dummy->next;
		delete dummy;
		return head;
    }
};
