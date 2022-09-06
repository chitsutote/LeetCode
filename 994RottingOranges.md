- Method 1
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const row = grid.length;
    const col = grid[0].length;
    const queue = [];
    let fresh = 0;
    let times = 0;
    
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (grid[i][j] === 2) {
                queue.push([j, i]);
            }
            
            if (grid[i][j] === 1) {
                fresh++;
            }
        }
    }
    
    const directions = [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1],
    ]
    
    while (queue.length && fresh > 0) {
        const currentRottenCount = queue.length
        
        for (let i = 0; i < currentRottenCount; i++) {
            const [x, y] = queue.shift();
            
            for (direction of directions) {
                const [vX, vY] = direction
                const nextX = x + vX;
                const nextY = y + vY;
                
                if (
                    nextX < 0
                    || nextX >= col
                    || nextY < 0
                    || nextY >= row
                    || grid[nextY][nextX] !== 1
                ) {
                    continue;
                }
                
                queue.push([nextX, nextY]);
                grid[nextY][nextX] = 2;
                fresh--;
            }
        }
        
        times++;
    }
    
    return fresh === 0 ? times : -1;
};
```
