#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    string res;
    cin >> num;
    while(num){
        res += to_string(num % 10);/* res += num % 10 + '0' */
        num /= 10;
    }
    cout << res << endl;
    return 0;
}