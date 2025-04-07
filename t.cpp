#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, steps;
};

int bfs(const vector<vector<char>>& maze, Point start, Point end) {
    int N = maze.size();
    int M = maze[0].size();
    
  
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    queue<Point> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    q.push(start);
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        
        if (current.x == end.x && current.y == end.y) {
            return current.steps;
        }
        
       
        for (auto& dir : directions) {
            int nx = current.x + dir[0];
            int ny = current.y + dir[1];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'E')) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1});
            }
        }
    }
    
    return -1; 
}

int main() {
    vector<vector<char>> maze = {
        {'S', '.', '.', '#', '.', '.'},
        {'#', '#', '.', '#', '.', '.'},
        {'.', '.', '.', '#', '.', '.'},
        {'.', '#', '#', '#', '.', 'E'},
        {'#', '#', '#', '#', '#', '#'}
    };
    
    Point start = {0, 0, 0};  /'
    Point end = {3, 5, 0};    
    
    int result = bfs(maze, start, end);
    cout << result << endl;  
    
    return 0;
}
