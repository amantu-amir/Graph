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
const ll N=1010;
const ll mod=1e9+7;

bool vis[N];
ll level[N];
vector<ll>primeFactors[N];
bitset<N+50>isPrime;
vector<ll>prime;

void sieve(){
	isPrime.reset();
	for(ll i=2; (i*i)<=N; i++){
		if(isPrime[i]==0){
			for(ll j=(i*i); j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(ll i=2; i<=N; i++){
		if(isPrime[i]==0){
			prime.pb(i);
		}
	}
}

void calcPrimeFactor(){
	for(ll i=2; i<=1000; i++){
		ll n=i;
		if(isPrime[n]==0){
			continue;
		}
		for(ll j=0; (prime[j]*prime[j])<=n; j++){
			if(n%prime[j]==0){
				primeFactors[i].pb(prime[j]);
				while(n%prime[j]==0){
					n/=prime[j];
				}
			}
		}
		if(n>1){
			primeFactors[i].pb(n);
		}
	}
}

ll bfs(ll src, ll dest){
	level[src]=0;
	queue<ll>Q;
	Q.push(src);
	while(!Q.empty()){
		ll par=Q.front();
		Q.pop();
		for(auto child:primeFactors[par]){
			ll curr=child+par;
			if(curr>dest){
				continue;
			}
			if(vis[curr]==false){
				Q.push(curr);
				vis[curr]=true;
				level[curr]=level[par]+1;
				if(curr==dest){
					return level[curr];
				}
			}
		}
	}
	return -1;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	sieve();
	calcPrimeFactor();

	ll tt=1; cin>>tt;
	for(ll T=1; T<=tt; T++){
		ll s,t; cin>>s>>t;
		if(s==t){
			cout<<"Case "<<T<<": 0\n";
			continue;
		}
		ll res=bfs(s,t);
		cout<<"Case "<<T<<": "<<res<<"\n";
		memset(vis,false,sizeof(vis));
	}
	return 0;
}


