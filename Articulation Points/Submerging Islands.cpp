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
const int N=1e5+50;

ll timer;
ll vis[N+5];
set<ll>cut_points;
ll low[N+5],in[N+5];
vector<ll>adj[N+5];

void dfs(ll node,ll par){
	vis[node]=1;
	ll subtree=0;
	low[node]=in[node]=timer++;
	for(auto child:adj[node]){
		if(child==par){continue;}
		if(vis[child]==1){
			low[node]=min(low[node],in[child]);
		}
		else if(vis[child]==0){
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node] and par!=-1){
				cut_points.insert(node);
			}
			subtree++;
		}
	}
	vis[node]=2;
	if(par==-1 and subtree>1){
		cut_points.insert(node);
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	while(1){
		ll node,edge;
		cin>>node>>edge;
		if((node+edge)==0){
			break;
		}
		timer=0;
		cut_points.clear();
		rep(i,0,N){
			adj[i].clear();
			vis[i]=0;
		}
		ll u,v;
		rep(i,0,edge){
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(u,-1);
		cout<<cut_points.size()<<"\n";
	}
	return 0;
}

