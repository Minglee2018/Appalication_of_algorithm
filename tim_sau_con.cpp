
/* Bài toán: Tìm tất cả các vị trí của xâu a
xuất hiện trong xâu b.
HD: Xây dựng một mảng v[leng(a)+leng(b)+1] để mỗi
vị trí chứa số ký tự giống xâu a, tính từ vị trí
đó.
Ví dụ
a="abcdefg";
b="abdacabcdefgaabcde";
thì v=[2,0,0,1,0,7,0,0,0,0,0,....]
Thuật toán: lần lượt từng vị trí i=0,1,... của V
đếm xem từ vị trí i trở đi, có bao nhiêu vị trí
tương ứng giống a.
Sau khi tìm được hết, thì vị trí nào trong V có
giá trị =leng(a) thì đó là vị trí cần tìm
Cải tiến:
bình thường, tìm được 1 giá trị của v[i] ta dịch
tiếp 1 để tìm vị trí tiếp theo, tuy nhiên có
nhận xét: nếu vị trí tiếp theo khác kí tự đầu
của a, thì chắc chắn không cần tìm.
do đó, ta không dịch mỗi lần 1 vị trí, mà trong
quá trình tính v[i], ta có thể biết luôn vị trí nào
tiếp theo giống vị trí đầu của xâu a, để ta nhảy
luôn đến đó và tính. Ô la la!!!!
*/
#include <bits/stdc++.h>

using namespace std;
string a,b,s;
long z[100000005];
void thuchien()
{   int la=a.length();
    int lb=b.length();
    s=a+"*"+b;
    int l=0,r=0;
    z[0]=-1;
    for (int i=1; i<s.length(); i++)
    {   if (i>r)
        {   l=i;
            while (s[i]==s[r])
            {   i++;
                r++;
            }
            z[i]=r-l+1;
        }
        else
        {   int k=i-l;
            if (z[i]<r-i+1) z[i]=z[k];
            else
            {   l=i;
                while (s[i]==s[r])
                {   i++;
                    r++;
                }
                z[i]=r-l+1;

            }

        }

    }

}
void inkq()
{   //cout<<endl;
    int d=0;
    for (int i=0; i<b.length(); i++)
        //cout<<v[i]<<" ";
        if (z[i]==(a.length()))
            d++;
    cout<<d<<endl;
}
void sinhdl()
{   srand(time(0));
    string s1,s2;
    freopen("string.inp","w",stdout);
    int t=1;//rand()%100+1;số test
    cout<<t<<endl;
    char ch;
    while (t--)
    {   s1="";
        s2="";
        int n=rand()%1000000000+1;
        while (n--)
        {   ch=rand()%26+65;
            if (rand()%2==0) ch+=32;
            s1=s1+ch;
        }
        int i=rand()%100;
        for (int k=0; k<i; k++)
        {   int j=rand()%100;
            for(int t=0; t<j; t++)
            {   ch=rand()%26+65;
                if (rand()%2==0) ch+=32;
                s2=s2+ch;
            }
            s2=s2+s1;//muốn s1 có trong s2
        }
        cout<<s2<<endl;
        cout<<s1<<endl;
    }
    freopen("con","w",stdout);
}
int main()
{   //sinhdl();
    freopen("string.inp","r",stdin);
    //freopen("string.out","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {   cin>>b>>a;
        //cout<<a<<endl;
        //cout<<b<<endl;
        thuchien();
        inkq();
        //cout<<b.length();
    }
    return 0;

}
