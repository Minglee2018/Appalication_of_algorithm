#include <bits/stdc++.h>
/*
Cho một lưới kích thước MxN các số nguyên , chỉ có các giá trị 0,1,2.
- Hai ô được gọi là kề nhau nếu có chung cạnh và cùng giá trị.
- Hai ô được gọi là cùng một miền liên thông, nếu chúng cùng giá trị và có thể
"đường đi đến nhau " thông qua một số ô kề.
1. Hãy cho biết miền liên thông lớn nhất có bao nhiêu ô ?
2. cho phép đổi giá trị tất cả các ô của một miền nào đó (0->1 hoặc; 0->2; or
1->2; 2->0 or 2->1 ).  Hay cho biết miền lớn nhất có thể (sau khi đổi giá trị
 của một miền nào đó ) có bao nhiêu ô.

4 5
1 1 1 1 0
1 1 1 1 0
1 1 2 2 1
1 1 2 1 1

trước khi thay đổi : 12
sau khi  thay đổi: 18

1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
1 1 1 1 1
*/


using namespace std;
int ds[100][100];
int tmp[100][100];

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

int n, m, so_mien = 1, befor_=1, cnt = 1, result_fi = 0, result_se = 0;
map<int,int> grap, cll ;


bool valid(int x, int y)
{
    return (x>=1 && y>=1 && x<=n && y<=m);
}

void loang(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        /*
            loang mien lien thong
        */
        tmp[x][y]= so_mien;
        int  r = x_[i] + x;
        int  c = y_[i] + y;
        if(valid(r,c) && tmp[r][c]==0 && ds[x][y]==ds[r][c]) {
            loang(r,c);

        /*
            luu lai kich thuoc cua tung mien tim duoc
        */

        grap[so_mien] ++;

        }

    }

}

void dis_C()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{

    freopen("input.INP","r",stdin);
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m;j++)
    {
        cin >> ds[i][j];
        cll[ds[i][j]] ++;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(tmp[i][j]==0)
            {
                loang(i,j);
                so_mien ++;
            }
        }
    dis_C();
    for(map<int,int> ::iterator it = grap.begin(); it!= grap.end(); it++) result_fi = max(result_fi, (*it).second + 1);


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {

            for(int k = 0; k<4; k++)
            {
                int r = x_[k] + i;
                int c = y_[k] + j;
    /*
        tim mien kich thuoc lon nhat
        va tim 2 mien lien thong den nhau co kich thuoc lon nhat
    */
                if(valid(i,j) && valid(r,c) && ds[i][j]!= ds[r][c])
                    result_se = max(result_se, cll[ds[i][j]] + cll[ds[r][c]]);
            }

        }
    }
    cout << "so mien truoc khi doi: " <<result_fi << "\nso mien sau khi doi: " << result_se << endl;
    return 0;
}
