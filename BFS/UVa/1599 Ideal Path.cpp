#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define F first
#define S second
#define aint(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e9+5
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[]={1,-1,0,0};
// int dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//typedef tree<int, nuint_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const int P=29;
const int N=2e5+50;
const int mod=1e9+7;

bool vis[N];
vector<pair<int,int>> adj[N];

void bfs(int root, vector<int>& dis){
    vis[root]=1;
    dis[root]=0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        for(auto i : adj[u]){
            if(!vis[i.F]){
                vis[i.F]=1;
                Q.push(i.F);
                dis[i.F]=dis[u]+1;
            }
        }
    }
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    for(int T=1; T<=t; T++){
        int node, edge;
        while(scanf("%d %d", &node, &edge)==2){
            for(int i=0; i<=node; i++){
                adj[i].clear(), vis[i]=0;
            }
            int u, v, c;
            for(int i=1; i<=edge; i++){
                scanf("%d %d %d", &u, &v, &c);
                if(u==v) continue;
                adj[u].pb({v, c});
                adj[v].pb({u, c});
            }

            vector<int> distRoot(node+5, inf), distGoal(node+5, inf);
            bfs(1, distRoot);
            for(int i=0; i<=node; i++) vis[i]=0;
            bfs(node, distGoal);

            int minDist=distRoot[node];
            for(int i=0; i<=node; i++) vis[i]=0;
            vector<int> preColor(node+5, inf), color(minDist+5, inf);
            queue<int> Q;
            Q.push(1);
            while(!Q.empty()){
                int root=Q.front();
                Q.pop();
                if(root!=1 and preColor[root]!=color[distRoot[root]]){
                    continue;
                }
                for(auto j:adj[root]){
                    if((distRoot[j.F]-distRoot[root])==1 and (distRoot[j.F]+distGoal[j.F])==minDist){
                    	preColor[j.F]=min(preColor[j.F], j.S);
                        color[distRoot[j.F]]=min(color[distRoot[j.F]], j.S);
                        if(!vis[j.F]){
                            vis[j.F]=1;
                            Q.push(j.F);
                        }
                    }
                }

            }
            printf("%d\n", minDist);
            for(int i=1; i<=minDist; i++){
                printf("%d", color[i]);
                if(i!=minDist) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}



/*


4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1
//2->1 3

6 7
1 2 1
1 3 2
1 4 1
2 3 1
3 6 3
4 5 1
5 6 1
//2->2 3


6 8
1 2 1
1 3 2
1 4 1
2 3 1
3 6 3
4 5 1
5 6 1
2 6 4
//2->1 4

10 14
1 2 2
1 3 2
1 4 1
1 5 1
2 9 1
2 6 1
9 6 2
6 7 2
3 7 3
4 8 3
7 8 4
5 8 4
8 10 2
8 10 1


6 6
1 2 1
1 3 1
2 4 4
3 5 5
5 6 2
4 6 50


*/
