class solution{

	public:
		int getNumFromChar(const char c){
			if(c=='I')
				return 1;
			else if(c=='V')
				return 5;
			else if(c=='X')
				return 10;
			else if(c=='L')
				return 50;
			else if(c=='C')
				return 100;
			else if(c=='D')
				return 500;
			else if(c=='M')
				return 1000;
			else
				cout << "invalid input char!" << endl;

		}


		int romanToInt(string s){
			if(s.size() < 1)
				return 0;
			else if(s.size() == 1)
				return getNumFromChar(s[0]);
			int final_num = 0;
			for(int i=0; i<s.size()-1; i++){
				int num1 = getNumFromChar(s[i]);
				int num2 = getNumFromChar(s[i+1]);
				if(num1 >= num2){
					final_num += num1;
				}else{
					final_num -= num1;
				}
			}
			final_num += getNumFromChar(s[s.size()-1]);
			return final_num;
		}
};

