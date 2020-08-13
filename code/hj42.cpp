#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const string ones[] = {"zero", "one", "two", "three","four", "five", "six", "seven", "enght", "nine"};
const string tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fiften", "sixteen", "seventeen", "eighteen", "ninteen"};
const string twenties[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"};
const int ihundereds[] = {(int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12};
const string hundreds[] = {"hundred", "thousand", "millon", "billon"};

string itoe(long long n)
{
    if(n >= 0 && n < 10) return ones[n];
    if(n >= 10 && n < 20) return tens[n % 10];
    if(n >= 20 && n < 100) return twenties[n / 10] + (n % 10? " " + ones[n % 10] : "");
    for(int i = 0; i < 5 - 1; ++i)
    {
        if(n < ihundereds[i + 1])
        return itoe(n / ihundereds[i]) + " " + hundreds[i] + (n % ihundereds[i]? (i? " " : " and ") + itoe(n % ihundereds[i]) : "");
    }
    return "";
}
int main()
{
    for(long long N; cin >> N;)
        cout << itoe(N) << endl;
    return 0;
}