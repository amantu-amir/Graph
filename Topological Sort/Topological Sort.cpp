#include<bits/stdc++.h>
#define int long long int
using namespace std;

vector<int> G[100];
bool vis[100];
int start[100];
int finish[100];
int somoy = 1;

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
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	int tc=1;
	for(int T=1; T<=tc; T++){
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
		for(int i=0; i<node; i++){
			cout<<p[i].second<<" "<<p[i].first<<"\n";
		}
	}
	return 0;
}
