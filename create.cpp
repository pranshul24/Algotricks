#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> adj[100009];
ll vis[100009] = {0};
ll has_cycle;
void dfs(ll i, ll p)
{
    vis[i] = 1;
    for (ll x : adj[i])
    {
        if (vis[x] == 0)
            dfs(x, i);
        else if (vis[x] == 1 and x != p)
            has_cycle = 1;
    }
}
int main()
{
    ll n, m, x, y, ans = 0;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            has_cycle = 0;
            dfs(i, i);
            if (has_cycle == 0)
                ans++;
        }
    }
    cout << ans;
}