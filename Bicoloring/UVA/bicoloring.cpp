#include<iostream>
using namespace std;

typedef long long ll;
const int N=2e5+50;
const int mod=1e9+7;


ll adj[210][210], vis[210], node, color[210];

bool bfs(ll root){
	vis[root]=1;
	ll Q[node+5], L=0, R=0;
	Q[R++]=root;
	color[root]=1;
	while(L<R){
		ll u=Q[L++];
		for(ll v=0; v<node; v++){
			ll ck=adj[u][v];
			if(ck!=-1){
				if(vis[v]==1 and (color[u]==color[v])){
					return false;
				}
				if(vis[v]==0){
					Q[R++]=v;
					vis[v]=1;
					color[v]=(color[u]+1)%3;
				}
			}
		}
	}
	return true;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while(cin>>node){
		if(node==0){
			break;
		}
		for(ll i=0; i<=node; i++){
			vis[i]=0;
			for(ll j=0; j<=node; j++){
				adj[i][j]=-1;
			}
		}
		ll edge;
		cin>>edge;
		ll u,v,root=node+5;
		for(ll i=0; i<edge; i++){
			cin>>u>>v;
			adj[u][v]=1;
			adj[v][u]=1;
			root=min(root, min(u,v));
		}
		bool isBicolorable=bfs(root);
		if(isBicolorable){
			cout<<"BICOLORABLE.\n";
		}
		else{
			cout<<"NOT BICOLORABLE.\n";
		}
	}
	return 0;
}


