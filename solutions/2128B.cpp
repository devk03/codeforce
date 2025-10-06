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
    cin >> n; // read in size of array
    string solution(n, '?');
    vector<int> arr(n);          // initialize vector to keep track
    bool isMax = false;          // false represents min
    int left = 0, right = n - 1; // two pointers
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        arr[i] = b;
    }
    for (int i = 0; i < n; i++)
    {              // construct size n solution object
        if (isMax) // if switch is true look for max
        {
            if (arr[left] < arr[right])
            {
                solution[i] = 'R';
                right--;
            }
            else
            {
                solution[i] = 'L';
                left++;
            }
        }
        else // if switch is false look for min
        {
            if (arr[left] > arr[right])
            {
                solution[i] = 'R';
                right--;
            }
            else
            {
                solution[i] = 'L';
                left++;
            }
        }
        isMax = !isMax;
    }
    cout << solution << '\n';
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