#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b){if(b == 0)return {1, 0};auto t = extended_gcd(b, a % b);return {t.second, t.first - t.second * (a / b)};}
ll modinverse(ll a, ll m){return (extended_gcd(a, m).first % m + m) % m;}
void setup() {
    if (!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}
#define INF 1e15
vector<vector<ll>> dijkstra(ll start, ll N, const vector<vector<pair<ll, ll>>>& graph) {
    vector<vector<ll>> dist = {
        vector<ll>(N, INF),
        vector<ll>(N, -1)
    };
    priority_queue<pair<ll, ll>> pq;

    dist[0][start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        const ll cur_dist = -pq.top().first;
        const ll cur_node = pq.top().second;
        pq.pop();
        if (cur_dist > dist[0][cur_node]) {
            continue;
        }
        for (ll i = 0; i < graph[cur_node].size(); i++) {
            ll nxt_node = graph[cur_node][i].first;
            ll nxt_dist = cur_dist + graph[cur_node][i].second;

            if (nxt_dist < dist[0][nxt_node]) {
                dist[0][nxt_node] = nxt_dist;
                dist[1][nxt_node] = cur_node;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
    return dist;
}
int main(){
    ll N, M;
    cin >> N >> M;
    ll a, b, c;
    vector<vector<pair<ll, ll>>> graph(N);
    for (ll i = 0; i<M; i++) {
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
    }
    ll start, end;
    cin >> start >> end;
    const vector<vector<ll>> ans = dijkstra(start-1, N, graph);
    cout << ans[0][end - 1] << "\n";
    ll current = end - 1;
    vector<ll> path;
    path.push_back(end);
    while (ans[1][current] != -1) {
        path.push_back(ans[1][current] + 1);
        current = ans[1][current];
    }
    cout << path.size() << "\n";
    for (ll i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    return 0;
}
