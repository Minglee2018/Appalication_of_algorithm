#include <iostream>

using namespace std;
int n;
int chessboard[500][500];
int so_buoc = 0;
int so_cach = 1;

int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};


void IN_KQ()
{
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << chessboard[i][j] <<"\t";
        }
        cout << endl;
    }

}

bool oke(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=n && chessboard[i][j] == 0;
}


void xep_ma(int i, int j)
{
    so_buoc ++ ;//Tăng giá trị bước đi
    chessboard[i][j] = so_buoc;
    for (int cnt=0; cnt<8; cnt++)
    {
        //Kiểm tra xem mã đã đi hết bàn cờ chưa
        if(so_buoc == n*n)
        {
            cout << " So cach: " << so_cach << endl;
            IN_KQ();
            so_cach ++;
            return ;
            //exit(0);
        }
        else
        {
        //Nếu chưa đi hết bàn cờ thì tạo bước đi mới
            int u = i + X[cnt]; //tạo một vị trí x mới
            int v = j + Y[cnt]; //tạo một vịi trí y mới
             //Nếu hợp lẹ thì tiến hành di chuyển
            if(oke(u,v) && chessboard[u][v]==0)
                xep_ma(u,v);
        }
    }
    //Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
    so_buoc --;
    chessboard[i][j] = 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> n;
    xep_ma(1,1);

    return 0;
}
