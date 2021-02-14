#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e2+50;

vector<int> G[N];
bool vis[N];
int start[N],finish[N];
int somoy;

void reset(){
	somoy = 0;
	for(int i=1; i<=N-5; i++){
		G[i].clear(); vis[i] = false;
	}
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
	int tc=1;
	for(int T=1; T<=tc; T++){
		int node, edge;
		while(cin>>node>>edge){
			if(node+edge == 0) break;
			reset(); int u,v;
			for(int i=1; i<=edge; i++){
				cin>>u>>v;
				G[u].push_back(v);
			}
			for(int i=1; i<=node; i++){
				if(vis[i] == false){
					dfs(i);
				}
			}
			vector<pair<int,int>>order;
			for(int i=1; i<=node; i++){
				order.push_back(make_pair(finish[i], i));
			}
			sort(order.begin(), order.end());
			reverse(order.begin(), order.end());
			for(int i=0; i<node; i++){
				cout<<order[i].second<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
