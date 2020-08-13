#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int num, n;
    while(cin >> num){
        unordered_map<int, int> a(10001);
        /*
        * 注意条件
        */
        while(num--){
            cin >> n;
            a[n] = 1;
        }
        for(int i = 1; i < 1001; i++){
            if(a[i] == 1)
                cout << i << endl;
        }
    }
    return 0;
}