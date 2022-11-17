#include<bits/stdc++.h>
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
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P=29;
const ll M=2e6;
const ll N=2e5+50;
const ll mod=1e9+7;

ll Time;
bool vis[N];
vector<ll> adj[N];
ll start[N], finish[N], tree[M];

void dfs(ll root){
    vis[root]=1;
    start[root]=++Time;
    for(auto i:adj[root]){
        if(vis[i]==0){
            dfs(i);
        }
    }
    finish[root]=++Time;
}

void update(ll node, ll b, ll e, ll idx, ll val){
    if(b==e){
        tree[node]=val;
        return;
    }
    ll mid=b+(e-b)/2;
    if(mid>=idx) update(node*2, b, mid, idx, val);
    else update(node*2+1, mid+1, e, idx, val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll b, ll e, ll L, ll R){
    if(b>R or e<L or b>e) return 0;
    if(b>=L and e<=R){
        return tree[node];
    }
    ll mid=b+(e-b)/2;
    ll q1=query(node*2, b, mid, L, R);
    ll q2=query(node*2+1, mid+1, e, L, R);
    return q1+q2;
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n, q;
        cin>>n>>q;
        vector<ll> A(n);
        for(ll i=0; i<n; i++){
            cin>>A[i];
        }
        ll u, v;
        for(ll i=0; i<(n-1); i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        for(ll i=1; i<=n; i++){
            update(1, 1, Time, start[i], A[i-1]);
        }
        while(q--){
            ll type, curr;
            cin>>type>>curr;
            ll L=start[curr], R=finish[curr];
            if(type==1){
                ll val;
                cin>>val;
                update(1, 1, Time, L, val);
            }
            else{
                ll res=query(1, 1, Time, L, R);
                cout<<res<<"\n";
            }
        }
    }
    return 0;
}





