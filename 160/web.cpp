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
