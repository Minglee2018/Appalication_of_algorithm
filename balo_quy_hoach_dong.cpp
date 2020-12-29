#include <bits/stdc++.h>

/*
5 15
12 4
2 2
1 1
4 10
2 6
0 Hang thu: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Vat thu: 0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Vat thu: 1: 0 0 0 0 0 0 0 0 0 0 0 0 4 4 4 4
Vat thu: 2: 0 0 2 2 4 4 6 6 8 8 10 10 12 12 14 14
Vat thu: 3: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Vat thu: 4: 0 1 2 3 10 11 12 13 20 21 22 23 30 31 32 33
Vat thu: 5: 0 1 6 7 12 13 18 19 24 25 30 31 36 37 42 43

 gia tri toi uu cua bai toan la: 43
truy vet
chon vat thu 3 value: 1
chon vat thu 5 value: 7
chon vat thu 5 value: 13
chon vat thu 5 value: 19
chon vat thu 5 value: 25
chon vat thu 5 value: 31
chon vat thu 5 value: 37
chon vat thu 5 value: 43


5 15
12 4
4 6
1 1
2 2
5 5

0 Hang thu: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Vat thu: 0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Vat thu: 1: 0 0 0 0 0 0 0 0 0 0 0 0 4 4 4 4
Vat thu: 2: 0 0 0 0 6 6 6 6 12 12 12 12 18 18 18 18
Vat thu: 3: 0 1 2 3 6 7 8 9 12 13 14 15 18 19 20 21
Vat thu: 4: 0 1 2 3 6 7 8 9 12 13 14 15 18 19 20 21
Vat thu: 5: 0 1 2 3 6 7 8 9 12 13 14 15 18 19 20 21

 gia tri toi uu cua bai toan la: 21
truy vet
chon vat thu 2 value: 6
chon vat thu 2 value: 12
chon vat thu 2 value: 18
chon vat thu 3 value: 19
chon vat thu 3 value: 20
chon vat thu 3 value: 21

*/

using namespace std;

int n, M, d;
int trace[100];

int value[100], weight[100];
int f[100][100];

void trace_single(int n, int m)
{
    if(f[n][m] == 0)
        return ;
    if(f[n][m]==f[n][m-1])
        trace_single(n,m-1);
    else
    {
        trace[d++] = n;
        cout << "chon vat thu "<< n <<endl;
        trace_single(n-1,m);
    }
}

void trace_multible(int n, int m)
{
    if(f[n][m] == 0)
        return ;
    if(f[n][m]==f[n][m-1])
        trace_multible(n,m-1);
    else
    {

        if(f[n][m]!=f[n-1][m]){
            trace_multible(n,m - weight[n]);
            trace[d++] = n;
            cout << "chon vat thu "<< n << " value: "<< f[n][m]<<endl;
        }
        else
            trace_multible(n-1,m);
    }
}

int main()
{
    freopen("input.INP","r",stdin);
    freopen("output.INP","w",stdout);
    cin >>n >> M;
    for(int i=1; i<=n; i++)
    {
        cin >> weight[i] >> value[i];
    }
/*
    code cho bai toan balo voi 1 vat chi duoc chon duy nhat 1 lan

*/

//
//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=M; j++)
//        {
//            if(i !=0 && j!=0){
//                int curr =  j - weight[i];
//
//                if (curr >=0)
//                    f[i][j] = max(f[i-1][j], value[i] + f[i-1][curr]);
//                else
//                    f[i][j] = f[i-1][j];
//            }
//
//        }
//    }

/*
    code phia duoi giai quyet bai toan ba lo voi 1 vat duoc chon nhieu lan.

*/

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=M; j++)
        {
            if(i !=0 && j!=0){
                int curr =  j - weight[i];

                if (curr >=0)
                    f[i][j] = max(f[i-1][j], value[i] + f[i][curr]);
                else
                    f[i][j] = f[i-1][j];
            }

        }
    }

    cout << 0 << " Hang thu: ";
    for ( int i =1; i<=M; i++)  cout << i << " ";
    cout << endl;
    for(int i=0; i<=n; i++)
    {
        cout << "Vat thu: " <<i <<": ";
        for(int j=0; j<=M; j++)
        {
            cout << f[i][j] <<" ";
        }
        cout << endl;

    }
    cout << "\n gia tri toi uu cua bai toan la: " << f[n][M] << endl;
    cout << "truy vet"<< endl;
    //trace_single(n,M);
    trace_multible(n,M);

    return 0;
}

