#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5+50;
vector<int> G[N];
bool vis[N];
int start[N];
int finish[N];
int somoy = 1;

void reset(){
	somoy = 1;
	for(int i=1; i<=N-5; i++){
		G[i].clear();
	}
	memset(vis, false, sizeof(vis));
}

void dfs(int root){
	vis[root] = true;
	start[root] = somoy++;
	for(auto i : G[root]){
		if(vis[i] == false){
			dfs(i);
		}
	}
	finish[root] = somoy++;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int tc=1; cin>>tc;
	for(int T=1; T<=tc; T++){
		reset();
		int node, edge;
		cin>>node>>edge;
		int u, v;
		for(int i=0; i<edge; i++){
			cin>>u>>v;
			G[u].push_back(v);
		}

		for(int i=1; i<=node; i++){
			if(vis[i] == false){
				dfs(i);
			}
		}

		vector<pair<int,int>>p;
		for(int i=1; i<=node; i++){
			p.push_back(make_pair(finish[i],i));
		}

		sort(p.begin(),p.end());
		reverse(p.begin(),p.end());
		memset(vis, false, sizeof(vis));
		
		int res = 0;
		for(int i=0; i<node; i++){
			if(vis[p[i].second] == false){
				res += 1;
				dfs(p[i].second);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
