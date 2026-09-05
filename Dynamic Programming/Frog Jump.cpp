int frogJump(int i, int height[]) {
  //BY RECURSION
    if (i == 0)
        return 0;

    int oneStep =
        frogJump(i - 1, height)
        + abs(height[i] - height[i - 1]);

    int twoStep = INT_MAX;

    if (i > 1) {
        twoStep =
            frogJump(i - 2, height)
            + abs(height[i] - height[i - 2]);
    }

    return min(oneStep, twoStep);
}


int frogJump(int i, int height[], int dp[]) {
//MEMOISATION / TOP DOWN
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int oneStep =
        frogJump(i - 1, height, dp)
        + abs(height[i] - height[i - 1]);

    int twoStep = INT_MAX;

    if (i > 1) {
        twoStep =
            frogJump(i - 2, height, dp)
            + abs(height[i] - height[i - 2]);
    }

    dp[i] = min(oneStep, twoStep);

    return dp[i];
}



int frogJump(int n, int height[]) {
//BY TABULATION / BOTTOM-UP
    int dp[n];

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        int oneStep =
            dp[i - 1]
            + abs(height[i] - height[i - 1]);

        int twoStep = INT_MAX;

        if (i > 1) {
            twoStep =
                dp[i - 2]
                + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n - 1];
}
