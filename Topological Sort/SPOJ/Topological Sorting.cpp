#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e4+50;

vector<int> G[N];
int vis[N],start[N],finish[N];
bool cycle;
int somoy;

void dfs(int root){
	vis[root] = 1;
	start[root] = somoy++;
	int siz = G[root].size();
	for(int i=siz-1; i>=0; i--){
		int child = G[root][i];
		if(vis[child] == 1){
			cycle = true;
		}
		if(vis[child] == 0){
			dfs(child);
		}
	}
	finish[root] = somoy++;
	vis[root] = 2;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	int tc=1;
	for(int T=1; T<=tc; T++){
		int node, edge;
		cin>>node>>edge;
		int u, v;
		for(int i=1; i<=edge; i++){
			cin>>u>>v;
			int lb = upper_bound(G[u].begin(), G[u].end(), v) - G[u].begin();
			G[u].insert(G[u].begin()+lb, v);
		}

		for(int i=node; i>=1; i--){
			if(vis[i] == 0){
				dfs(i);
			}
		}

		if(cycle){
			cout<<"Sandro fails.\n";
			return 0;
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
	}
	return 0;
}
