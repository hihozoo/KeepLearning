/**
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
*/

struct ListNode
{
	int val;
	ListNode* next;
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* a = headA;
		ListNode* b = headB;

		bool aLinked = false;
		bool bLinked = false;
		while (a != nullptr || !aLinked){
			if (a == nullptr && !aLinked){
				a = headB;
				aLinked = true;
			}
			if (b == nullptr && !bLinked){
				b = headA;
				bLinked = true;
			}
			if (a == b){
				return a;
			}
			a = a->next;
			b = b->next;
		}
		return nullptr;
    }
};
