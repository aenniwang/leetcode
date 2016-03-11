bool isPalindrome(int x){
	if(x < 0)
		return false;
	else if(x == 0)
		return true;
	int front_pos = 9;
	int ten_pow = pow(10, front_pos);
	while(!(x/ten_pow)){
		--front_pos;
		ten_pow = pow(10, front_pos);
	}
	cout << front_pos << endl;
	for(int i=1; i<=(front_pos+1)/2; ++i){
		int high_pow = pow(10, (front_pos-i+1));
		int low_pow = pow(10, i);
		int high_num = 0;
		int low_num = 0;
		if(i == 1){
			high_num = x / high_pow;
			low_num = x%10;
		}else{
			high_num = (x-high_pow*10*(x/(high_pow*10)))/high_pow;
			low_num = (x%low_pow)/(low_pow/10);
		}
		if(high_num != low_num)
			return false;
	}
	return true;
}
