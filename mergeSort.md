### [剑指 Offer 51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

```cpp

class Solution {
public:
    int _mergeAndCount(vector<int>&nums,vector<int>&temp,int left,int right){
        for(int i=left;i<=right;i++){
            temp[i]=nums[i];
        }
        int count=0;
        int mid=(left+right)>>1;
        int i=left,j=mid+1,k=left;
        while(i<=mid&&j<=right){
            if(temp[i]<=temp[j]){
                nums[k++]=temp[i++];
            }else{
                count+=mid-i+1;
                nums[k++]=temp[j++];
            }
        }
        while(i<=mid){
            nums[k++]=temp[i++];
        }
        while(j<=right){
            nums[k++]=temp[j++];
        }
        return count;
    }
    int merge(vector<int>&nums,vector<int>&temp,int left,int right){
        if(left>=right) return 0;
        int mid=(left+right)>>1;
        int leftCount=merge(nums,temp,left,mid);
        int rightCount=merge(nums,temp,mid+1,right);
        if(nums[mid]<=nums[mid+1]){
            return leftCount+rightCount;
        }
        return leftCount+rightCount+_mergeAndCount(nums,temp,left,right);
    }
    int reversePairs(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return 0;
        vector<int> temp=vector<int>(len,0);
        return merge(nums,temp,0,len-1);
    }
};
```

