#include <bits/stdc++.h>

using namespace std;
int n = 5;
int cnt = 0;
bool check(string s){
    for(int i=0; i<s.length(); i++)
        if(s[i] == s[i+1]){
            return false;
        }
    return true;
}
int main()
{
    //initialize results to 0
    for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {    // for each subset, O(2^n)

        string s = "";

        for ( int j = 0; j < n ; ++ j ) {       // check membership, O(n)

            if (    (i&(1 <<j))   != 0 )    // test if bit ‘j’ is turned on in subset ‘i’?
                s += "4";         // if yes, process ‘j’
            else
                s += "7";
        }
        cnt ++ ;
//        if(check(s)){
//            cout<<s<<endl;
//        }
        cout << s << endl;

    }
    printf(" \n tong so chuoi la %d \n", cnt);
}


