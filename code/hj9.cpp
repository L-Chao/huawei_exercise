#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* int main(){
    int num;
    vector<int> vec;
    unordered_map<int, int> myMap;
    unordered_map<int, bool> use;
    cin >> num;
    while(num){
        int temp = num % 10;
        myMap[temp]++;
        vec.push_back(temp);
        num /= 10;
    }
    int res = 0;
    for(auto v : vec){
        if(myMap[v] != 0 && !use[v]){
            res = res * 10 + v;
            use[v] = true;
        }
    }
    cout << res << endl;
    return 0;
} */
int main(){
    int num;
    unordered_map<int, int> myMap;
    cin >> num;
    int res(0);
    while(num){
        int temp = num % 10;
        if(myMap[temp] == 0){
            myMap[temp]++;
            res = res * 10 + temp;
        }
        num /= 10;
    }
    cout << res << endl;
    return 0;
}