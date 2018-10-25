#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int prime[MAX];
vector <int> primes;

void sieve(){
	memset(prime,1,sizeof(prime));
	prime[0] = 0,prime[1] = 0;
	for(int p=2;p<MAX;p++){
		if(prime[p]){
			for(int j=2*p;j<MAX;j+=p){
				prime[j] = 0;
			}
		}
	}


	// get all the primes in a vector 
	
	for(int i=0;i<MAX;i++){
		if(prime[i]){
			primes.push_back(i);
		}
	}
}



int main(){
	sieve();

	/******    Getting the prime Factors    ******/
	//To get the sum of prime factors of a number just keep on adding p to prime[j] 
}