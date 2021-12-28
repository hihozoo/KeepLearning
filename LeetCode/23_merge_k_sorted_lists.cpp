/**
 * 给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNodeCmp {
	bool operator()(ListNode* a, ListNode* b){
		return a->val > b->val;
	}
};

class Solution {
public:
	/**
	 * 利用二叉堆处理每个链表的 head，
	 * 每次pop出最小值，然后再插入被 pop 出的那个链表新 head
	*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, \
		vector<ListNode*>, ListNodeCmp> queue;

		for (vector<ListNode*>::iterator it = lists.begin();
			it != lists.end(); it++){
			if (*it){
				queue.push(*it);
			}
		}

		ListNode* p = new ListNode();
		ListNode* dummy = p;
		while(!queue.empty()){
			ListNode* n = queue.top();
			p->next = n;
			queue.pop();
			if (n->next != nullptr){
				queue.push(n->next);
			}
			p = p->next;
		}

		return dummy->next;
    }
};
