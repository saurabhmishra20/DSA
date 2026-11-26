//Approach-1 Simulation
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};


