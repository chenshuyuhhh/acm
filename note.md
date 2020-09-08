# c++常用语法总结

### 0. 

#### 0.1库

```c++
#include <math.h> ==> <cmath>

pow(x,y);  // x^y
squrt(x);
log(x); // 以e为底取x的对数
exp(n); // e的n次方
```

#### 0.2 ASCII

| 字符   | 0    | 9    | A    | Z    | a    | z    |
| ------ | ---- | ---- | ---- | ---- | ---- | ---- |
| 十进制 | 48   | 57   | 65   | 90   | 97   | 1    |

```c++
// char 转数字：
char a = '0';
int ia = (int)a; // 48
// first method
int x = ia - 48;
// second method
int ia = a - '0';
```



#### 0.3 num

int：-2147483648 ~ 2147483647

```c++
// int 转 char，用加法
int i = 5;
char c = i + '0';

// char 转 int，用减法
char c = '7';
int i = c - '0';
```



#### 0.4 位运算符

| ^    | ~    | \>>>       |      |      |      |
| ---- | ---- | ---------- | ---- | ---- | ---- |
| 异或 | 取反 | 无符号右移 |      |      |      |

#### 0.5





### 1.vector

#### 1.1 vector api

size() 大小

push_back() 加入

emplace_back() 创建新的加入

pop_back() 取出最后一个元素

back() 获得最后一个元素

insert() 指定位置插入元素

vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t

```c++
vector<int> res;
vector<vector<int>> result;
int l = nums.size();
result.emplace_back(res);

vector<int> v(3);  
v[0]=2; //v[0]是第0个元素 
v[1]=7;  
v[2]=9;  
v.insert(v.begin(),8);//在最前面插入新元素。  
v.insert(v.begin()+2,1);//在迭代器中第二个元素前插入新元素  
v.insert(v.end(),3);//在向量末尾追加新元素。  
 
v.insert(v.end(),4,1);//在尾部插入4个1

v.insert(v.end(),a[1],a[3]);//在尾部插入a[1]个a[3]
```

#### 1.2 convert

数组转vector

```c++
float ary[] = { 1.68,1.72,1.83,2.05,2.35,1.78,2.1,1.96 };
int l = ary.size();
vector<float> vecHeight(ary, ary+l);
vector<int> vec(ary, ary + sizeof(ary) / sizeof(int));
```

vector转数组

```c++
//初始化为10个c字符
vector<unsigned char> vec(10, 'c');
unsigned char charary[vec.size()];
 
//vector全部转到数组
memcpy(charary, &vec[0], vec.size() * sizeof(vec[0]));

//转部分vector数据到数组，最后4个
unsigned char ary1[4];
memcpy(ary1, &vec[6], 4);
```



### 2. map

2.1 map api

insert(pair<T,U>(xxx,xxx));

```c++
map<int, int> hashnum;
hashnum.insert(pair<int, int>(temp, i)); //插入

// 遍历
map<int, int>::iterator it;
for (it = hashnum.begin(); it != hashnum.end(); ++it) {
    cout<<it->first<<" "<<it->second<<endl;
}
```



### 3.set

#### 3.1 set api

insert 返回插入地址的迭代器和是否插入成功的 `bool` 并成的 `pair`

find

erase(value)

```c++
for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    cout << *it << endl;    //取出这个迭代器指向的元素
```

#### 3.2 convert

```c++
// set 和 vector 互相转换
vector<int> vec;
vec = { 1, 2, 3, 4, 8, 9, 3, 2, 1, 0, 4, 8 };
set<int> st(vec.begin(), vec.end());
vec.assign(st.begin(), st.end());
```



### 4. queue

- front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
- back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
- push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
- push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
- pop()：删除 queue 中的第一个元素。
- size()：返回 queue 中元素的个数。
- empty()：如果 queue 中没有元素的话，返回 true。
- emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
- swap(queue \<T\> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。



### 5.deque

 1.Constructors  创建一个新双向队列 

* deque();//创建一个空双向队列 
* deque( size_type size ); // 创建一个大小为size的双向队列 
* deque( size_type num, const TYPE &val ); //放置num个val的拷贝到队列中
* deque( const deque &from ); // 从from创建一个内容一样的双向队列 
* deque( input_iterator start, input_iterator end ); // start 和  end - 创建一个队列，保存从start到end的元素。

2.Operators 比较和赋值双向队列 

可以使用[]操作符访问双向队列中单个的元素 

3.assign() 设置双向队列的值 

```c++
void assign( input_iterator start, input_iterator end);  //start和end指示的范围为双向队列赋值 
void assign( Size num, const TYPE &val );//设置成num个val。
```

4.at() 返回指定的元素 

5.back() 返回最后一个元素 

```c++
reference at( size_type pos ); 返回一个引用，指向双向队列中位置pos上的元素 

reference back();//返回一个引用，指向双向队列中最后一个元素 
```

6.begin() 返回指向第一个元素的迭代器 

7.clear()  删除所有元素

8.empty() 返回真如果双向队列为空 

9.end() 返回指向尾部的迭代器 

10.erase()  删除一个元素 

```c++
iterator erase( iterator pos ); //删除pos位置上的元素 
//删除start和end之间的所有元素
//返回指向被删除元素的后一个元素 
iterator erase( iterator start, iterator end ); 
```

11.front()  返回第一个元素的引用

12.get_allocator()  返回双向队列的配置器 

13.insert()  插入一个元素到双向队列中 

```c++
iterator insert( iterator pos, size_type num, const TYPE &val ); //pos前插入num个val值
void insert( iterator pos, input_iterator start, input_iterator end );  
//插入从start到end范围内的元素到pos前面 
```

14.max_size()  返回双向队列能容纳的最大元素个数 

15.**pop_back()** 删除尾部的元素 

16.**pop_front()** 删除头部的元素 

17.**push_back()** 在尾部加入一个元素 

18.**push_front()**  在头部加入一个元素 

9.rbegin()  返回指向尾部的逆向迭代器 

20.rend() 返回指向头部的逆向迭代器 

21.resize()  改变双向队列的大小 

22.size()  返回双向队列中元素的个数 

23.swap() 和另一个双向队列交换元素     

```c++
void swap( deque &target );// 交换target和现双向队列中元素
```


### 6.stack

```c++
// 快速清空栈
stack<elemType>().swap(s);
```



### 7. Array

```c++
int a[SIZE];
memset(a, 0, sizeof(a));
memset(a, 0, sizeof(int)*1000);//这里的1000是数组大小，需要多少替换下就可以了。 
```



### 8.string

```c++
stringvar.substr(start , [length ])
```

