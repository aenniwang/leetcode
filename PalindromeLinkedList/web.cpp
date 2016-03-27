
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

