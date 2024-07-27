long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    int dist[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dist[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < originalSize; i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        int wt = cost[i];
        if (wt < dist[u][v]) {
            dist[u][v] = wt;
        }
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int s = strlen(source);
    long long ans = 0;
    for (int i = 0; i < s; i++) {
        int l = source[i] - 'a';
        int r = target[i] - 'a';
        if (dist[l][r] == INT_MAX) {
            return -1;
        } else {
            ans += dist[l][r];
        }
    }
    return ans;
}
