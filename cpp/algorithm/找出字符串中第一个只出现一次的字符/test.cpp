#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    int cnt[128] = {0};
    int flag = 0;
    while(getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            cnt[str[i]]++;
        }
        
        for (int i = 0; i < str.size(); i++)
        {
            if (cnt[str[i]] == 1)
            {
                cout << str[i] << endl;
                flag = 1;
                break;
            }            
        }
        
        if (!flag)
        {
            cout << -1 << endl;
        }
        flag = 0;
        memset(cnt, 0, sizeof(cnt));
    }

    return 0;
}