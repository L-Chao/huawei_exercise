#include <iostream>

using namespace std;

int main(){
    long num;
    while(cin >> num){
        for(int i = 2; i * i < num; i++){
            while(num % i == 0){
                cout << i << ' ';
                num /= i;
            }
        }
        if(num > 1)
            cout << num << ' ';
    }
    return 0;
}