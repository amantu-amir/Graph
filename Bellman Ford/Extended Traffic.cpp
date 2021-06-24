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
const ll N=2e5+50;
const ll mod=1e9+7;

class info{
public:
	ll U,V,W;
};

info adj[N];
ll dist[N],node,edge;

void bellmanFord(ll source){
	for(ll i=0; i<(N-5); i++){
		dist[i]=inf;
	}
	dist[source]=0;
	for(ll i=1; i<=(node-1); i++){
		for(ll j=0; j<edge; j++){
			ll u=adj[j].U, v=adj[j].V, w=adj[j].W;
			if(dist[u]!=inf and (dist[u]+w)<dist[v]){
				dist[v]=dist[u]+w;
			}
		}
	}
	//Checking for negative cycle
	for(ll i=0; i<edge; i++){
		ll u=adj[i].U, v=adj[i].V, w=adj[i].W;
		if((dist[u]+w)<dist[v]){
			dist[v]=inf;
		}
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		cin>>node;
		vector<ll>busyness(node+5);
		for(ll i=1; i<=node; i++){
			cin>>busyness[i];
		}
		cin>>edge; ll aa;
		for(ll i=0; i<edge; i++){
			cin>>adj[i].U>>adj[i].V;
			aa=busyness[adj[i].V]-busyness[adj[i].U];
			adj[i].W=aa*aa*aa;
		}
		bellmanFord(1);
		ll q,dest; cin>>q;
		cout<<"Case "<<T<<":\n";
		while(q--){
			cin>>dest;
			if(dist[dest]==inf or dist[dest]<3){
				cout<<"?\n";
			}
			else{
				cout<<dist[dest]<<"\n";
			}
		}
	}
	return 0;
}

