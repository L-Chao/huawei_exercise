#include <iostream>
#include <stack>

using namespace std;

int main(){
   string str;
   getline(cin, str);
   stack<char> s;
   string res;
   for(int i = str.size() - 1; i >= 0; i--){
      s.push(str[i]);
      if(str[i] == ' ' && !s.empty()){
         if(str[i] == ' '){
            s.pop();
            while(!s.empty()){
               res += s.top();
               s.pop();
            }
            res += ' ';
         }
      }
      }
   if(!s.empty()){
      while(!s.empty()){
         res += s.top();
         s.pop();
      }
   }
   cout << res << endl;
   return 0;
}