
int trailingZeroes(int n){
	int num_zeros = 0;
	long long tmp=5;
	while(n >= tmp){
		num_zeros += n/tmp;
		tmp *= 5;
	}
	return num_zeros;
}

