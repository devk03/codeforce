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
    // Solution code here
    int n = 0;
    cin >> n;
    ll answer = 0;

    // Read in the matrix
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // key intuition here is that there is only n paths (can only go down once)
    vector<int> suf_mn = a[1]; // Bottom row copies
    vector<int> suf_mx = a[1];

    // Work backwards from the end (n-2 down to 0)
    for (int j = n - 2; j >= 0; j--)
    {
        suf_mn[j] = min(suf_mn[j], suf_mn[j + 1]);
        suf_mx[j] = max(suf_mx[j], suf_mx[j + 1]);
    }

    vector<int> anss(2 * n + 2, 2 * n + 1); // intialize with value higher than any 1,...,2n

    int pref_mn = a[0][0];
    int pref_mx = a[0][0];
    for (int j = 0; j < n; j++)
    { // iterating through all the possible paths <-bijection-> switch points bijection
        // prefix
        pref_mn = min(pref_mn, a[0][j]);
        pref_mx = max(pref_mx, a[0][j]);
        int path_min = min(pref_mn, suf_mn[j]);         // true min boundary for path
        int path_max = max(pref_mx, suf_mx[j]);         // true max boundary for path // this path's R
        anss[path_min] = min(anss[path_min], path_max); // store smallest R for the L found
    }
    for (int i = 2 * n; i >= 1; i--)
    { // propogate the smallest R backwards since it should also work for all the values before it
        anss[i] = min(anss[i], anss[i + 1]);
    }

    for (int l = 1; l <= 2 * n; l++)
    {
        if (anss[l] <= 2 * n)
        {
            answer += (2 * n - anss[l] + 1);
        }
    }
    cout << answer << '\n';
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