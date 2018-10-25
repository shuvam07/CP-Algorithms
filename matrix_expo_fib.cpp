#include <bits/stdc++.h>
using namespace std;

#define N 10000
#define ll long long int

void mult(ll F[2][2], ll M[2][2]){
	ll x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	ll y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	ll z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	ll w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(ll A[2][2],ll n){
	if(n==0 || n==1)
		return;
	ll y[2][2] = {{1,1},{1,0}};
	power(A, n/2); 
	mult(A, A); 
	  
	if (n%2 != 0) 
	   mult(A, y); 
}

ll fib(ll n){
	if(n==0)
		return 0;
	ll A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

int main() {
	ll n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}
