#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	if(l1 == NULL && l2 == NULL)
		return NULL;
	else if(l1 == NULL)
		return l2;
	else if(l2 == NULL)
		return l1;
	bool isCompareBigger; //not confirm number is bigger or smaller along the list.
	if(l1->next == NULL && l2->next == NULL){
		isCompareBigger = true;
	}else{
		if(l1->next != NULL){
			if(l1->val <= l1->next->val)
				isCompareBigger = true;
			else
				isCompareBigger = false;
		}
		if(l2->next != NULL){
			if(l2->val <= l2->next->val)
				isCompareBigger = true;
			else
				isCompareBigger = false;
		}
	}
	ListNode* l1_cur = l1;
	ListNode* l2_cur = l2;
	ListNode* start;
	if(isCompareBigger){
		if(l1_cur->val <= l2_cur->val){
			start = l1_cur;
			l1_cur = l1_cur->next;
		}else{
			start = l2_cur;
			l2_cur = l2_cur->next;
		}
	}else{
		if(l1_cur->val >= l2_cur->val){
			start = l1_cur;
			l1_cur = l1_cur->next;
		}else{
			start = l2_cur;
			l2_cur = l2_cur->next;
		}
	}
	ListNode* cur = start;
	//start from l1
	while(l1_cur != NULL || l2_cur != NULL){
		if(l1_cur == NULL){
			cur->next = l2_cur;
			l2_cur = l2_cur->next;
		}else if(l2_cur == NULL){
			cur->next = l1_cur;
			l1_cur = l1_cur->next;
		}else{
			if(isCompareBigger){
				if(l1_cur->val >= l2_cur->val){
					cur->next = l2_cur;
					l2_cur = l2_cur->next;
				}else{
					cur->next = l1_cur;
					l1_cur = l1_cur->next;
				}
			}else{
				if(l1_cur->val >= l2_cur->val){
					cur->next = l1_cur;
					l1_cur = l1_cur->next;
				}else{
					cur->next = l2_cur;
					l2_cur = l2_cur->next;
				}
			}
		}
		cur = cur->next;
	}
	return start;
}

int main(){
	ListNode* l1 = new ListNode(5);
	ListNode* l2 = new ListNode(1);
	ListNode* l2_2 = new ListNode(2);
	ListNode* l2_3 = new ListNode(4);
	l2->next = l2_2;
	l2_2->next = l2_3;
	cout << "merge two list: \n";
	ListNode* result = mergeTwoLists(l1, l2);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}
