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

ll timer;
bool bridge;
ll vis[N+5];
ll in[N+5],low[N+5];
vector<ll>adj[N+5];
vector<pair<ll,ll>>res;

void dfs(ll node,ll par){
	vis[node]=1;
	in[node]=low[node]=timer++;
	for(auto child:adj[node]){
		if(child==par){continue;}
		if(vis[child]==1){
			low[node]=min(low[node],in[child]);
			res.pb({node,child});
		}
		else if(vis[child]==0){
			dfs(child,node);
			res.pb({node,child});
			if(low[child]>in[node]){
				bridge=true; return;
			}
			low[node]=min(low[node],low[child]);
		}
	}
	vis[node]=2;
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
			adj[v].pb(u);
		}
		dfs(u,-1);
		if(bridge==true){
			cout<<"0\n";
		}
		else{
			reverse(all(res));
			for(auto i:res){
				cout<<i.F<<" "<<i.S<<"\n";
			}
		}
	}
	return 0;
}

