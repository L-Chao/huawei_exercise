#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    
    while(cin >> str){
        vector<string> vec; // 容器每次都要初始化
        int x = 0, y = 0;
        string temp;
        for(int i = 0; i < int(str.size()); i++){
            
            if(str[i] != ';'){
                temp += str[i];
            }
            else{
                if(!temp.empty()){
                    vec.push_back(temp);
                    temp = "";
                }
            }
        }
        for(int i = 0; i < int(vec.size()); i++){
            int num = 0;
            if(vec[i].size() == 2 && vec[i][1] >= '0' && vec[i][1] <= '9'){
                num = vec[i][1] - '0';
            }
            if(vec[i].size() == 3 && vec[i][1] >= '0' && vec[i][1] <= '9' && vec[i][2] >= '0' && vec[i][2] <= '9'){
                num = 10 * (vec[i][1] - '0') + vec[i][2] - '0';
            }
            switch (vec[i][0])
            {
            case 'A': x -= num; break;
            case 'D': x += num; break;
            case 'W': y += num; break;
            case 'S': y -= num; break;
            default: break;
            }
        }
        cout << x << ',' << y << endl;
    }

    return 0;
}