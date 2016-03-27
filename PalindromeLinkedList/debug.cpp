#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head){
	if(head == NULL || head->next == NULL)
		return true;
	stack<int> appeared_num;
	ListNode* cur = head;
	while(cur){
		appeared_num.push(cur->val);
		cur = cur->next;
	}
	cur = head;
	while(cur){
		if(cur->val!=appeared_num.top())
			return false;
		cur = cur->next;
		appeared_num.pop();
	}
	return true;
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(2);
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	cout << "is Palindrome? " << isPalindrome(head) << endl;

	return 0;
}
