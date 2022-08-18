- Method 1
```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let up = 1;
    let down = 0;
    let left = 0;
    let right = 0;
    let indexX = 0;
    let indexY = 0;
    let direction = "right";
    
    const m = matrix[0].length;
    const n = matrix.length;
    const result = [];
    const visited = new Array(n).fill(0).map((element) => new Array(m).fill(0));
    
    while (visited[indexY][indexX] === 0) { 
        result.push(matrix[indexY][indexX]);
        visited[indexY][indexX] = 1;
        
        switch (direction) {
            case "right": {
                if (indexX === (m-right-1)) {
                    direction = 'down';
                    indexY++;
                    right++;
                    
                    if (indexY >= n) {
                        return result;
                    }
                } else {
                    indexX++;
                }
                
                break;
            }
            case "down": {
                if (indexY === (n-down-1)) {
                    direction = 'left';
                    indexX--;
                    down++;
                
                    if (indexX < 0) {
                        return result;
                    }
                } else {
                    indexY++;
                }
                break;
            }
            case "left": {
                if (indexX === (0+left)) {
                    direction = 'up';
                    indexY--;
                    left++;
                
                    if (indexY < 0) {
                        return result;
                    }
                } else {
                    indexX--;
                }
                break;
            }
            case "up": {
                if (indexY === (0+up)) {
                    direction = 'right';
                    indexX++;
                    up++;
                
                    if (indexX >= m) {
                        return result;
                    }
                } else {
                    indexY--;
                }
                break;
            }
        }
    }
    
    return result;
};
```
- Method 2
```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
   
    
    const m = matrix[0].length;
    const n = matrix.length;
    const result = [];
    
    let upperBound = 0;
    let lowerBound = n - 1;
    let leftBound = 0;
    let rightBound = m - 1;
    let indexX = 0;
    let indexY = 0;
    
    const narrowerSide = Math.min(m, n);
    let times = narrowerSide % 2 === 0
        ? narrowerSide / 2
        : Math.floor(narrowerSide / 2) + 1;
    
    while (times > 0) {
        if (leftBound === rightBound) {
            for (; indexY <= lowerBound ; indexY++) {
                result.push(matrix[indexY][indexX])
            }
        } else if (upperBound === lowerBound) {
            for (; indexX <= rightBound ; indexX++) {
                result.push(matrix[indexY][indexX])
            }
        } else {
            for (; indexX < rightBound; indexX++) {
                result.push(matrix[indexY][indexX]);
            }
            
            for (; indexY < lowerBound; indexY++) {
                result.push(matrix[indexY][indexX]);
            }           
            
            for (; indexX > leftBound; indexX--) {
                result.push(matrix[indexY][indexX]);
            }
            
            for (; indexY > upperBound; indexY--) {
                result.push(matrix[indexY][indexX]);
            }
            indexY++;
            indexX++;
            
            rightBound--;
            leftBound++;
            upperBound++;
            lowerBound--;
        }
        
        times--;
    }
    
    
    
    return result;
};
```
