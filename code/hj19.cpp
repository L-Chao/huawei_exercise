#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <unordered_map>

using namespace std;
struct record
{
    string name;
    int line;
    int cnt = 1;
    bool operator==(const record &a)/* 重载运算符 '=='，以便后续使用 find 函数 */
    {
        if (a.name == this->name && a.line == this->line)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<record> rec;
    //vector<int> line;
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        record temp;
        string name;
        int line = 0;
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            if (str1[i] != '\\')/* 取出文件名中最后一个'\'之后的内容*/
                name = str1[i] + name;/* 因为从后往前遍历，所以倒序 */
            else
                break;
        }
        if (name.size() > 16)
        {
            name = name.substr(name.size() - 16, 16);/* 如果文件名长度大于16，取后16个字符 */
        }
        for (int i = 0; i < str2.size(); i++)/* 将行数转化为整数，可以省略，不转也没问题 */
        {
            line = 10 * line + str2[i] - '0';
        }
        temp.name = name;
        temp.line = line;
        auto p = find(rec.begin(), rec.end(), temp);/* 查找结构体数组中是否有当前输入的 对象 */
        if (p == rec.end())/* 如果不存在，将该对象存入数组 */
        {
            rec.push_back(temp);
        }
        else
        {
            p->cnt++;/* 如果已存在，将存在对象的计数加一 */
        }
    }
    if (rec.size() >= 8)/* 输出 */
    {
        for (int i = rec.size() - 8; i < rec.size(); i++)
        {
            cout << rec[i].name << ' ' << rec[i].line << ' ' << rec[i].cnt << endl;
        }
    }
    else
    {
        for (int i = 0; i < rec.size(); i++)
        {
            cout << rec[i].name << ' ' << rec[i].line << ' ' << rec[i].cnt << endl;
        }
    }

    return 0;
}