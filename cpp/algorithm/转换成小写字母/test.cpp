class Solution {
public:
    string toLowerCase(string s) {
        if (s.size() > 0 )
        {
            for (auto& c : s)
            {
                if (c >= 'A' && c <= 'Z')
                {
                    c += 32;
                }
            }
        }
        return s;
    }
};