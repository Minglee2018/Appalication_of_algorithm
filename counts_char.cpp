// đếm ký tự bằng thuật toán tìm kiếm nhị phân.

#include <bits/stdc++.h>

using namespace std;

int find_char(string str,char a, int l, int r)
{
    int m = (l + r) / 2;
    if( l == r)
    {
        if (str[l] == a)
            return 1;
        else
            return 0;
    }
    else
        return find_char(str,a,l,m) + find_char(str,a,m+1,r);
}



int main()
{
    string str = "abaabbaacc";
    char k = 'a';
    int l = 0, r = str.length();

    cout << find_char(str,k, 0, r);

    return 0;
}
