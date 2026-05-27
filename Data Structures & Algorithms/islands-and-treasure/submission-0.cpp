class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<bool> v(grid[0].size(), false);
        vector<vector<bool>> vis(grid.size(), v);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            if(cell.first-1 >= 0 && !vis[cell.first-1][cell.second] && grid[cell.first-1][cell.second]==INT_MAX) {
                vis[cell.first-1][cell.second] = true;
                grid[cell.first-1][cell.second] = grid[cell.first][cell.second] + 1;
                q.push({cell.first-1,cell.second});
            }
            if(cell.second-1 >= 0 && !vis[cell.first][cell.second-1] && grid[cell.first][cell.second-1]==INT_MAX) {
                vis[cell.first][cell.second-1] = true;
                grid[cell.first][cell.second-1] = grid[cell.first][cell.second] + 1;
                q.push({cell.first,cell.second-1});
            }
            if(cell.first+1 < grid.size() && !vis[cell.first+1][cell.second] && grid[cell.first+1][cell.second]==INT_MAX) {
                vis[cell.first+1][cell.second] = true;
                grid[cell.first+1][cell.second] = grid[cell.first][cell.second] + 1;
                q.push({cell.first+1,cell.second});
            }
            if(cell.second+1 < grid[0].size() && !vis[cell.first][cell.second+1] && grid[cell.first][cell.second+1]==INT_MAX) {
                vis[cell.first][cell.second+1] = true;
                grid[cell.first][cell.second+1] = grid[cell.first][cell.second] + 1;
                q.push({cell.first,cell.second+1});
            }
        }
    }
};
