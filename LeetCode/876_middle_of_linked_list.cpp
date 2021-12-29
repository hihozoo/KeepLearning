
/**
 *
 * 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
	如果有两个中间结点，则返回第二个中间结点。
*/
struct ListNode{
	int val;
	ListNode* next;
};

class Solution {
public:
	//链表的缺点在于不能通过下标访问对应的元素。因此我们可以考虑对链表进行遍历，同时将遍历到的元素依次放入数组 A 中。如果我们遍历到了 N 个元素，那么链表以及数组的长度也为 N，对应的中间节点即为 A[N/2]。
    ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
    }
};

