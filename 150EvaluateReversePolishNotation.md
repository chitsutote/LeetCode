- Method 1
```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];
    
    for (let token of tokens) {
        switch (token) {
            case '-': {
                const [back, first] = [stack.pop(), stack.pop()]
                
                stack.push(first - back);
                break;
            }
            case '+': {
                const [back, first] = [stack.pop(), stack.pop()]
                
                stack.push(first + back);
                break;
            }
            case '*': {
                const [back, first] = [stack.pop(), stack.pop()]
                
                stack.push(first * back);
                break;
            }
            case '/': {
                const [back, first] = [stack.pop(), stack.pop()]
                
                stack.push(parseInt(first / back));
                break;
            }
            default: {
                stack.push(Number(token));
            }
        }
    }
    
    return stack[0];
};
```
