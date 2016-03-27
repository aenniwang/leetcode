#include<iostream>
#include<vector>
//#include<cstdio>
//#include<cstdlib>
#include<cstring>

using namespace std;

int countPrimes(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	bool *tags = new bool[n+1];
	
	vector<int> primes;
	memset(tags, true, sizeof(bool) * (n+1));

	for(int i=2; i<n; ++i){
		if(tags[i])
			primes.push_back(i);
		for(int j=0; j<primes.size() && i*primes[j] < n; j++){
			tags[i*primes[j]] = false;
			if(i%primes[j] == 0){
				break;
			}
		}
	}

	return primes.size();

}

int main(){
	cout << "the number of prime is: " << countPrimes(499979) << endl;
	return 0;
}
