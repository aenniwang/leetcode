#include<iostream>

using namespace std;

bool isBadVersion(int version){
	return version >= 1702766719;
}

int subfirstBadVersion(long long start, long long end){
	long long cur_version = (start + end) / 2;
	if(isBadVersion(cur_version) && (cur_version == 1 || !isBadVersion(cur_version-1)))
		return cur_version;
	if(isBadVersion(cur_version)){
		return subfirstBadVersion(start, cur_version);
	}else{
		return subfirstBadVersion(cur_version+1, end);
	}
}

int firstBadVersion(int n) {
	return subfirstBadVersion(0, n);
}

int main(){
	cout << "first bad version is: " << firstBadVersion(2126753390)<< endl;
	return 0;
}
