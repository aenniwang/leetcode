class Solution{
public:
	bool isPowerOfTwo(int n){
		if(n <= 0)
			return false;
		int num_one = 0;
		while(n>0){
			if(n - (n/2)*2 == 1)
				num_one++;
			if(num_one > 1)
				return false;
			else
				n /= 2;
		}
		return true;
	}
};
