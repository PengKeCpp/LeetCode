### [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

```cpp
//特殊条件，当只有一列或者只有一行时需要特殊处理
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        fillmatrix(0,0,matrix.size()-1,matrix[0].size()-1,matrix,res);
        return res;
    }
    void fillmatrix(int x1,int y1,int x2,int y2,vector<vector<int>> &matrix,vector<int>&res){
        if(x1>=x2||y1>=y2){
            //当只有一行时
            if(x1==x2){
                for(int i=y1;i<=y2;i++) res.push_back(matrix[x1][i]);
                //到这个地方就要返回，因为当只有一个点时 既在一行又在一列，如果不返回就会加入两次这个点
                return;
            }
            //当只有一列时的处理
            if(y1==y2){
                for(int i=x1;i<=x2;i++) res.push_back(matrix[i][y2]);
            }   
            return;
        }
        for(int i=y1;i<y2;i++) res.push_back(matrix[x1][i]);
        for(int i=x1;i<x2;i++) res.push_back(matrix[i][y2]);
        for(int i=y2;i>y1;i--) res.push_back(matrix[x2][i]);
        for(int i=x2;i>x1;i--) res.push_back(matrix[i][y1]);
        fillmatrix(x1+1,y1+1,x2-1,y2-1,matrix,res);
    }
};
```

### [59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int ans=0;
        fillmattrix(ans,0,0,n-1,n-1,res);
        return res;
    }
    void fillmattrix(int &ans,int x1,int y1,int x2,int y2,vector<vector<int>>& res){
        if(x1>=x2){
            //当n为奇数时，就会只有一个点此时需要特殊处理这个点，最后一个点就只需要加入一次就可以了
            if(x1==x2) res[x1][x1]=++ans;
            return ;
        }
        for(int i=y1;i<=y2;i++) res[x1][i]=++ans;
        for(int i=x1+1;i<x2;i++) res[i][y2]=++ans;
        for(int i=y2;i>=y1;i--) res[x2][i]=++ans; 
        for(int i=x2-1;i>x1;i--) res[i][y1]=++ans;
        fillmattrix(ans,x1+1,y1+1,x2-1,y2-1,res);
    }
};
```

