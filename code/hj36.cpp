#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string code(string key, string data)
{
    unordered_map<char, bool> use;
    unordered_map<char, bool> l_letter;
    string key_N;
    for(int i = 0; i < key.size(); i++)
    {
        if(key[i] >= 'a' && key[i] <= 'z')
            key_N += key[i] - 32;
        else
            key_N += key[i];
    }
    string table;
    for(int i = 0; i < key_N.size(); i++)
    {
        if(!use[key_N[i]])
        {
            table += key_N[i];
            use[key_N[i]] = true;
        }

    }
    for(int i = 0; i < letter.size(); i++)
    {
        if(!use[letter[i]])
            table += letter[i];
    }
    string res;
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] >= 'a' && data[i] <= 'z')
        {
            char temp = data[i] - 32;
            int pos = letter.find(temp);
            res += table[pos] + 32;
        }
        else if(data[i] >= 'A' && data[i] <= 'Z')
        {
            int pos = letter.find(data[i]);
            res += table[pos];
        }
        else
        {
            res += data[i];
        }
    }
    return res;


}

int main()
{
    string key, data;
    while(cin >> key >> data)
    {
        cout << code(key, data) << endl;

    }
/*     string key = "nihao", data = "ni";
    cout << code(key, data); */
    return 0;
}