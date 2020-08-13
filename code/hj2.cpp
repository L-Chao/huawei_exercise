#include <iostream>

using namespace std;

int main(){
    char str[100001];
    char x;
    gets(str);
    /*
    * gets 防止空格
    */
    cin >> x;
    int cnt = 0;
    /*
    +- 32 大小写转换
    */
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == x || str[i] == x + 32 || str[i] == x - 32)
            cnt++;
    }
    cout << cnt;
    return 0;
}