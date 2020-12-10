#include <bits/stdc++.h>

using namespace std;
int *a;
int n;
int cnt = 0, len = 6;
int dem =0;

int value[6] = {1,2,3,4,5,6};

void xoa_mang(int vitri)
{
    for(int i=vitri; i<len; i++)
    {
        value[i] = value[i+1];
    }
    len --;
}

void tra_lai_mang(int vitri, int gt)
{
    len ++;
    for(int i=len; i>vitri; i--)
    {
        value[i] = value[i-1];
    }
    value[vitri] = gt;
}



void Try( int index)
{
    if(index == n)
    {
        for(int i=0; i<n; i++)
        {
            cout << a[i];
        }
        cnt ++;

        if(a[0] == 1) dem ++;

        cout << endl;
        return ;
    }
    else{

        for(int i=0; i<len; i++)
        {
            int gt = value[i];
            a[index] = value[i];

            xoa_mang(i);

            Try(index +1);

            a[index] = 0;

            tra_lai_mang(i, gt);
        }
    }
}



int main()
{
    n = 6;
    a = new int[n];
    Try(0);
    cout << " \n tong so day hoan vi \n" ;
    cout << cnt <<endl;

    cout << "dem so 1 dung trc " << dem << endl;

}
