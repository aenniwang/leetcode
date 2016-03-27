
bool wordPattern(string pattern, string str){

	map<char, string> pattern_str;
	set<string> appeared_char;
	stringstream ss(str);
	string buf;
	for(int i=0; i<pattern.length(); i++){
		ss >> buf;
		if(pattern_str.find(pattern[i]) == pattern_str.end()){
			if(appeared_char.find(buf) != appeared_char.end())
				return false;
			pattern_str[pattern[i]] = buf;
			appeared_char.insert(buf);
		}else{
			if(pattern_str[pattern[i]] != buf)
				return false;
		}
	}
	if(ss >> buf)
		return false;
	return true;
}

