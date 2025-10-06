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
    int n = 0, c = 0, s = 0, b = 0, mult = 1;
    cin >> n >> c; // read in # of bags, popping weight
    vector<int> v(n);
    for (int i = 0; i < n; i++) // read in
    {
        cin >> b;
        v[i] = b;
    }

    sort(v.rbegin(), v.rend()); // sort because we really only care about the free balloons

    for (int i = 0; i < n; i++)
    {
        if ((mult * v[i]) > c)
        {
            s++; // if the val is greater than bag size increment solution because it will always cost 1 to destroy
        }
        else // the weight is less than c, so don't increment s, just increase the mult and move on
        {
            mult *= 2; // all bags cost twice as much now
        }
    }
    cout << s << '\n';
}

int main()
{
    // #ifdef DEBUG
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

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