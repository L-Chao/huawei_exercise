#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char str[5001];
    gets(str);
    /*
    gets() 可以读取空格
    cint 遇到空格自动结束
    */
    int len = 0;
    for(int i = strlen(str) - 1; str[i] != ' ' && i >= 0; i--){
        len++;
    }
    cout << len << endl;
    return 0;
}