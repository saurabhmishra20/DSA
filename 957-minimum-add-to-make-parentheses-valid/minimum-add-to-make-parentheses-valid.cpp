class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int needOpen = 0;

        for (char currentBracket : s) {
            if (currentBracket == '(') {
                st.push(currentBracket);
            } else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    needOpen++;
                }
            }
        }

        return needOpen + (int)st.size();
    }
};