#include <bits/stdc++.h>
using namespace std;
int input[100][100], tmp[100][100]; // mảng input đầu vào và mảng lưu trữ thông tin để truy vết lại
int n, m;
int Max = 0, x = 0,y =0;

int savePos[2][10];
void createArrays()
{
    freopen("input.txt","r",stdin);

    cin >> n >> m;

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j <=m; j++){
            cin >> input[i][j];
            tmp[i][j] = input[i][j];
        }
    }
}
void printArray(int a[100][100])
{

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//hàm update giá trị tại từng vị trí (i,j)
void solve()
{
    for(int i=1; i<=n; i++){
        // tính 3 điểm liền trước ô đang xét lấy max để update tại vị trí có tọa độ (i,j)
        for(int j=1; j<=m; j++){
        input[i][j] = input[i][j] + (int)max( input[i-1][j+1],(int) max(input[i-1][j], input[i-1][j-1]) );
        }
    }

}
//hàm truy vết lại vị mà tại đó có thể có giá trị lớn nhất
void trace()
{
    // tìm giá trị lớn nhất ở hàng cuối cùng
    for( int i=1 ; i<=m; i++){
        if(Max<input[n][i]){
            Max = input[n][i];
            x = n, y = i;
        }
    }
    cout << "the maximum value find !\n";
    cout << Max << endl;
    // truy ngược từ hàng cuối cùng về hàng đầu tiên
    for(int i=n; i>=1 ; i-- ){
        savePos[0][i] = i, savePos[1][i] = y;  // lưu lại tọa độ (i,j)
        if(input[i][y] - tmp[i][y] == input[i-1][y-1]) y -=1;
        else if(input[i][y] - tmp[i][y] == input[i-1][y + 1]) y +=1;
    }
}

int main()
{
    createArrays();
    solve();
    cout << "\n arrays input \n";
    printArray(tmp);
    cout << "\n arrays update \n";
    printArray(input);
    trace();
    cout << " \n the paths of coordinate \n";
    for(int i= 1; i<=n; i++ ){
        cout << savePos[0][i] << " " << savePos[1][i] <<endl;
    }
    return 0;
}
