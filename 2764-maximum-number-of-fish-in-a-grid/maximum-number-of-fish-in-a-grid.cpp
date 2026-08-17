class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds or no fish
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;

        // Collect fish from current cell
        int fish = grid[r][c];

        // Mark as visited
        grid[r][c] = 0;

        // Explore four directions
        fish += dfs(grid, r + 1, c);
        fish += dfs(grid, r - 1, c);
        fish += dfs(grid, r, c + 1);
        fish += dfs(grid, r, c - 1);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {

        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }

            }
        }

        return ans;
    }
};