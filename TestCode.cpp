#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << " ---------------------------------------- \n";
    string s = " BangTranVan2004,";
    s += " hello github workspace";
    cout << s;
    cout << "\n ---------------------------------------- ";

    int n = 8;
    int a[n] = {-12, 6, -18, -24, -30, 36, 42, -48};
    for (int i = 0; i < n;)
    {
        if (a[i] < 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
        }
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}