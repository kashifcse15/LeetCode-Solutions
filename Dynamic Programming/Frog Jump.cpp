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
