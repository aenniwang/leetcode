#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
	if(head == NULL || n == 0)
		return head;
	vector<ListNode*> node_addr;
	ListNode* cur = head;
	while(cur != NULL){
		node_addr.push_back(cur);
		cur = cur->next;
	}
	int size = node_addr.size();
	if(size-1-n < 0){
		head = head->next;
	}else{
		node_addr[node_addr.size()-n-1]->next \
			= node_addr[node_addr.size()-n]->next;
	}
	return head;
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* result = removeNthFromEnd(head, 1);
	while(result!=NULL){
		cout << result->val << endl;
		result = result->next;
	}

	return 0;
}
