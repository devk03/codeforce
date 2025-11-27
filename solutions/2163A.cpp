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
const string yes = "YES\n";
const string no = "NO\n";

void solve()
{
    // Solution code here

    // read in all the values
    int a = 0;
    cin >> a;
    vector<int> arr(a);
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    ;
    // iterate
    sort(arr.begin(), arr.end());
    // a1 <= a2 == a3 <= a4...
    for (int i = 1; i < a - 1; i += 2)
    {
        // a1
        if (arr[i] != arr[i + 1])
        {
            cout << no;
            return;
        }
    }
    cout << yes;
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