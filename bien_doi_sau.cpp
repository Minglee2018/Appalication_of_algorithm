//Bien doi sau
#include <bits/stdc++.h>

using namespace std;
int L[5000][5000];
void solve(string x, string y){
    int n = x.length();
    int m = y.length();
    for(int i=0; i<=m; i++) L[0][i] = i;
    for(int i=0; i<=n; i++) L[i][0] = i;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1] == y[j-1]) L[i][j] = L[i-1][j-1];
            else
            {
                L[i][j] = min(min(L[i-1][j],L[i][j-1]),L[i-1][j-1]) + 1;
            }
        }
    }
    cout << " the matrix is: \n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout << L[i][j] <<" ";
        }
        cout <<endl;
    }

    printf("anwer of problem is: %d",L[n][m]);
}

int main()
{
    string x,y;
    cin >> x >> y;
    solve(x,y);
    return 0;
}
