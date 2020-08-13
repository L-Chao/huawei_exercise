#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        int letter(0), space(0), num(0), other(0);
        for(auto s : str)
        {
            if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
                letter++;
            else if(s == ' ')
                space++;
            else if(s >= '0' && s <= '9')
                num++;
            else
                other++;
        }
        cout << letter << endl;
        cout << space << endl;
        cout << num << endl;
        cout << other << endl;
    }
    return 0;
}