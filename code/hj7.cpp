#include <iostream>

using namespace std;

int main(){
    double num;
    while(cin >> num){
        long floor;
        floor = long(num);
        if(num - floor >= 0.5){
            cout << floor + 1 << endl;
        }
        else
            cout << floor << endl;
    }
    return 0;
}