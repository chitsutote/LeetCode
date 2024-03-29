- CPP
```cpp
/**********************
Question:

Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Thought:
Establish a hashmap with counts for the letters in magazine,
check every letter in ransom note. Minus one count for each letter.
if the count is negative , that is to say , out of letters in magazine
return false ,then. Otherwise , return true.

 **********************/

class Solution {
		public:
				bool canConstruct(string ransomNote, string magazine) {
						int magaDict[25]={0};
						int tmp=0;
						//Construct hashmap of magazine
						for(int i = 0 ; i < magazine.length(); i ++){
								tmp = magazine[i];
								magaDict[tmp - 97] +=1;
						}

						for(int j = 0 ; j < ransomNote.length();j++){
								tmp = ransomNote[j];
								magaDict[tmp - 97] -=1;
								if(magaDict[tmp-97] < 0) return false;
						}

						return true;
				}
};
```

- Javascript
```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    if (magazine.length < ransomNote.length) return false;
    
    const map = {};
    
    for (let i = 0; i < magazine.length; i++) {
        map[magazine[i]] = (map[magazine[i]] || 0)+1;
    }
    
    for (let i = 0; i < ransomNote.length; i++) {
        if (map[ransomNote[i]] === undefined) return false;
        
        map[ransomNote[i]]--;
        
        if (map[ransomNote[i]] < 0) return false;
    }
    
    return true;
};
```
