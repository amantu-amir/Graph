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

vector<ll>SCC;
vector<ll>G[30],Trans_G[30];
ll vis[30],somoy,start[30],finish[30];

void pre_process(ll src){
	vis[src]=1;
	start[src]=somoy++;
	for(auto i:G[src]){
		if(vis[i]==0){
			pre_process(i);
		}
	}
	finish[src]=somoy++;
}

void dfs(ll src){
	vis[src]=1;
	SCC.pb(src);
	for(auto i:Trans_G[src]){
		if(vis[i]==0){
			dfs(i);
		}
	}
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1,cas=1;
	for(ll T=1; T<=t; T++){
		ll n,m;
		while(cin>>n>>m){
			if((n+m)==0){break;}
			string u,v;
			ll curr=0;
			unordered_map<string,ll>mp;
			unordered_map<ll,string>M;
			for(ll i=0; i<m; i++){
				cin>>u>>v;
				if(mp[u]==0){
					mp[u]=++curr;
				}
				M[mp[u]]=u;
				if(mp[v]==0){
					mp[v]=++curr;
				}
				M[mp[v]]=v;
				G[mp[u]].pb(mp[v]);
				Trans_G[mp[v]].pb(mp[u]);
			}
			for(ll i=1; i<=n; i++){
				if(vis[i]==0){
					pre_process(i);
				}
			}
			vector<pair<ll,ll>>P;
			for(ll i=1; i<=n; i++){
				P.pb({finish[i],i});
			}
			sort(all(P));
			reverse(all(P));
			memset(vis,0,sizeof(vis));
			if(cas!=1){cout<<"\n";}
			cout<<"Calling circles for data set "<<cas++<<":\n";
			for(ll i=0; i<n; i++){
				if(vis[P[i].S]==0){
					dfs(P[i].S);
					ll siz=SCC.size();
					for(ll j=0; j<siz; j++){
						cout<<M[SCC[j]];
						if(j!=(siz-1)){
							cout<<", ";
						}
					}cout<<"\n";
					SCC.clear();
				}
			}
			somoy=0;
			for(ll i=0; i<30; i++){
				vis[i]=0;
				G[i].clear();
				Trans_G[i].clear();
			}
		}
	}
	return 0;
}



