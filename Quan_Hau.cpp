
#include <bits/stdc++.h>

using namespace std;

int road[10][10];
int stage_answer[2][10];
int cach = 1;

void printf()
{
    for (int i = 1; i<=8; i++)
    {
        cout << "(" << stage_answer[0][i]<<" : "<<stage_answer[1][i]<<")"<<" ";
    }
    cout << endl;
    for (int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cout << road[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

bool oke(int hang, int cot)
{
    for (int i=1; i<cot; i++){
        if(hang==stage_answer[0][i] || cot==stage_answer[1][i] || abs(hang-stage_answer[0][i])==abs(cot-stage_answer[1][i]) )
            return false;
    }
    return true;
}


void xep_hau(int cot)
{
    if(cot == 9){
        cout <<"cach: "<<cach<<endl;
        cach++;
        printf();
        return ;
//        exit(0);
    }
    else
    {
        for(int hang = 1; hang <= 8; hang++)
        {
            if(oke(hang,cot))
            {
                road[cot][hang] = 1;
                stage_answer[0][cot] = hang;
                stage_answer[1][cot] = cot;
                xep_hau(cot + 1);
                road[cot][hang] = 0;
                stage_answer[0][cot] = 0;
                stage_answer[1][cot] = 0;
            }
        }
    }
}


int main()
{
    xep_hau(1);
    return 0;
}
