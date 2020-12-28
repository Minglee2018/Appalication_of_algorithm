#include <bits/stdc++.h>

using namespace std;


int BMH(string root, string sub)
{
    int n = root.length(), m = sub.length(), dem = 0;

    map < char,int> bad_table;
    for(int i=0; i<m; i++) bad_table[sub[i]] = 0;

    /*
        i'm try Construct bad match table in this input i have by formular : value = len of sub string - index - 1.
    */

    for(int i=0; i<m-1; i++)
    {
        int value = m - i - 1;
        bad_table[sub[i]] = value;
    }
    if(bad_table[sub[m-1]] == 0)
            bad_table[sub[m-1]] = m;
//    for(map<char,int> ::iterator it = bad_table.begin(); it!=bad_table.end(); it++)
//    {
//        cout << "charactor: "<<it->first << " value: " <<it->second <<endl;
//
//    }

    int loop = m - 1;
    for( ; loop <n ; )
    {
        int idx = 0;
        /*
            i'm find a sub string in root string
            if sub string appeared in root string, that mean my idx varible equal leng of subtring.
        */
        while(root[loop - idx] == sub[m - idx - 1] && idx !=m) idx ++;
        /*
            i found sub string in root string then we counts by one.
            if u need to find sub string in root u can return number of index of sub string.
        */

        if (idx == m)  dem ++;


        int curr = loop - idx;
//        cout <<"loop: " <<loop <<" char root: "<<root[curr] << " char sub: " << sub[m - idx - 1] <<" not match " <<endl;
        /*
            this is boyer moore horspool algorithmic. i'm try to skip arange by caculate BMH .
        */
        if(bad_table[root[curr]] == 0)
            loop += m -1;
        else
            loop += bad_table[root[curr]];

    }
    return dem;
}


int main()
{

//    string root="tambaymothaitamkbonnamsautamchinmuoibay";
//    string sub="bay";
    string root = "CGTGCCTACTTACTTACTTACTTACGCGAA";
    string sub = "CTTACTTAC";
    int answer = BMH(root, sub);
    if (answer == -1)
        cout << "do not find sub string in root string";
    else
        cout << "this index we find sub string in root string is: " << answer;
    return 0;
}
