#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long ipToNum(string ip)
{
    vector<string> vec;
    string temp;
    for(int i = 0; i < ip.size(); i++)
    {
        if(ip[i] != '.')
        temp += ip[i];
        else
        {
            if(!temp.empty())
            {
                vec.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty())
    {
        vec.push_back(temp);
    }
    vector<int> ip_int;
    for(int i = 0; i < vec.size(); i++)
    {
        int num = 0;
        for(int j = 0; j < vec[i].size(); j++)
        {
            num = 10 * num + vec[i][j] - '0';
        }
        ip_int.push_back(num);
    }
    string ip_2;
    for(int i = 0; i < ip_int.size(); i++)
    {
        string bit_8(8, '0');
        int temp = ip_int[i];
        for(int j = 7; j >= 0; j--)
        {
            bit_8[j] = temp % 2;
            temp /= 2;
        }
        ip_2 += bit_8;
    }
    long long res = 0;
    for(int i = 0; i < ip_2.size(); i++)
    {
        res = res * 2 + ip_2[i];
    }
    return res;
};

string numToIp(long long num)
{
    string num_2(32, '0');
    for(int i = 31; i >= 0; i--)
    {
        num_2[i] = '0' + (num % 2);
        num /= 2;
    }
    vector<int> ip_10;
    for(int i = 0; i < 32; i += 8)
    {
        string temp = num_2.substr(i, 8);
        int bit_8 = 0;
        for(int i = 0; i < 8; i ++)
        {
            bit_8 = bit_8 * 2 + temp[i] - '0'; 
        }
        ip_10.push_back(bit_8);
    }
    string res;
    for(int i = 0; i < 4; i++)
    {
        string temp;
        int n = ip_10[i];
        while(n)
        {
            temp = to_string(n % 10) + temp;
            n /= 10;
        }
        if(i < 3)
            res += temp + '.';
        else
            res += temp;
        temp.clear();
    }
    return res;

}

int main()/* 自己电脑上 long long 类型才能通过，牛客上 long 类型通过 */
{
    string ip;
    long long num;
    while(cin >> ip >> num)
    {
        cout << ipToNum(ip) << endl << numToIp(num) << endl;

    }
/*     string ip = "234.237.37.104";
    long num = 3165757026;
    cout << ipToNum(ip) << endl;
    cout << numToIp(num) << endl; */
    return 0;
}