- Method - BFS
1. will TLE, because same node would be push into queue 4 times at worst case
```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const m = grid.length;
    const n = grid[0].length
    const visited = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    let islandCount = 0;
    
    function markIslandRange (x, y, xBoundary, yBoundary) {
        const queue = [{ x, y }];
        const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        
        while (queue.length) {
            const point = queue.shift();
            visited[point.y][point.x] = 1;
            
            for (direction of directions) {
                const [xVector, yVector] = direction;
                              
                const nextX = point.x+xVector;
                const nextY = point.y+yVector;
                
                if (
                    nextX < xBoundary
                    && nextX >= 0
                    && nextY >= 0
                    && nextY < yBoundary
                    && grid[nextY][nextX] === '1'
                    && !visited[nextY][nextX]
                ) {
                    queue.push({
                        x: nextX,
                        y: nextY,
                    }); 
                }
            }        
        }
    }
    
    for(let i = 0; i < m; i++) {
        for (let j = 0 ; j < n; j++) {
            if (grid[i][j] === '1' && !visited[i][j]) { 
                islandCount++;
                markIslandRange(j, i, n, m);
            }
        }
    }
    
    return islandCount;
};
```
2. improved version
```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const m = grid.length;
    const n = grid[0].length
    let islandCount = 0;
    
    function markIslandRange (x, y, xBoundary, yBoundary) {
        const queue = [{ x, y }];
        const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        
        while (queue.length) {
            const point = queue.shift();
            grid[point.y][point.x] = 0;
            
            for (direction of directions) {
                const [xVector, yVector] = direction;
                              
                const nextX = point.x+xVector;
                const nextY = point.y+yVector;
                
                if (
                    nextX < xBoundary
                    && nextX >= 0
                    && nextY >= 0
                    && nextY < yBoundary
                    && grid[nextY][nextX] === '1'
                ) {
                    queue.push({
                        x: nextX,
                        y: nextY,
                    });
                    grid[nextY][nextX] = 0;
                }
            }        
        }
    }
    
    for(let i = 0; i < m; i++) {
        for (let j = 0 ; j < n; j++) {
            if (grid[i][j] === '1') { 
                islandCount++;
                markIslandRange(j, i, n, m);
            }
        }
    }
    
    return islandCount;
};
```
