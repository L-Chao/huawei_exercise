#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> vec = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                      "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
unordered_map<int, char> Map = 
{
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, 'E'},
    {15, 'F'}
};

int toInt(const string str0)
{
    int res = 0;
    for(int i = 0; i < str0.size(); i++)
    {
        res = 2 * res + str0[i] - '0';
    }
    return res;
}

int main()
{
    string str, str1;
    while(cin >> str >> str1)
    {
        str += str1;
        string odd, even;
        for(int i = 1; i < str.size() + 1; i++)
        {
            if(i % 2 == 1)
                odd += str[i - 1];
            else
                even += str[i - 1];
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int m = 0, n = 0;
        string s_str;
        for(int i = 1; i < str.size() + 1 ; i++)
        {
            if(i % 2 == 1 && n < odd.size())
            {
                s_str.push_back(odd[n]);
                n++;
            }
            if(i % 2 == 0 && m < even.size())
            {
                s_str.push_back(even[m]);
                m++;
            }
        }
        string res;
        string temp;
        int index;
        for(auto s : s_str)
        {
            if(s >= '0' && s <= '9')
            {
                temp = vec[s - '0'];
                reverse(temp.begin(), temp.end());
                index = toInt(temp);
                res.push_back(Map[index]);
            }
            else if(s >= 'A' && s <= 'F')
            {
                temp = vec[s - 'A' + 10];
                reverse(temp.begin(), temp.end());
                index = toInt(temp);
                res.push_back(Map[index]);
            }
            else if(s >= 'a' && s <= 'f')
            {
                temp = vec[s - 'a' + 10];
                reverse(temp.begin(), temp.end());
                index = toInt(temp);
                res.push_back(Map[index]);
            }
            else
            {
                res += s;
            }
        }
        cout << res << endl;
    }
    return 0;
}