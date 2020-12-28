#include <bits/stdc++.h>
/*
5 15
12 4
2 2
1 1
1 2
4 10

4 10
1 2
2 2
1 1
12 4

*/

using namespace std;

int weight[100], value[100];
float ll[100];
int n, w;

void Sort()
{
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(ll[i] < ll[j])
            {
                swap(weight[i],weight[j]);
                swap(value[i], value[j]);
                swap(ll[i], ll[j]);
            }
        }
    }

}

int main()
{
    freopen("input.INP","r",stdin);
    cin >> n >> w;
    for(int i=1; i<=n; i++)
    {
        int x , y ;
        cin >> x >> y;
        weight[i] = x, value[i] = y;
        ll[i] = (float)y/x;
    }
    Sort();
    for(int i = 1; i<=n; i++)
    {
        cout << weight[i] <<" " <<value[i] <<" "<<ll[i] <<endl;

    }
    int ans = 0, W = w;
    for(int i=1; i<=n; i++)
    {
        ans += (W/weight[i])*value[i];
        W = W%weight[i];
    }

    cout << ans;
    return 0;
}
