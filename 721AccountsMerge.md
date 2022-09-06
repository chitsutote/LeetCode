- Method 1 - DFS
```javascript
/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
var accountsMerge = function(accounts) {
    const result = [];
    const emailAccountMap = {}
    const visited = {};
    
    for (let i = 0; i < accounts.length; i++) {
        for (let j = 1; j < accounts[i].length; j++) {
            emailAccountMap[accounts[i][j]] = [...(emailAccountMap[accounts[i][j]] || []), i];
        }
    }
   
    function findEmails (index, foundEmails) {
        if (visited[index]) return;
        visited[index] = 1;
        
        const emails = accounts[index];
        
        for (let j = 1; j < emails.length; j++) {
            const accountList = emailAccountMap[emails[j]];
            foundEmails[emails[j]] = emails[j];
            
            for (account of accountList) {
                findEmails(account, foundEmails);
            }
        }
    }
    
    for (let i = 0; i < accounts.length; i++) {
        if (visited[i]) continue;
        const foundEmails = {};
        
        findEmails(i, foundEmails);
        
        result.push([
            accounts[i][0],
            ...Object.values(foundEmails)
                .sort((a, b) => {
                    if (a > b) return 1;
                    if (a < b) return -1;
                    return 0;
                })
        ])
    }
    
    return result
};
```
