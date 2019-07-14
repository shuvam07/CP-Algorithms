#include <bits/stdc++.h>
using namespace std;

#define INF 1<<29
#define MAX 100005


vector < pair < int , int > > v [MAX];   
int dist[MAX];
bool vis[MAX];

void dijkstra(int n){
    
    fill_n(dist,n,INF);                                        // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].second; int w = v[x][i].first;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}

int main(){
    int n,e,wt,src,dest;
    cin>>n>>e;
    int sum = 0;
    for(int i=0;i<e;i++){
        cin>>src>>dest>>wt;
        v[src].push_back(make_pair(wt,dest));
        v[dest].push_back(make_pair(wt,src));
    }
    dijkstra(n);
}
