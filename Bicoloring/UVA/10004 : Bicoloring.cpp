#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18;
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

ll cnt;
ll vis[500];
ll color[500];
vector<ll>G[500];

bool isBicolor(ll src){
	vis[src]=1;
	cnt++;
	color[src]=cnt%2;
	for(auto i:G[src]){
		if(vis[i]==1){
			if(color[src] == color[i]){	//back edge
				return false;
			}
		}
		if(vis[i]==0){
			isBicolor(i);
		}
	}
	vis[src]=2;
	return true;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1,n;
	for(ll T=1; T<=t; T++){
		while(cin>>n){
			if(n==0){break;}
			ll edge; cin>>edge;
			ll u,v,start;
			for(ll i=0; i<edge; i++){
				cin>>v>>u;
				G[v].pb(u);
				G[u].pb(v);
				start=u;
			}
			bool ok=isBicolor(start);
			if(ok==false){
				cout <<"NOT BICOLORABLE."<<endl;
			}
			else{
				cout <<"BICOLORABLE."<<endl;
			}
			cnt=0;
			for(ll i=0; i<500; i++){
				vis[i]=false;
				color[i]=0;
				G[i].clear();
			}
		}
	}
	return 0;
}



