class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qL++;
            else
                sumL += num[i] - '0';
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qR++;
            else
                sumR += num[i] - '0';
        }

        // Odd number of '?' -> Alice gets the final move
        if ((qL + qR) % 2 == 1)
            return true;

        // Otherwise Bob can win only if the existing
        // sum difference can be exactly compensated.
        return sumL - sumR != 9 * (qR - qL) / 2;
    }
};