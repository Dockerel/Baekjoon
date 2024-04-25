#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_pbds;

int n, k, num;
long long ret;
int a[250004];
typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set X;

int main()
{
    fastIO;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = num;
        X.insert(num);
        if (X.size() > k)
        {
            int target = a[i - k];
            auto idx = X.order_of_key(target);
            X.erase(X.find_by_order(idx));
        }
        if (X.size() == k)
        {
            int mid = (k + 1) / 2 - 1;
            ret += *X.find_by_order(mid);
        }
    }

    cout << ret << "\n";

    return 0;
}