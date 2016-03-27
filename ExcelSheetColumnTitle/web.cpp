
string convertToTitle(int n){
	if(n == 0)
		return "";
	string result;
	int num_pow = 1;
	long long alph_pow = pow(26, num_pow);
	if(n <= 26){
		result.push_back('A'-1+n);
	}else{
		int remainder = 0;
		int last_remainder = 0;
		int num = n;
		while(alph_pow/26 < num){
			num -= last_remainder;
			remainder = num % alph_pow;
			if(remainder == 0){
				result.push_back('Z');
				last_remainder = alph_pow;
			}else{
				result.push_back(remainder / (alph_pow / 26) + 'A'-1);
				last_remainder = remainder;
			}
		alph_pow *= 26;
		}
	}
	reverse(result.begin(), result.end());
	return result;

}

