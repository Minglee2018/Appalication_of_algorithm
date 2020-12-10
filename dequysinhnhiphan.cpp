#include <bits/stdc++.h>

using namespace std;
char *a;
int n;
int cnt = 0;

string s = "ueoai";

void Try( int index)
{
    if(index == n)
    {
        for(int i=0; i<n; i++)
        {
            cout << a[i];
        }
        cnt ++;
        cout << endl;
        return ;
    }
    else{

        for(int i=0; i<s.length(); i++)
        {
            a[index] = s[i];
            Try(index +1);
            a[index] = 'x';
        }
    }
}



int main()
{
   cin >> n;
   a = new char[n];
   for(int i =0; i<n; i++)
        a[i] = 'x';

   Try(0);

   cout << " \n tong so day hoan vi \n" ;
   cout << cnt <<endl;

}
