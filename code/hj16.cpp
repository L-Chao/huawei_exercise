#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* arg[])
{
    int N, M;
    cin >> N >> M;
    N /= 10;
    int m_p[61] = {0}, m_v[61] = {0}; //主件价格、价格 * 权重
    int s1_p[61] = {0}, s1_v[61] = {0};//附件1价格、价格 * 权重
    int s2_p[61] = {0}, s2_v[61] = {0};//附件2价格、价格 * 权重
    
    int dp[3200] = {0};
    for(int i = 1; i <= M; ++i)
    {
        int v, p, q;
        cin >> v >> p >> q;
        v /= 10;
        if(q == 0)
        {
            m_p[i] = v;
            m_v[i] = v * p;
        }
        else
        {
            if(s1_p[q] == 0)//附件一
            {
                s1_p[q] = v;
                s1_v[q] = v * p;
            }
            else//附件2
            {
                s2_p[q] = v;
                s2_v[q] = v * p;                
            }
        }
    }
    for(int i = 1; i <= M; ++i)
    {
        for(int j = N; j >= 0; --j)
        {
            if(j >= m_p[i])
                dp[j] = max(dp[j], dp[j - m_p[i]] + m_v[i]);
            if(j >= m_p[i] + s1_p[i])
                dp[j] = max(dp[j], dp[j - m_p[i] - s1_p[i]] + m_v[i] + s1_v[i]);
            if(j >= m_p[i] + s2_p[i])
                dp[j] = max(dp[j], dp[j - m_p[i] - s2_p[i]] + m_v[i] + s2_v[i]);
            if(j >= m_p[i] + s1_p[i] + s2_p[i])
                dp[j] = max(dp[j], dp[j - m_p[i] - s1_p[i] - s2_p[i]] + m_v[i] + s1_v[i] + s2_v[i]);
        }

    }
    cout << dp[N] * 10 << endl;
    return 0;
    
}
