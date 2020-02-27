#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e4+50;

vector<int> G[N];
int vis[N];
bool cycle;

void reset(){
	cycle = false;
	for(int i=1; i<=N-5; i++){
		G[i].clear(); vis[i] = 0;
	}
}

void dfs(int root){
	vis[root] = 1;
	for(auto child : G[root]){
		if(vis[child] == 1){
			cycle = true;
			return;
		}
		if(vis[child] == 0){
			dfs(child);
		}
	}
	vis[root] = 2;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("lightoj.txt","r",stdin);
    //freopen("lightojOut.txt","w",stdout);
    int tc=1; cin>>tc;
    for(int T=1; T<=tc; T++){
    	reset();
        int n; cin>>n;
        string u, v;
        int curr = 1;
        map<string,int>m;
        for(int i=1; i<=n; i++){
        	cin>>u>>v;
        	if(m[u] == 0){
        		m[u] = curr++;
        	}
        	if(m[v] == 0){
        		m[v] = curr++;
        	}
        	G[m[u]].push_back(m[v]);
        }
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<curr; i++){
        	if(vis[i] == 0){
        		dfs(i);
        		if(cycle) break;
        	}
        }
        if(cycle) cout<<"Case "<<T<<": No\n";
        else cout<<"Case "<<T<<": Yes\n";
    }
    return 0;
}
