- Method 1
```javascript
function addBinary(a: string, b: string): string {
    let carry = 0;
    let [i, j] = [a.length - 1, b.length -1];
    const stack = [];
    
    while (i >= 0 || j >= 0) {
        const sum = (Number(a[i]) || 0) + (Number(b[j]) || 0) + carry;
        if (sum >= 2) {
            carry = 1;
            stack.push(`${sum%2}`);
        } else {
            carry = 0;
            stack.push(`${sum}`)
        }
        
        i--;
        j--;
    }
    
    const result = carry === 1 ? ['1'] : [];
    
    while (stack.length) {
        result.push(stack.pop())
    }
    
    return result.join('');
};
```
