#include <bits/stdc++.h>

using namespace std;

int n, M;

int value[100], weight[100];
int f[100][100];
int main()
{
    freopen("input.INP","r",stdin);
    cin >>n >> M;
    for(int i=1; i<=n; i++)
    {
        cin >> weight[i] >> value[i];
    }
/*
    code cho bai toan balo voi 1 vat chi duoc chon duy nhat 1 lan

*/


    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=M; j++)
        {
            if(i !=0 && j!=0){
                int curr =  j - weight[i];

                if (curr >=0)
                    f[i][j] = max(f[i-1][j], value[i] + f[i-1][curr]);
                else
                    f[i][j] = f[i-1][j];
            }

        }
    }

/*
    code phia duoi giai quyet bai toan ba lo voi 1 vat duoc chon nhieu lan.

*/

//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=M; j++)
//        {
//            if(i !=0 && j!=0){
//                int curr =  j - weight[i];
//
//                if (curr >=0)
//                    f[i][j] = max(f[i-1][j], value[i] + f[i][curr]);
//                else
//                    f[i][j] = f[i-1][j];
//            }
//
//        }
//    }

    cout << 0 << "  ";
    for ( int i =1; i<=M; i++)  cout << i << " ";
    cout << endl;
    for(int i=0; i<=n; i++)
    {
        cout << i <<": ";
        for(int j=0; j<=M; j++)
        {
            cout << f[i][j] <<" ";
        }
        cout << endl;

    }
    cout << "\n gia tri toi uu cua bai toan la: " << f[n][M];

    return 0;
}

