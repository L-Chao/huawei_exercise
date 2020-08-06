#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string str;
    unordered_map<char, int> myMap;
    getline(cin, str);
    for(auto s : str){
        int acsCode = int(s);
        if(acsCode >= 0 && acsCode <= 127){
            myMap[s]++;
        }
    }
    cout << myMap.size() << endl;
    return 0;
}