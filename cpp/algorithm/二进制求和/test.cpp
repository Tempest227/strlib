class Solution {
public:
    string addBinary(string a, string b) {
        int idx1 = a.size() - 1;
        int idx2 = b.size() - 1;
        int sum = 0;
        int next = 0;
        string str;
        while(idx1 >= 0 && idx2 >= 0)
        {
            int val1 = a[idx1] - '0';
            int val2 = b[idx2] - '0';
            if ((sum = val1 + val2 + next) >= 2)
                next = 1;
            else
                next = 0;
            str += ('0' + (sum % 2));
            idx1--;
            idx2--;
        }

        while(idx1 >= 0)
        {
            int t = a[idx1] - '0' + next;
            if (t >= 2)
                next = 1;
            else
                next = 0;
            idx1--;
            str += ('0' + t % 2);
        }
        while(idx2 >= 0)
        {
            int t = b[idx2] - '0' + next;
            if (t >= 2)            
                next = 1;            
            else            
                next = 0;            
            idx2--;
            str += ('0' + t % 2);
        }
        if (next)        
            str += ('0' + 1);        

         reverse(str.begin(), str.end());
         return str;
    }
};