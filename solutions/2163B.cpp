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
    vector<int> p(n);
    vector<int> x(n);
    string x_str;
    int x_pos_1 = -1, x_pos_n = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        // store x_pos_1, x_pos_n
        if (p[i] == 1)
        {
            x_pos_1 = i;
        }
        else if (p[i] == n)
        {
            x_pos_n = i;
        }
    }
    cin >> x_str;
    // check obvious bounds issues
    if (x_str[0] == '1' ||
        x_str[n - 1] == '1' ||
        x_str[x_pos_1] == '1' ||
        x_str[x_pos_n] == '1')
    {
        cout << "-1\n";
        return;
    }

    // actual reasoning, at this point we know the problem is solvable
    cout << "5\n";
    auto print_op = [&](int u, int v)
    {
        if (u > v)
            swap(u, v);
        // Output 1-based indices
        cout << u + 1 << " " << v + 1 << "\n";
    };

    // The 5 "Master" Operations
    print_op(0, x_pos_1);       // Start -> Pos(1)
    print_op(0, x_pos_n);       // Start -> Pos(n)
    print_op(x_pos_1, n - 1);   // Pos(1) -> End
    print_op(x_pos_n, n - 1);   // Pos(n) -> End
    print_op(x_pos_1, x_pos_n); // Pos(1) <-> Pos(n)
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