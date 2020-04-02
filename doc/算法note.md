#### ASCII

| Char | ASCII | Char | ASCII | Char | ASCII |
| ---- | ----- | ---- | ----- | ---- | ----- |
| 0    | 48    | A    | 65    | a    | 97    |
| 9    | 57    | Z    | 90    | z    | 122   |
|      |       |      |       |      |       |



### 1.排序

#### 1.1 排序算法

O(n^2) 冒泡排序、插入排序、选择排序

O(n^1.3) 

希尔排序：将待排序数组按照步长gap进行分组，然后将每组的元素利用直接插入排序的方法进行排序；每次将gap折半减小，循环上述操作；当gap=1时，利用直接插入，完成排序。

O(nlogn) 

* 快速排序：分治，取一个数作为基准，将比这个数小的放在一边，大的放在另一边，再分别对这两边递归操作
* 归并排序：先将小的部分排序好，再将小部分合并
* 堆排序：进行大顶堆/小顶堆排序之后，首尾交换
* 基数排序：

#### 1.2 排序库 algorithm 

> **包含 algorithm 头文件，使用sort排序函数**，可以自定义排序规则
>
> 比较的除了数字，也可以是对象或者结构体

```c++
#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int x,int y){ // 自定义排序规则
    return x > y;
}

int main(){
    int n;
    int buf[100];
    
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d",&buf[i]);
        }
        sort(buf, buf + n, cmp);//使用重载形式，自定义排序规则
        
        for(int i = 0; i < n; i++){
            printf("%d", buf[i]);
        }
        printf("\n");
    }
    return 0;
}
```

> 为什么传&b，可以不传引用
>
> 为什么char[]不用&，而int需要
>
> sort传入的是**指针**

```c++
#include <stdio.h>
#include <algorithm>
#include <string.h>

struct E{
    char name[101];
    int age;
    int score;
    bool operator < (const E &b) const{
        if(score != b.score) return score < b.score;
        int tmp = strcmp(name, b.name);
        if(tmp != 0) return tmp < 0;
        else return age < b.age;
    }
}buf[1000];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%s%d%d",buf[i].name, &buf[i].age, &buf[i].score);
        }
        sort(buf,buf+n);
        
        for(int i = 0; i < n; i++){
            printf("%s %d %d\n",buf[i].name, buf[i].age, buf[i].score);
        }
    }
    return 0;
}
```



#### map

```c++
map.insert(pair<int, string>(000, "student_zero"));
find 返回迭代器指向当前查找元素的位置否则返回map::end()位置
map<char , int>::iterator iter;
for (iter = map.begin(); iter != map.end(); iter++) {
   cout << iter->first << " occurs " << iter->second<< ((iter->second) > 1 ? " times" : " time") << endl;
}
```

#### vector

常见语法：

size()

push_back()

void assign(const_iterator first,const_iterator last); // **assign会清空你的容器。**赋值

```c++
bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0]; // 升序排序
}

// 需要传的是begin，end
sort(intervals.begin(), intervals.end(), cmp);

// 初始化用{}
vector<int> newInterval = {2, 5};

// vector全部转到数组
memcpy(charary, &vec[0], vec.size() * sizeof(vec[0]));

// 数组转vector
vector<float> vecHeight(arrHeight, arrHeight+sizeof(arrHeight)/sizeof(float));
```

#### Stack

push top 

#### string

size  at  substr

#### set

```c++
// vector to set
unordered_set<string> good(words.begin(), words.end());
```

### 2. 动态规划

#### int

```c++
// infinite
int->INT_MAX
unsigned int ->UINT_MAX
long->LONG_MAX
unsigned long->ULONG_MAX
```