class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;

        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;

        dist[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            for (int num : arr) {
                int newNode = (1LL * node * num) % 100000;

                if (steps + 1 < dist[newNode]) {
                    dist[newNode] = steps + 1;

                    if (newNode == end)
                        return steps + 1;

                    q.push({newNode, steps + 1});
                }
            }
        }

        return -1;
    }
};
