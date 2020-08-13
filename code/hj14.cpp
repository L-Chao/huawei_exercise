#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    vector<string> vec;
    cin >> num;
    unordered_map<string, int> myMap;
    while(num--){
        string temp;
        cin >> temp;
        if(myMap[temp] == 0)
            myMap[temp]++;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    for(auto v : vec){
        if(myMap[v])
        cout << v << endl;
    }
    return 0;
}