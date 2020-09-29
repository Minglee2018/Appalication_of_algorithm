#include <bits/stdc++.h>

using namespace std;
int n , m , input[100][100], output[100][100], so_mien = 1;

int _x[4] = {1, 0, -1, 0};
int _y[4] = {0, 1, 0, -1};

bool oke(int i, int j){
    return i >=1 && i <= n && j >=1 && j <= m;
}


void Loang(int i, int j)
{
    output[i][j] = so_mien;

    for (int cnt =0; cnt <4; cnt++)
    {
        if(oke(i + _x[cnt], j + _y[cnt]) && input[i][j]==input[i + _x[cnt]][j + _y[cnt]] && output[i + _x[cnt]][j + _y[cnt]] == 0)
            Loang(i + _x[cnt], j + _y[cnt]);
    }

}
void thuc_hien()
{
    for (int i =1; i<=n; i++)
    {
        for (int j=1; j<=m; j++){
            if(output[i][j] == 0){
                Loang(i,j);
                so_mien ++;
            }
        }
    }

}

void IN_KQ (int a[100][100])
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cout << n << " " << m << endl;
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> input[i][j];
    }

    thuc_hien();
    IN_KQ(output);
    return 0;
}
