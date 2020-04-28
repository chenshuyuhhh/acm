# c++常用语法总结

### 1.vector

#### 1.1 vector api

size() 大小

push_back() 加入

emplace_back() 创建新的加入

pop_back() 取出最后一个元素

back() 获得最后一个元素

insert() 指定位置插入元素

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

