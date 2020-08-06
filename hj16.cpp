#include <iostream>

using namespace std;

int getMax(int a, int b){
    return (a > b)? a : b;
};

int main(){
    int N, M;
    int price[60][3] = {0};
    int value[60][3] = {0};
    int f[60][3200];
    int v, p, q;
    cin >> N >> M;
    N /= 10;
    for(int i = 1; i <= M; i++){
        cin >> v >> p >> q;
        v /= 10;
        if(q == 0){
            price[i][0] = v;
            value[i][0] = v * p;
        }
        else if(price[q][1] == 0){
            price[q][1] = v;
            value[q][1] = v * p;
            }
        else{
            price[q][2] = v;
            value[q][2] = v * p;
            }
    }
    for(int i = 1; i <= M; i++){
        for(int j = N; j > 0; j--){
            if(j >= price[i][0])
            f[i][j] = getMax(f[i - 1][j], f[i - 1][j - price[i][0]] + value[i][0]);
            if(j >= price[i][0] + price[i][1])
            f[i][j] = getMax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][1]] + value[i][0] + value[i][1]);
            if(j >= price[i][0] + price[i][2])
            f[i][j] = getMax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][2]] + value[i][0] + value[i][2]);
            if(j >= price[i][0] + price[i][1] + price[i][2])
            f[i][j] = getMax(f[i - 1][j], f[i - 1][j - price[i][0] - price[i][1] - price[i][2]] + value[i][0] + value[i][1] + value[i][2]);
        }
    }
    cout << f[M][N] * 10 << endl;

    return 0;
}