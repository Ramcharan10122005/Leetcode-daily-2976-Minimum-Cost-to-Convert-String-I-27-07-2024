class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        int n = original.size();
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            dist[u][v] = min(dist[u][v], wt);
        }
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int s = source.size();
        long long ans = 0;
        for (int i = 0; i < s; i++) {
            int l = source[i] - 'a';
            int r = target[i] - 'a';
            if (dist[l][r] == INT_MAX)
                return -1;
            else
                ans += dist[l][r];
        }
        return ans;
    }
};
