#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
	if(headA == NULL || headB == NULL)
		return NULL;
	ListNode* endA;
	ListNode* endB;
	ListNode* pA, *pB; 

	pA = headA;
	pB = headB;
	endA = NULL;
	endB = NULL;

	while(true){
		if(pA == NULL && pB == NULL && endA != endB)
			return NULL;
		if(pA == NULL)
			pA = headB;
		if(pB == NULL)
			pB = headA;
		if(pA->next == NULL)
			endA = pA; 
		if(pB->next == NULL)
			endB = pB; 
		if(pA == pB) 
			return pA; 
		pA = pA->next;
		pB = pB->next;
	}
}

int main(){
	ListNode* result;
	
	ListNode* headA = new ListNode(1);
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(5);
	ListNode* node3 = new ListNode(6);
	ListNode* node4 = new ListNode(7);
	ListNode* node5 = new ListNode(9);
	ListNode* node6 = new ListNode(11);
	ListNode* node7 = new ListNode(13);
	ListNode* node8 = new ListNode(15);
	ListNode* node9 = new ListNode(17);
	headA->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;

	ListNode* headB= new ListNode(17);
	headB->next = node7;

	result = getIntersectionNode(headA, headB);
	if(result != NULL)
		cout << "intersect node: " << result->val << endl;
	else
		cout << "no intersection!" << endl;

	return 0;
}
