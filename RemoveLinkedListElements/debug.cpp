#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val){
	if(head == NULL)
		return NULL;
	ListNode* per_node = NULL;
	ListNode* cur_node = head;
	while(cur_node != NULL){
		if(cur_node->val == val){
			if(per_node == NULL){
				head = head->next;
			}else{
				per_node->next = cur_node->next;
			}

		}else{
			per_node = cur_node;
		}
		cur_node = cur_node->next;
	}
	return head;
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(1);
//	ListNode* node4 = new ListNode(4);
//	ListNode* node5 = new ListNode(5);
//	ListNode* node6 = new ListNode(6);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = node6;

	ListNode* result = removeElements(head, 2);
	while(result!=NULL){
		cout << result->val << endl;
		result = result->next;
	}

	return 0;
}
