#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> myMap = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15}

};

using namespace std;


int main(){
    string str;
    
    while(getline(cin, str)){
        int num(0);
        for(int i = 2; i < str.size(); i++){
            num = num * 16 + myMap[str[i]];
        }
        cout << to_string(num) << endl;
    }
    return 0;
}
/*
* 不用 hasp map
int main(){
    string str;
    
    while(getline(cin, str)){
        int num(0);
        for(int i = 2; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9')
                num = num * 16 + str[i] - '0';
            else
                num = num * 16 + str[i] - 'A' + 10;
        cout << to_string(num) << endl;
        }
    }
    return 0;
}
*/