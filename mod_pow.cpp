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

int main(){
	ll x,y,p;
	cin>>x>>y>>p;
	cout<<power(x,y,p)<<endl;
}

