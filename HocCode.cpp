#include <bits/stdc++.h>
#include <fstream>
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

void Hoc_tep_tin()
{
    int n, m, t;
    cin >> t;
    int a[t];
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    cin >> n >> m;
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    // Ghi tep
    fstream f("Hoc_tep_tin.txt", ios::out);
    f << n << "\n";
    for (int i = 0; i < n; i++)
    {
        f << a[i] << " ";
    }
    f << "\n\n";
    f << n << " " << m << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            f << b[i][j] << " ";
        }
        f << "\n";
    }
    f.close();

    cout << "-------- DOC TEP --------\n";
    // Doc tep
    ifstream ff("Hoc_tep_tin.txt", ios::out);
    int p, q;
    ff >> p;
    int *x = new int(p);
    for (int i = 0; i < p; i++)
    {
        ff >> x[i];
    }
    ff >> p >> q;
    int y[p][q];
    for (int i = 0; i < p; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            ff >> y[i][j];
        }
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << y[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Hoc_tep_tin();
}
