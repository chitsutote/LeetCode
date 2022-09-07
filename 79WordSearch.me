- Method - backtrack
```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const row = board.length;
    const col = board[0].length;
    const visited = Array.from({ length: row }, () => Array.from({ length: col }, () => 0));
    
    function findWord (point, boundary, level) {
        if (level === word.length) return true;
        
        if (
            point.x < 0
            || point.x >= boundary.x
            || point.y < 0
            || point.y >= boundary.y
            || board[point.y][point.x] !== word[level]
            || visited[point.y][point.x]
        ) {
            return false
        }
        
        visited[point.y][point.x] = 1;
        
        const result = findWord({ x: point.x+1, y: point.y }, boundary, level+1)
        || findWord({ x: point.x-1, y: point.y }, boundary, level+1)
        || findWord({ x: point.x, y: point.y+1 }, boundary, level+1)
        || findWord({ x: point.x, y: point.y-1 }, boundary, level+1)
        
        visited[point.y][point.x] = 0;
        
        return result
    }
    
    for (let i = 0; i < col; i++) {
        for (let j = 0; j < row; j++) {
            if (board[j][i] === word[0]) {
                if (findWord({ x: i, y: j}, { x: col, y: row }, 0)) return true;
            }
        }
    }
    
    return false;
};
```
