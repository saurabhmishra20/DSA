class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if (s1 == s2) {
            return true;
        }
        int diffs = 0;

        int firstidx = 0;
        int secondidx = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s1[i] != s2[i]) {
                diffs++;
            
            if (diffs > 2) {
                return false;
            } else if(diffs == 1) {
                firstidx = i;
            } else {
                secondidx = i;
            }
        }
        }
    
        return s1[firstidx] == s2[secondidx] && s1[secondidx] == s2[firstidx];
    }
};