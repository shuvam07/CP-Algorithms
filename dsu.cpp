#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int parent[MAX];
int rank[MAX];

void init(int n){
	for(int i=0;i<n;i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int i){
	if(i!=parent[i]){
		parent[i] = find(parent[i]);
	}
	return parent[i];
}

void _union(int x,int y){

	int xroot = find(x);
	int yroot = find(y);

	if(rank[xroot]<rank[yroot]){
		parent[xroot] = yroot;
	}
	else if(rank[yroot]<rank[xroot]){
		parent[yroot] = xroot;
	}
	else{
		parent[yroot] = xroot;
		rank[xroot]++;
	}
}


int main(){
	init(10);
	cout<<find(5)<<endl;
	_union(5,6);
	cout<<find(4)<<endl;
	_union(5,7);
	cout<<find(7)<<endl;
}