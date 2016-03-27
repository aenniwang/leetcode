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
