### [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

```cpp
class Solution {
public:
    void reverseWord(string &s,int start,int end){
        while(start<end){
            char temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
    }
    void removeSpace(string&s){
        int fast=0,slow=0;
        while(fast<s.size()&&s[fast]==' ') fast++;
        for(;fast<s.size();fast++){
            if(fast-1>=0&&s[fast]==s[fast-1]&&s[fast]==' ') continue;
            else s[slow++]=s[fast];
        }
        if(slow-1>=0&&s[slow-1]==' ') slow--;
        s.resize(slow);
    }
    string reverseWords(string s) {
        reverseWord(s,0,s.size()-1);
        removeSpace(s);
        int fast=0,slow=0;
        while(fast<s.size()){
            while(fast<s.size()&&s[fast]!=' ')fast++;
            reverseWord(s,slow,fast-1);
            fast++;
            slow=fast;
        }
        return s;
    }
};
```



字符串：

统计字符串：给定一个字符串str，返回str的统计字符串。例如“aaabbbbcccd”的统计字符串为“a_3_b_4_c_3_d_1”。

```cpp
//将数字转换为字符串
int main(){
    string op;
    cin>>op;
    int i=0,j=0;
    while(op[j]){
        while(op[j]&&op[i]==op[j])j++;
        if(!i){ 
            cout<<op[i]<<'_'<<j-i;
        }else{
            cout<<'_'<<op[i]<<'_'<<j-i;
        }
        i=j;
    }
    return 0;
}
```

### [38. 外观数列](https://leetcode-cn.com/problems/count-and-say/)

```cpp
class Solution {
public:
    string countAndSay(int n) {
        return _countAndSay("1",1,n);
    }
    string _countAndSay(const string&str,int index,int n){
        if(index==n){
            return str;
        }
        int i=0,j=0;
        string nextStr="";
        while(str[i]){
            while(str[j]&&str[i]==str[j])j++;
            nextStr+=to_string(j-i);
            nextStr+=str[i];
            i=j;
        }
        return _countAndSay(nextStr,index+1,n);
    }
};
```



