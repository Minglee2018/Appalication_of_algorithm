#include <bits/stdc++.h>

using namespace std;

int Find_sub_string(string root, string sub)
{
    int m = sub.length();
    int n = root.length();
    for(int i=0; i<n; i++)
    {
        int j = 0;
        while(j<m&& root[j+i]==sub[j])
        j ++;
        if(j==m)
            return i;

    }
    return -1;
}


int main()
{

    string root = "CGTGCCTACTTACTTACTTACTTACGCGAA";
    string sub = "CTTACTTAC";
    cout << Find_sub_string(root,sub);
    return 0;
}
