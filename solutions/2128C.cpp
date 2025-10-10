#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve()
{
    // Solution scaffolding
    int n = 0;
    cin >> n;
    vector<int> B(n);
    int b = 0;
    // Read in via reference
    for (int &x : B)
    {
        cin >> x;
    }
    // Actual Logic
    int min_so_far = B[0];
    for (int &b : B)
    {
        if (2 * min_so_far - 1 < b)
        {
            cout << "NO\n";
            return;
        }
        min_so_far = min(min_so_far, b);
    }
    cout << "YES\n";
    return;
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // Uncomment for multiple test cases

    while (t--)
    {
        solve();
    }

    return 0;
}