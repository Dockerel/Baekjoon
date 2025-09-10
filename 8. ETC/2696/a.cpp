#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_pbds;

int t, n, num;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int a[10004];

int main()
{
    fastIO;
    cin >> t;
    while (t--)
    {
        ordered_set X;
        cin >> n;
        if (n % 2)
            cout << n / 2 + 1 << "\n";
        else
            cout << n / 2 << "\n";
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            a[i] = num;
        }
        for (int i = 1; i <= n; i++)
        {
            X.insert({a[i], i});
            if (i % 2)
                cout << X.find_by_order(i / 2)->first << " ";
            if (i % 20 == 0)
            {
                cout << "\n";
            }
        }
        if (n % 20 != 0)
            cout << "\n";
    }
    return 0;
}