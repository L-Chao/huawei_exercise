#include <string>
#include <sstream>
#include <iostream>
//#include <stack>

using namespace std;

class Soultion{
public:
    string reverse(string str){
        istringstream ss(str);
        string s;
        string res;
        while(ss >> s){
            res = s + ' ' + res;
        }
        return res.substr(0, res.size() - 1);
    }
};

int main(){
    string str;
    getline(cin, str);
    Soultion sol;
    string ans  = sol.reverse(str);
    cout << ans << endl;
}