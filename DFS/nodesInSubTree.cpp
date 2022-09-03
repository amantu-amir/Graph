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
const ll N=2e6+50;
const ll mod=1e9+7;

ll subTreeSize[N];
vector<ll>adj[N];

void dfs(ll root){
	if(adj[root].size()==0){
		subTreeSize[root]=1;
		return;
	}
	for(auto i:adj[root]){
		dfs(i);
	}
	ll tot=0;
	for(auto i:adj[root]){
		tot+=subTreeSize[i];
	}
	subTreeSize[root]=tot+1;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	//Given a tree and you have find the number of nodes in each subtree

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll node;
		cin>>node;
		ll edge=node-1,u,v;
		for(ll i=0; i<edge; i++){
			cin>>u>>v;
			adj[u].pb(v);
		}
		dfs(1);
		ll Q,x; 
		cin>>Q;
		while(Q--){
			cin>>x;		//number of nodes in this subtree 
			ll res=subTreeSize[x];
			cout<<res<<"\n";
		}
	}
	return 0;
}

/*
7
1 2
1 3
1 4
3 5
3 7
5 6
3
1
5
3
*/

