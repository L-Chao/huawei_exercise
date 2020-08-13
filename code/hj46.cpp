#include <iostream>
#include <string>

using namespace std;
/* 汉字 ASCII 码 < 0*/

/* int main(int argc, char *argv[])
{
    string str;
    int n;
    while(cin >> str >> n)
    {
        cout << str.substr(0, n) << endl;
    }
} */

int main()
{
    string s;
    int n;
    while(cin >> s >> n)
    {
        int index = 0;
        for(int i = 0, j = 0; i < s.size() && j < n; i++)
        {
            int a = sizeof(s[i]);
            j += a;
            index++;
        }
        for(int i = 0; i < index; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}