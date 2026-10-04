class Solution {
    vector<vector<int>> memo;

    bool solve(string &s, int idx, int bal) {
        // invalid path
        if (bal < 0) return false;

        // all characters are passed
        if (idx == s.length()) {
            return bal == 0;
        }

        // already calculated
        if (memo[idx][bal] != -1) {
            return memo[idx][bal];
        }

        char currentCharacter = s[idx];
        bool result;

        // '('
        if (currentCharacter == '(') {
            result = solve(s, idx + 1, bal + 1);
        }
        // ')'
        else if (currentCharacter == ')') {
            result = solve(s, idx + 1, bal - 1);
        }
        // '*'
        else {
            bool useAsOpening = solve(s, idx + 1, bal + 1);  // '*' as '('
            bool useAsClosing = solve(s, idx + 1, bal - 1);  // '*' as ')'
            bool useAsEmpty   = solve(s, idx + 1, bal);      // '*' as empty

            result = useAsOpening || useAsClosing || useAsEmpty;
        }

        // store answer for this state
        return memo[idx][bal] = result;
    }

public:
    bool checkValidString(string s) {
        int n = s.length();
        memo.assign(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0);
    }
};