#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define miOne cout<<"-1\n";
#define zero cout<<"0\n";
#define rep(i,a,b) for(ll i=a; i<b; i++) 
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
const int N=1e3;

ll mx,node;
ll depth[N+5];
bool vis[N+5];
vector<ll>G[N+5];

void bfs(ll src){
	mx=0;
	vis[src]=1;
	depth[src]=0;
	queue<ll>Q;
	Q.push(src);
	while(!Q.empty()){
		ll par=Q.front();
		Q.pop();
		ll sz=G[par].size();
		for(ll i=0; i<sz; i++){
			ll child=G[par][i];
			if(vis[child]==0){
				vis[child]=1;
				depth[child]=depth[par]+1;
				if(mx<depth[child]){
					mx=depth[child];
					node=child;
				}
				Q.push(child);
			}
		}
	}
}

void solve(ll t){
	ll n,k; cin>>n>>k;
	ll u,v;
	for(ll i=0; i<(n-1); i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	bfs(u);
	for(ll i=0; i<=N; i++){vis[i]=0;}
	bfs(node);
	cout<<mx<<"\n";
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	//pre_calc();

	ll t=1;
	rep(T,1,t+1){
		solve(T);
	}
	return 0;
}

