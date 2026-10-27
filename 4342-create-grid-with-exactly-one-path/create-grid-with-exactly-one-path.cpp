class Solution {
public:

    vector<string> createGrid(int m, int n) {

        vector<string> res(m);

        // Row 0 stays completely open.
        string open(n, '.');

        // Later rows are blocked except the last column.
        string blocked(n, '#');
        blocked[n - 1] = '.';

        res[0] = open;

        for (int i = 1; i < m; i++) {
            res[i] = blocked;
        }

        return res;
    }
};