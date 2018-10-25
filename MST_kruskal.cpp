#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

struct edge{
	int src;
	int dest;
	int wt;
};

vector <edge> edges;

bool comp(struct edge a,struct edge b){
	return a.wt<b.wt;
}

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
	int n,e,wt,src,dest;
	cin>>n>>e;
	int sum = 0;
	init(n+1);						// n+1 considering index starts from 1
	edges.resize(e);
	for(int i=0;i<e;i++){
		cin>>edges[i].src>>edges[i].dest>>edges[i].wt;

	}
	sort(edges.begin(),edges.end(),comp);
	for(int i=0;i<edges.size();i++){
		int x = find(edges[i].src);
		int y = find(edges[i].dest);
		if(x!=y){
			_union(x,y);
			sum+=edges[i].wt;
		}
	}
	cout<<"Sum of Weights = " << sum<<endl;
}