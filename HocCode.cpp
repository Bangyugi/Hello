#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

int Lmao(vector<long long> &a, int l, int r)
{
    int ucln = UCLN(a[l], a[l + 1]);
    for (int i = l + 2; i <= r; i++)
    {
        ucln = UCLN(ucln, a[i]);
        if (ucln == 1)
            return 1;
    }
    return ucln;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, v, l, r, j;
    int thaotac;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (m--)
    {
        cin >> thaotac;
        if (thaotac == 1)
        {
            cin >> j >> v;
            a[j] = v;
        }
        else
        {
            cin >> l >> r;
            int ucln = Lmao(a, l, r);
            cout << ucln << "\n";
        }
    }
}
