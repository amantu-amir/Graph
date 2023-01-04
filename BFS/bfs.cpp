///**Bismillahir Rahmanir Rahim.**
//Amantu Amir, University of Barishal, Bangladesh
#include <bits/stdc++.h>
#define int                   long long int
#define clr(a, v)             memset(a,v,sizeof a)
#define all(v)                v.begin(),v.end()
#define ast(v)                sort(all(v))
#define sfs(s)                scanf("%s", s)
#define sf(n)                 scanf("%lld", &n)
#define sff(n, m)             scanf("%lld %lld",&n,&m)
#define dst(v)                sort(all(v),greater<int>())
#define sfff(n, m, o)         scanf("%lld %lld %lld",&n,&m,&o)
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout<<a<<" "<<b<<" "<<c<<"\n"
#define MX(a)                 *max_element(all(a))
#define MI(a)                 *min_element(all(a))
#define SUM(a)                accumulate(all(a),0)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define MIN(a, b, c)          min(a, min(b, c))
#define MAX(a, b, c)          max(a, max(b, c))
#define MID(b, e)             (b+(e-b)/2)
#define CAS(a)                cout << "Case " << a << ":"
#define pf(n)                 printf("%lld", n)
#define pff(n,m)              printf("%lld %lld\n",n,m)
#define prln(n)               printf("%lld\n", n)
#define P(n)                  cout << n
#define debug                 cout << " debug\n"
#define yes                   cout << "Yes\n"
#define no                    cout << "No\n"
#define minus1                cout << "-1\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first

using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
bool is_prime[N+50];
vector<int>prime,primeFactor;
int digit(int n){return log10(n)+1;}
int bit_on(int n,int pos){return n=n|(1<<pos);}
int bit_off(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
string toString(int n){stringstream ss;ss<<n;string s;ss>>s;return s;}
int toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
bool isVowel(char ch){ ch=tolower(ch); if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
double dis(double x, double y, double x2, double y2){double res = sqrt(pow(x-x2,2) + pow(y-y2,2));return res;}
int digit_sum_1toN(int n){if (n<10)return n*(n+1)/2;int d = log10(n);int a[100];a[0] = 0, a[1] = 45;
for (int i=2; i<=d; i++)a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));int p = ceil(pow(10, d));int msd = n/p;
return msd*a[d] + (msd*(msd-1)/2)*p +msd*(1+n%p) + digit_sum_1toN(n%p);}
void sieve(){prime.push_back(2);for(int i=4;i<=N;i+=2)is_prime[i]=1;for(int i=3; i<N; i+=2){if(is_prime[i] == 0)
{prime.push_back(i);for(int j = i*i; j<N; j += (i*2))is_prime[j]=1;}}}
bool isPrime(int n){if(n == 1) return false;if(n == 2) return true;if(n%2 == 0) return false;
for(int i = 3; i * i <= n; i += 2 )if(n%i == 0) return false;return true;}
void primeFac(int n){int tmp = sqrt(n);for(int i = 0; prime[i] <= tmp; i++){if(n%prime[i] == 0)
{while(n%prime[i] == 0){n /= prime[i];primeFactor.pb(prime[i]);}}}if(n > 1)primeFactor.pb(n);}
int SOD(int n){int sum = 1;for(int i = 0; prime[i] <= n; i++){if(n%prime[i] == 0){int cnt = 1;
while(n%prime[i] == 0){n /= prime[i];cnt++;}sum *= (pow(prime[i], cnt) - 1)/ (prime[i] - 1);}}return sum;}
int NOD(int n){int till=sqrt(n+1);int p,divisor=1;for(int i=0;prime[i]<=till;i++){if(n%prime[i]==0){p=1;
while(n%prime[i]==0){n/=prime[i];p++;}till=sqrt(n);divisor*=p;}}if(n>1)divisor*=2;return divisor;}
vector<int> single(vector<int> vec){ast(vec);vec.erase(unique(all(vec)),vec.end()); return vec;}
bool isDigit(char ch){if(ch >= 48 && ch <= 57) return true; else return false;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
//Template end
//-------------------******Alhamdulillah******--------------------//

vector<int>G[N];
bool visited[N];
int level[N];
int dest,paici;
void bfs(int source){
    visited[source]=1;
    level[source]=0;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty() and !paici){
        int parent = Q.front(); Q.pop();
        int siz = G[parent].size();
        for(int i=0; i<siz; i++){
            int child = G[parent][i];
            if(visited[child]==0){
                visited[child]=1;
                level[child]=level[parent]+1;
                Q.push(child);
                if(child==dest){paici=1;break;}
            }
        }
    }
}

int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast();
    int tc = 1;
    for(int T=1; T<=tc; T++){
        int node; II(node,dest);
        int u,v;
        for(int i=1; i<node; i++){
            II(u,v); G[u].pb(v);
            G[v].pb(u);
        }
        bfs(1);
        if(paici) yes;
        else no;
        //P(level[dest]);
    }
    return 0;

}

//--------------------******Alhamdulillah******-------------------//











// #include<iostream>
// using namespace std;

// int adj[100][100], vis[100], Q[100], level[100];

// void bfs(int root) {
//     vis[root] = 1;
//     int L = 100, R = 100;
//     Q[L--] = root;
//     level[root] = 1;
//     while (L <= R) {
//         int u = Q[R--];
//         for (int i = 1; i <= 100; i++) {
//             if (adj[u][i] and !vis[i]) {
//                 Q[L--] = i;
//                 vis[i] = 1;
//                 level[i] = level[u] + 1;
//             }
//         }
//     }
// }

// int main() {
//     int node;
//     cin >> node;
//     int u, v;
//     for (int i = 1; i <= (node - 1); i++) {
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
//     bfs(1);
//     int x;
//     cin >> x;
//     int cnt = 0;
//     for (int i = 1; i <= node; i++) {
//         if (level[i] == x) cnt++;
//     }
//     cout << cnt << "\n";
//     return 0;
// }







