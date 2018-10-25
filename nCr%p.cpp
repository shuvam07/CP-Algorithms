/********
		We know the formula for  nCr 
		nCr = fact(n) / (fact(r) x fact(n-r)) 
		Here fact() means factorial.

		 nCr % p = (fac[n]* modIverse(fac[r]) % p *
		               modIverse(fac[n-r]) % p) % p;
		Here modIverse() means modular inverse under
		modulo p.

******/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll power(ll x,ll y,ll p){

	ll res = 1;
	x = x%p;
	while(y>0){
		if(y&1)
			res = (res * x)%p;
		x = (x * x)%p;
		y = y / 2;
	}
	return res;
}

ll modInv(ll n,ll p){
	return power(n,p-2,p);
}

ll calc(ll n,ll r, ll p){
	if(r==0)
		return 1;
	ll fac[n+1];
	fac[0] = 1;
	for(int i=1;i<=n;i++)
		fac[i] = (fac[i-1]*i)%p;
	return ((fac[n]%p*modInv(fac[r],p))%p*modInv(fac[n-r],p))%p;
}

int main(){

	ll n,r,p;
	cin>>n>>r>>p;
	cout<<calc(n,r,p)<<endl;
}