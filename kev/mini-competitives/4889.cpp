#include <iostream>
#include <vector>
using namespace std;

string str;

bool input()
{
    cin >> str;
    if (str.find('-') != string::npos)
        return false;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; input(); ++i)
    {

        int cnt = 0;
        vector<char> s;
        if (str.size() > 0)
        {

            s.push_back(str[0]);
            for (int j = 1; j < str.size(); ++j)
            {

                if (s.empty()){
                    s.push_back(str[j]);
                    continue;
                }

                if (s.back() == '{' && str[j] == '}'){
                    s.pop_back();
                    continue;
                }

                s.push_back(str[j]);
            }
        }

        if (!s.empty())
        {

            for (int k = 1; k < s.size(); k += 2)
            {
                if (s[k - 1] == s[k])
                    ++cnt;
                else
                    cnt += 2;
            }
        }

        cout << i << ". " << cnt << '\n';
    }
}