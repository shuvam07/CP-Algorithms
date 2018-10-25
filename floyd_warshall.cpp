/*** All pair shortest path algo ***/


#include<bits/stdc++.h>
using namespace std;

#define INF 1<<29			// Dont make it INT_MAX since integer will overflow on addition and become negative
#define MAX 1003

int dp[MAX][MAX];

void floyd(int n){
	int e,src,dest,wt;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j)
				dp[i][j] = INF;
			else dp[i][j] = 0;
		}
	}

	cin>>e;

	for(int i=0;i<e;i++){
		cin>>src>>dest>>wt;
		dp[src][dest] = wt;
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((dp[i][k]+dp[k][j])<dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j] == 1<<29)
				cout<<-1<<" ";
			else	
				cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}



int main(){
	int n;
	cin>>n;
	floyd(n);
}