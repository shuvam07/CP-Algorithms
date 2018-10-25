#include <bits/stdc++.h>
using namespace std;

#define INF 1<<29
#define MAX 1003

int adj[MAX][MAX], dist[MAX]; 
bool vis[MAX];

void dijkstra(int n,int src){

    int u,v,wt,e;
    cin>>e;

    fill_n(&adj[0][0], MAX*MAX, INF);

    for(int i=0;i<e;i++){
        cin>>u>>v>>wt;
        adj[u][v] = adj[v][u] = min(adj[u][v], wt);
    }

    fill(dist, dist+MAX, INF);

    dist[src] = 0;
    for(int i=1; i<=n; i++){
        int d=INF,u=0;
        for(int j=1; j<=n; j++)
            if(!vis[j] && dist[j]< d){
                d=dist[j]; u=j;
            }
        vis[u] = 1;
        for(int j=1; j<=n; j++)
            if(!vis[j])
                dist[j]=min(dist[j], dist[u]+adj[u][j]);
    }

    for(int i=0; i<n; i++)
        if(vis[i]) cout << dist[i] << endl;
        else cout << -1 << endl;
}
int main(){
    int n,src;
    cin>>n>>src;
    dijkstra(n,src);
    
}