#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    int cnt(0);
    while(num){
        cnt++;
        num = num & (num - 1);
    }
    cout << cnt << endl;
    return 0;
}
/* int main(){
    int num;
    cin >> num;
    int cnt(0);
    while(num){
        if(num % 2 == 1)
        cnt ++;
        num /= 2;
        
    }
    cout << cnt << endl;
    return 0;
} */