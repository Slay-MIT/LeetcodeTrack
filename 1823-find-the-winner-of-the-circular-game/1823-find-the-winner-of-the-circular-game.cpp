class Solution {
public:
    int findTheWinner(int n, int k) {
        int playerCount = 0;
//When there is only one person (n=1) they are the winner by default. 
//This base case doesn't require any elimination steps and thus 
//we don't need to calculate anything for it. Therefore, we start the iteration from i =2
        for (int i = 2; i <= n; i++) {
            playerCount = (playerCount + k) % i;
        }
        return playerCount + 1;
    }
};