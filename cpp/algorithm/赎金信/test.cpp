class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};

        for (int i = 0; i < magazine.size(); i++)
        {
            cnt[magazine[i] - 'a'] += 1;
        }
        
        for (int i = 0; i < ransomNote.size(); i++)
        {
            cnt[ransomNote[i] - 'a']--;
        }
        
        for (int i = 0; i < sizeof(cnt) / sizeof(int); i++)
        {
            if (cnt[i] < 0)
                return false;
        }

        return true;
    }
};