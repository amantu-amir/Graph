#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,a,b) for(ll i=a; i<b; i++) 
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//
const int N=1e6;


bool vis[N+5];
vector<ll>scc;
ll start[N+5],finish[N+5],somoy;
vector<ll>adj[N+5],trans_adj[N+5];

void pre_process(ll root){
	vis[root]=1;
	start[root]=somoy++;
	for(auto child:adj[root]){
		if(vis[child]==0){
			pre_process(child);
		}
	}
	finish[root]=somoy++;
}

void dfs(ll root){
	vis[root]=1;
	scc.pb(root);
	for(auto child:trans_adj[root]){
		if(vis[child]==0){
			dfs(child);
		}
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	rep(T,1,t+1){
		ll node,edge;
		cin>>node>>edge;
		ll u,v;
		rep(i,0,edge){
			cin>>u>>v;
			adj[u].pb(v);
			trans_adj[v].pb(u);
		}
		rep(i,1,node+1){
			if(vis[i]==0){
				pre_process(i);
			}
		}
		vector<pair<ll,ll>>P;
		rep(i,1,node+1){
			P.pb({finish[i],i});
		}
		sort(all(P));
		reverse(all(P));
		memset(vis,0,sizeof(vis));
		rep(i,0,node){
			if(vis[P[i].S]==0){
				scc.clear();
				dfs(P[i].S);
				ll sz=scc.size();
				rep(j,0,sz){
					cout<<scc[j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}



