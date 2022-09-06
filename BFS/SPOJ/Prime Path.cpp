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
const ll N=1e5+50;
const ll mod=1e9+7;

bitset<N+50> isPrime;
unordered_map<string, ll> vis, depth;

ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}

void sieve(){
	isPrime[1]=1;
	for(ll i=2; i<=N; i++){
		if(isPrime[i]==0){
			for(ll j=i*i; j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
}

ll bfs(string root, string goal){
	vis[root]=1;
	queue<string> Q;
	Q.push(root);
	depth[root]=0;
	while(!Q.empty()){
		string u=Q.front();
		if(u==goal) return depth[u];
		Q.pop();
		for(ll i=0; i<4; i++){
			string v=u;
			for(ll j=0; j<=9; j++){
				if(i==0 and j==0) continue;
				v[i]=j+'0';
				if(isPrime[toInt(v)]==0 and vis[v]==0){
					vis[v]=1;
					depth[v]=depth[u]+1;
					Q.push(v);
				}
			}
		}
	}
	return -1;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	sieve();

	ll t=1;
	cin>>t;
	for(ll T=1; T<=t; T++){
		vis.clear();
		ll root, goal;
		cin>>root>>goal;
		ll res=bfs(toString(root), toString(goal));
		cout<<res<<"\n";
	}
	return 0;
}




