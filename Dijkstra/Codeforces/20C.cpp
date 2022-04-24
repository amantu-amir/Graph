#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e5+50;
const ll mod=1e9+7;

ll dist[N],parent[N];
vector<pair<ll,ll>>adj[N];
void dijkstra(ll root){
	for(ll i=0; i<(N-5); i++){
		dist[i]=inf;
	}dist[root]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>PQ;
	PQ.push({0,root});
	parent[root]=-1;
	while(!PQ.empty()){
		ll u=PQ.top().S;
		PQ.pop();
		ll siz=adj[u].size();
		for(ll i=0; i<siz; i++){
			ll v=adj[u][i].F, cost=adj[u][i].S;
			if((dist[u]+cost)<dist[v]){
				parent[v]=u;
				dist[v]=dist[u]+cost;
				PQ.push({dist[v],v});
			}
		}
	}
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll node,edge;
		cin>>node>>edge;
		ll u,v,w;
		for(ll i=0; i<edge; i++){
			cin>>u>>v>>w;
			adj[u].pb({v,w});
			adj[v].pb({u,w});
		}
		dijkstra(1);
		if(dist[node]==inf){
			cout<<"-1\n";
			return 0;
		}
		vector<ll>path;
		path.pb(node);
		while(parent[node]!=-1){
			path.pb(parent[node]);
			node=parent[node];
		}
		ll siz=path.size();
		for(ll i=siz-1; i>=0; i--){
			cout<<path[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}



