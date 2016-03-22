#include<iostream>
#include<string>
#include<map>

using namespace std;

string getHint(string secret, string guess){
	map<char, int> secret_info;
	map<char, int> guess_info;
	int same_num = 0;
	for(int i=0; i<secret.length(); i++){
		if(secret[i] == guess[i])
			same_num++;
		else{
			if(secret_info.find(secret[i]) != secret_info.end())
				secret_info[secret[i]]++;
			else
				secret_info[secret[i]] = 1;
			if(guess_info.find(guess[i]) != guess_info.end())
				guess_info[guess[i]]++;
			else
				guess_info[guess[i]] = 1;
		}
	}
	map<char, int>::iterator it;
	int wrong_pos = 0;
	for(it=guess_info.begin(); it!=guess_info.end(); ++it){
		if(secret_info.find(it->first) != secret_info.end())
			wrong_pos += it->second > secret_info[it->first] ? secret_info[it->first] : it->second;
	}
	return to_string(same_num) + "A" + to_string(wrong_pos) + "B";

}

int main(){
	string secret = "1807";
	string guess = "7810";
	cout << getHint(secret, guess) << endl;

	return 0;
}
