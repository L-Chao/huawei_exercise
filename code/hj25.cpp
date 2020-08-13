#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
bool match(int r, int i)
{
    string strr = to_string(r);
    string stri = to_string(i);
    int pos = stri.find(strr);
    if(pos != -1)
    return true;
    return false;
};

int main()
{
    int Inum, Rnum;
    while(cin >> Inum)
    {
        vector<int> I, R;
        for(int i = 0; i < Inum; i++)
        {
            int temp;
            cin >> temp;
            I.push_back(temp);
        }

        cin >> Rnum;
        for(int j = 0; j < Rnum; j++)
        {
            int temp;
            cin >> temp;
            R.push_back(temp);
        }
        sort(R.begin(), R.end());
        R.erase(unique(R.begin(), R.end()), R.end());

        vector<int> value, cnt, index, index1;
        for(int i = 0; i < R.size(); i++)
        {
            int cnt1 = 0;/* 记录 R[i] 在 I 里出现的次数 子集数量*/
            for(int j = 0; j < I.size(); j++)
            {
                if(match(R[i], I[j]))
                {
                    cnt1++;
                    index.push_back(j);
                    value.push_back(I[j]);
                }
            }
            if(cnt1 != 0)
                {
                    cnt.push_back(cnt1);
                    index1.push_back(R[i]);

                }

        }
        int sum = value.size()+ cnt.size() + index.size() + index1.size();
        cout << sum << ' ';
        int j = 0;
        for(int i = 0; i < cnt.size(); i++)
        {
            cout << index1[i] << ' ' << cnt[i] << ' ';
            while(cnt[i] --)
            {
                cout << index[j] << ' ' << value[j];/* << ' '; */
                if(i == cnt.size() - 1 && cnt[i] == 0)
                    cout << endl;
                else
                    cout << ' ';
                j++;
            }
        }
    }


}