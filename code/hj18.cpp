#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int strtoint(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum = sum * 10 + str[i];
    }
    return sum;
};

vector<int> toint(string str){
    vector<int> res;
    int len = 0;
    for(int i = 0; i < str.size(); i++){
        while(str[i] != '.' && i < str.size())
        len++, i++;
        string nums = str.substr(i - len, len);
        int num = strtoint(nums);
        res.push_back(num);
        len = 0;
    }
    return res;
};

bool ismask(vector<int> mask){
    if(mask.size() != 4) return false;
    if(mask[0] = 255){
        if(mask[1] = 255){
            if(mask[2] = 255){
                if(mask[3] == 254 || mask[3] == 252 || mask[3] == 248 || mask[3] == 240 || mask[3] == 224 || mask[3] == 192 || mask[3] == 128 || mask[3] == 0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(mask[2] == 254 || mask[2] == 252 || mask[2] == 248 || mask[2] == 240 || mask[2] == 224 || mask[2] == 192 || mask[2] == 128 || mask[2] == 0){
                    if(mask[3] == 0) return true;
                    else return false;
                }
            }
        }
        else{
            if(mask[1] == 254 || mask[1] == 252 || mask[1] == 248 || mask[1] == 240 || mask[1] == 224 || mask[1] == 192 || mask[1] == 128 || mask[1] == 0){
                if(mask[2] == 0 && mask[3] == 0) return true;
                else return false;
            }
        }

    }
    else{
        if(mask[0] == 254 || mask[0] == 252 || mask[0] == 248 || mask[0] == 240 || mask[0] == 224 || mask[0] == 192 || mask[0] == 128){
            if(mask[1] == 0 && mask[2] == 0 && mask[3] == 0) return true;
            else return false;
        }
    }
    return false;
};

int main(){

    int len = 0;
    string str;
    while(cin >> str){
        vector<int> res(7, 0);
        vector<string> temp;
        string ips, masks;
        for(int i = 0; i < str.size(); i++){
            while(str[i] != '~' && i < str.size())
            i++, len++;
            temp.push_back(str.substr(i - len, len));
            len = 0;
        }
        ips = temp[0]; masks = temp[1];
        vector<int> ip, mask;
        ip = toint(ips);
        mask = toint(masks);
        if(ismask(mask)){
            if(ip[1] >= 0 && ip[1] <= 255 && ip[2] >= 0 && ip[2] <= 255 && ip[3] >= 0 && ip[3] <= 255){
                if(ip[0] >= 0 && ip[1] <= 126){
                    res[0]++;
                    if(ip[0] == 10)
                        res[6]++;
                }
                else if(ip[0] >= 128 && ip[1] <= 191){
                    res[1]++;
                    if(ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31)
                        res[6]++;
                }
                else if(ip[0] >= 192 && ip[1] <= 223){
                    res[2]++;
                    if(ip[0] == 192 && ip[1] == 168)
                        res[6]++;
                }
                else if(ip[0] >= 224 && ip[1] <= 239){
                    res[3]++;
                }
                else if(ip[0] >= 240 && ip[1] <= 255){
                    res[4]++;
                }
            }
        }
        else{
            res[5]++;
        }
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << ' ';
            if(i == res.size() - 1)
                cout << res[i] << endl;
        }
    }

    return 0;
}