- Method 1 - DFS
```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, color) {
    const m = image.length;
    const n = image[0].length;
    
    if (image[sr][sc] === color) return image;
    if (sr < 0 || sc < 0) return;
    if (sr >= m || sc >= n) return;
    
    const currentColor = image[sr][sc];
    image[sr][sc] = color;
    
    if (
        ((sr - 1) >= 0) &&
        (image[sr-1][sc] === currentColor)
    ) {
        floodFill(image, sr-1, sc, color);
    }
    
    if (
        ((sc - 1) >= 0) &&
        (image[sr][sc-1] === currentColor)
    ) {
        floodFill(image, sr, sc -1, color);
    }
    
    if (
        ((sr + 1) < m) &&
        (image[sr+1][sc] === currentColor)
    ) {
        floodFill(image, sr+1, sc, color);
    }
    
    if (
        ((sc + 1) < n) &&
        (image[sr][sc+1] === currentColor)
    ) {
        floodFill(image, sr, sc+1, color);
    }
     
    
    return image;
};
```

- Method 2 BFS
```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, color) {
    if (image[sr][sc] === color) return image;

    const m = image.length;
    const n = image[0].length;
    const queue = [];
    
    queue.push({
        x: sr,
        y: sc,
    });
    const startingColor = image[sr][sc];
    
    while (queue.length != 0) {
        console.log('teh queue', queue);
        const pixel = queue.shift();
        image[pixel.x][pixel.y] = color;
        console.log('the current color', startingColor);
        console.log('the pixel movement', pixel);
        console.log('teh image', image);
        
        
        if (
            (pixel.x - 1 >= 0)
            && image[pixel.x - 1][pixel.y] === startingColor
        ) {
            queue.push({
                x: pixel.x-1,
                y: pixel.y,
            })
        }
        
        if (
            (pixel.y - 1 >= 0)
            && image[pixel.x][pixel.y-1] === startingColor
        ) {
            queue.push({
                x: pixel.x,
                y: pixel.y-1,
            })
        }
        
        if (
            (pixel.x + 1 < m)
            && image[pixel.x+1][pixel.y] === startingColor
        ) {
            queue.push({
                x: pixel.x+1,
                y: pixel.y,
            })
        }
        
        if (
            (pixel.y + 1 < n)
            && image[pixel.x][pixel.y+1] === startingColor
        ) {
            queue.push({
                x: pixel.x,
                y: pixel.y+1,
            })
        }
    }
    
    return image;
};
```
