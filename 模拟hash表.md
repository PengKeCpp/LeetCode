## [模拟散列表](https://www.acwing.com/problem/content/842/)



### 拉链法

```c++
#include<iostream>
#include<cstring>
using namespace std; 
const int N=100003;//选取一个质素,原因:https://blog.csdn.net/w_y_x_y/article/details/82288178 
int h[N],e[N],ne[N],idx;
void insert(int x){	 
	int k=(x%N+N)%N;//找到要插入下链表中的下表 
	e[idx]=x;		//创建节点的值 
	ne[idx]=h[k];	//链表头插法 
	h[k]=idx++;		//将head指向idx,idx向后移动 
}
bool find(int x){
	int k=(x%N+N)%N;	//先确定在哪个链表上 
	for(int i=h[k];i!=-1;i=ne[i]){	//在链表中找这个数是否存在 
		if(e[i]==x){
			return true;	//如果找到返回true 
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	memset(h,-1,sizeof h);	//将所有的链表置为空链表 
	while(n--){
		char op[2];	
		int x;	
		scanf("%s%d",op,&x);	//scanf一般用来读入字符串, 
		if(*op=='I'){
			insert(x);
		}else{
			if(find(x))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}

```



### 开放寻址法

```c++
#include<iostream>
#include<cstring>
using namespace std; 
const int N=200003,null=0x3f3f3f3f;//null:一般约定是找一个不在范围内的数 ,N:取一个质数 
int h[N];
// 功能:1.当这个数不存在时就返回第一个应该插入的位置,2.当这个数存在时就返回这个值的位置 
int find(int x){
	int t=(x%N+N)%N;
	while(h[t]!=null&&h[t]!=x){	//如果该位置h[t]!=null&&h[t]!=x 就往下找满足条件的位置;h[t]==x说明已经找到这个x在数组中的位置;
								//h[t]==null说明找到了第一个可以插入的位置 
		t++;
		if(t==N)t=0;	//如果到最后一个位置了，就循环到第一个位置 
	}
	return t;
}

int main(){
	memset(h,0x3f,sizeof(h));
	int n;
	cin>>n;
	while(n--){
		char op[2];
		int x;
		scanf("%s%d",op,&x);	//scanf用于读入一个字符串会忽略掉回车、空格、制表符 
		int k=find(x);
		if(*op=='I')h[k]=x;
		else{
			if(h[k]==null)puts("No");
			else puts("Yes");
		}
	}
	return 0;
}

```



### 拉链法

```c++

//拉链法 
class MyHashMap{
public:
	const static int N=20011;
	vector<list<pair<int,int>>> hash;	//定义一个长度为N的数组来存储每个链表的头(关键字：key) 
	MyHashMap(){
		hash=vector<list<pair<int,int>>>(N); 
	}
	//查找关键字是否存在 
	list<pair<int,int>>::iterator find(int key){
		int t=key%N;
		auto it=hash[t].begin();
		for(;it!=hash[t].end();it++)
			if(it->first==key)
				break;
		return it;
	}
	//如果找到关键字的就将关键字修改,没有找到就将值插入进去 
	void put(int key,int value){
		int t=key%N;
		auto it=find(key);
		if(it==hash[t].end()){
			hash[t].push_back(make_pair(key,value));
		}else{
			it->second=value;
		}
	}
	//没有找到关键字就返回-1找到就返回关键字对应的value; 
	int get(int key){
		auto it=find(key);
		if(it==hash[key%N].end()){
			return -1;
		}
		return it->second;
	}
    //将找到关键字就将关键字移除 
	void remove(int key){
		int t=key%N;
		auto it=find(key);
		if(it!=hash[t].end()){
			hash[t].erase(it);
		}
	}
};


```



### 开放寻址法

```c++
class MyHashMap{
public:
	
	//注意:空位置有两种状态,-2，-1;-2:对应于用过的点，但是将其移除了。-1:对应于还没有插入的点 
	const static int N=20011;
	int hash_key[N],hash_value[N];
	MyHashMap{
		memset(hash_key,-1,sizeof hash_key);
	}
	
	//两个作用:作用一:找到了这个点就返回这个点。作用二:如果这个点不存在那么就返回这个点该插入的位置 
	int find(int key){
		int t=ket%N;
		while(hash_key[t]!=key&&hash_key[t]!=-1){//	 hash_key[t]=key:说明找到了这个关键字，返回这个点这个关键字本身 
												 //hash_key[t]=-1:找到了可以插入的点 
			if(++t==N) t=0; 
		}
		return t;
	}
	void put(int key,int value){
		int t=find(key);
		hash_key[t]=key;
		hash_value[t]=value;
	}
	
	int get(int key){
		int t=find(key);
		if(hash_key[t]==-1)return -1;
		return hash_value[t];
	}
	
	void remove(int key){
		int t=find(key);
		if(hash_key[t]!=-1){
			hash_key[t]=-2;	//不能将hash_key[t]的值改为-1,如果直接改为-1
							//那么我们就从这个点断开了,如果这个点对应的
							//关键字后面还有点就不能找到后面的点了，所以将值改为-2换一种标记 
		}
	}
};

```





