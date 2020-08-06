#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    cin >> num;
    unordered_map<int, int> myMap;
    vector<int> vec;
    while(num--){
        int index, val;
        cin >> index >> val;
        vec.push_back(index);
        myMap[index] += val;
    }
    sort(vec.begin(), vec.end());/* 排序 */
    vec.erase(unique(vec.begin(), vec.end()), vec.end());/* 去重 */
    for(auto v : vec){
        cout << v << ' ' << myMap[v] << endl;
    }
/*     for(int i = 0; i < int(myMap.size()); i++){
        if(myMap[i] != 0){
            cout << i << ' ' << myMap[i] << endl;
        }
    } */
    return 0;
}