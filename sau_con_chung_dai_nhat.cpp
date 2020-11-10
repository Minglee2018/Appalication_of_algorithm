//Sau con chung dai nhat

#include <bits/stdc++.h>

using namespace std;
int L[5000][5000];

void solve(string x, string y)
{
    int n = x.length();
    int m = y.length();
    //cout << n << " " << m << endl;
    //cout << x[n] << " " << y[m] << endl;
    for(int i=0; i< n; i++) L[i][0] = 0;
    for(int j=0; j< m; j++) L[0][j] = 0;

    for(int i=1; i<= n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
            {
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    cout << "matrix results \n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    printf("result is: %d",L[n][m]);
}

int main()
{
    string x ,y;
    cin >> x >> y;
    solve(x,y);
    return 0;
}
