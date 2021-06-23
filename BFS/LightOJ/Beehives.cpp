#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//

const ll p=29;
const ll N=2e4+50;
const ll mod=1e9+7;

vector<ll>G[N];
ll vis[N],dist[N];

ll bfs(ll root){
	ll ret=inf;
	dist[root]=0;
	vis[root]=1;
	queue<ll>Q;
	Q.push(root);
	while(!Q.empty()){
		ll par=Q.front(),child;
		Q.pop();
		ll siz=G[par].size();
		for(ll i=0; i<siz; i++){
			child=G[par][i];
			if(vis[child]==0){
				Q.push(child);
				vis[child]=1;
				dist[child]=dist[par]+1;
			}
			else if(vis[child]==1){
				ll diff=dist[child]+dist[par]+1;
				if(diff>2){
					ret=min(ret,diff);
				}
			}
		}
		vis[par]=2;
	}
	return ret;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll res=inf;
		ll n,m; 
		cin>>n>>m;
		ll u,v;
		for(ll i=0; i<m; i++){
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		for(ll i=0; i<n; i++){
			memset(vis,0,sizeof(vis));
			res=min(res,bfs(i));
		}
		cout<<"Case "<<T<<": ";
		if(res==inf){
			cout<<"impossible\n";
		}
		else{
			cout<<res<<"\n";
		}
		for(ll i=0; i<(N-5); i++){
			G[i].clear();
		}
	}
	return 0;
}

