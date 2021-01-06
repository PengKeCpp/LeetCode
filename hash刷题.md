### [290. 单词规律](https://leetcode-cn.com/problems/word-pattern/)

```cpp
class Solution {
public:
    vector<string> split(string s){
        vector<string> res;
        int index=0,pos=0;
        for(int i=0;i<s.size();i++){
            pos=s.find(" ",index);
            if(pos==-1){
                res.push_back(s.substr(index));
                break;
            }else{
                res.push_back(s.substr(index,pos-index));
            }
            index=pos+1;
        }
        return res;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> res=split(s);//分割字符串
        unordered_map<char,string> hash;
        unordered_set<string> set;//去重
        if(pattern.size()!=res.size())return false;
        for(int i=0;i<res.size();i++){
            if(hash.find(pattern[i])!=hash.end()){
                if(hash[pattern[i]]!=res[i])return false;
            }else{
                if(set.find(res[i])!=set.end())return false;//发现加入的value已经出现
                else{
                    set.insert(res[i]);
                    hash[pattern[i]]=res[i];
                }
            }
        }
        return true;
    }
};
```

