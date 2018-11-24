#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair; 


#define INF 1<<29
#define MAX 100005

vector < iPair > v [MAX]; 


int key[MAX];
bool inMST[MAX];
int parent[MAX];

int prims(int n){

	int sum=0;
    
    fill_n(key,n,INF); 
    fill_n(parent,n,-1);                                        
    memset(inMST, false , sizeof inMST);            
    key[0] = 0;
    multiset < pair < int , int > > s;          

    s.insert({0 , 0});  

    int u,wei;                        

    while(!s.empty()){

        pair <int , int> p = *s.begin();        
        s.erase(s.begin());

        u = p.second; wei = p.first;

        inMST[u] = true;

        for(int i = 0; i < v[u].size(); i++){
            int w = v[u][i].first; int e = v[u][i].second;
            if(inMST[e] == false && key[e]>=w){            
                key[e] = w;
                s.insert({key[e], e} );
                parent[e] = u;           
            }
        }
    }

    for (int i = 1; i < n; ++i){
    	printf("%d - %d\n", parent[i], i);
    	sum+=key[i];
    } 

    cout<<endl;
    cout<<sum<<endl; 
    return sum;
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
    int isum = prims(n);
}