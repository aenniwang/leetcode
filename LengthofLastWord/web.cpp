
int lengthOfLastWord(string s){
	if(s == "")
		return 0;
	string s_without_last(s.begin(), s.begin()+s.length());
	while(s_without_last[s_without_last.length()-1] == ' ')
		s_without_last.pop_back();
	cout << s_without_last << endl;
	size_t found = s_without_last.find_last_of(' ');
	if(found == s_without_last.length()-1){
		return  0;
	}else
		return  s_without_last.length() - found - 1;
}

