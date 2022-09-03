#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=2e5+50;
const ll mod=1e9+7;

ll vis[N], cnt;
vector<ll> adj[N];

void dfs(ll root){
	cnt++;
	vis[root]=1;
	for(auto i:adj[root]){
		if(vis[i]==0){
			dfs(i);
		}
	}
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	cin>>t;
	for(ll T=1; T<=t; T++){
		ll node, edge;
		cin>>node>>edge;
		for(ll i=0; i<=node; i++){
			adj[i].clear(), vis[i]=0;
		}
		ll u, v;
		for(ll i=1; i<=edge; i++){
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ll comp=0, ans=1;
		for(ll i=1; i<=node; i++){
			if(!vis[i]){
				comp++, cnt=0;
				dfs(i);
				ans=(ans*cnt)%mod;
			}
		}
		cout<<comp<<" "<<ans<<"\n";
	}
	return 0;
}




