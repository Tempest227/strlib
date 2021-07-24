# include <iostream>
using namespace std;
int main()
{
    string s;
    int pos;
    getline(cin, s);
    
    if ((pos = s.rfind(' ')) != string::npos)
    {
        cout << s.size() - pos - 1 << endl;
    }
    else
    {
        cout << s.size() << endl;
    }
    return 0;
}