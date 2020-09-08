### 排序

0.库

```c++
#include<algorithm>

// 自定义比较函数
bool cmp(E a,E b){
}

E buf[100];

// 如果没有自定义比较函数，则可以不传最后的函数名
sort(buf, buf+100, cmp);
```



### 日期类



### 并查集



### greedy





### 回溯

```c++
# 算法框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```



### KPM

解题背景：

字符串 s （模式串）是否是字符串 p 的子串，若是，则返回匹配的起始位置，若不是，则返回-1。

> 可用于解字符串匹配问题，
>
> 比如，判断一棵树是否是另一颗数的子树，可以先将树转换成字符串，再用字符串匹配来完成。

**0.暴力匹配算法**

![image-20200507114115885](/Users/chenshuyu/Library/Application Support/typora-user-images/image-20200507114115885.png)

```c++
int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
 
	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
			i++;
			j++;
		}
		else
		{
			//②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
			i = i - j + 1;
			j = 0;
		}
	}
	//匹配成功，返回模式串p在文本串s中的位置，否则返回-1
	if (j == pLen)
		return i - j;
	else
		return -1;
}
```

> 暴力法简单，但是时间复杂度很高为O(mn)
>
> 如何减少匹配次数？
>
> 在上一次匹配中已经成功匹配上的字符能否重复利用？

##### 1. 如何重复利用

举个🌰：

对于给定文本串eababace（i指向它），模式串abac（j指向它），若前面的aca都能匹配上，c匹配不上

* 暴力法：模式串：j=0，给定文本串应：i=i-2

> i=i-2 指向的 b 显然不能和模式串中的首字符a匹配，所以没有必要。
>
> 再看 i=i-1 指向的 a 和模式串中的首字符一样(出现**前缀**)，模式串已经有第一个字符能匹配上，不用再重复匹配，直接从 i 不变，j=1（模式串的第二个字符） 开始匹配，就可以重复利用上一次匹配的结果。

`ps` 为什么不考虑i=i-3，因为i-3对应的是首字符，不具备重复利用的意义

![image-20200507120424736](/Users/chenshuyu/Library/Application Support/typora-user-images/image-20200507120424736.png)



若给的模式串是abc呐？

i = i-1对应的b不是首字符，没有可利用前缀，i不变，j从0开始匹配：

![image-20200507122011412](/Users/chenshuyu/Library/Application Support/typora-user-images/image-20200507122011412.png)

可以总结出如下规律：

假设已经匹配上的字符串为 \[ 0 , j \] ( j < n )，n为模式串s的长度，j+1位置处不能匹配，此时指向给定文本串的位置是i：

* j==0：只有首字符能匹配，i 向后移一位，j从0开始；
* 找出s.substr[ 1 , j ] 中的模式串的前缀s.substr[x,j]，并且这个前缀是位于 s.substr[ 1 , j ]的末尾处（后缀），则可以重复利用这个前缀，j 从 j - x + 1 开始匹配。

> e.g
>
> 比如，abcabbe模式串，能匹配 [ 0, 4 ]，即abcab能匹配，5对应的b不能匹配，则找到的前缀为ab，位于[0,4]的后缀位置处，可重复利用。
>
> 比如，abcabbe模式串，能匹配 [ 0, 5 ]，即abcabb能匹配，对6应的e不能匹配，则找到的前缀为ab，但是由于ab前缀并不是[0,4]的后缀，所以不能重复利用。

##### 2. 如何找出j应当移动多少？

我们用一个数组next[]存：当前j的情况下没有匹配上，下一次j应当指向的位置（0位置处特殊处理）。

举个🌰，我们用人脑算一遍：

当模式串的第0个字符匹配不上时，i 向后移一位，j从0开始；

当模式串的第1个字符匹配不上时（第0个字符能匹配），没有前缀可以重复利用，i不变，j从0开始；

当模式串的第2个字符匹配不上时（第0-1个字符能匹配），1没有前缀可以重复利用，i不变，j从0开始；

当模式串的第3个字符匹配不上时（第0-2个字符能匹配），1-2没有前缀可以重复利用，i不变，j从0开始；

当模式串的第4个字符匹配不上时（第0-3个字符能匹配），1-3有前缀a可以重复利用，i不变，j从1开始；

当模式串的第5个字符匹配不上时（第0-4个字符能匹配），1-4有前缀ab可以重复利用，i不变，j从2开始；

![image-20200507131924675](/Users/chenshuyu/Library/Application Support/typora-user-images/image-20200507131924675.png)







### hamiton



### sort

#### 二分查找





### 第k小

#### 寻找两个有序数组中的第k小

题目描述：

> There are two sorted arrays nums1 and nums2 of size m and n respectively.
>
> Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
>
> You may assume nums1 and nums2 cannot be both empty.
>

e.g.

```c++
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

解题分析：

假设待合并的两个数组为 A (size: m) 和 B (size:n)，既然要求的时间复杂度是lg，一般是将数组分成两部分，可以满足这种时间复杂度。

##### 1.这个中位数应当再哪里？

将数组A分为 [0, i-1] 和 [i, m-1] 两部分（0 <= i <= m），数据B分为 [0, j-1] 和 [j, n-1] 两部分（0 <= j <= n）。

将 left_A 和 left_B放入一个集合，并将 right_A 和 right_B 放入另一个集合。 再把这两个新的集合分别命名为 
left_part 和 right_part：

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

> A有m+1种分法，B有n+1种分法

在满足如下条件情况下（边界情况暂不考虑）：

max(left_part)≤min⁡(right_part)   =>  A[ i-1 ]  ≤  B[ j ] && B[ j-1 ]  ≤  A[ i ] 

* m+n 为偶数：len(left_part)=len(right_part)  =>  i+j = m-i+n-j  =>   i+j = (m+n+1)/2

所求中位数为：**median = (max(left_part)+min⁡(right_part))/2**

* m+n 为奇数：len(left_part)=len(right_part)+1  =>  i+j = m-i+n-j+1  =>   i+j = (m+n+1)/2

所求中位数为：**median = max(left_part) **

##### 2.应当满足什么条件

进一步分析条件：

① 0 ≤ j ≤  n；② j = (m+n+1)/2-i ；③ 0 ≤ i≤ m 

②③ => ④ :  n≥m（不过i取任何值，j 都不为负数）

①② => : 0 ≤  (m+n+1)/2-i ≤  n ，(m-n+1)/2 ≤ i；此条件在④条件下无意义

所以我们需要找到 i 满足

> A[ i-1 ] ≤   B[ j ] && B[ j-1 ]  ≤  A[ i ] ，且 j = (m+n+1)/2-i ，n≥m

##### 3.如何二分搜索找到 i

1. 设imin=0，imax=m，然后开始在[imin,imax]中进行搜索。

2. i = (imin+imax)/2, j = (m+n+1)/2-i 

3. 遇到如下几种情况：

   * A[ i-1 ] ≤ B[ j ]  && B[ j-1 ]  ≤  A[ i ]

     满足条件，直接根据m+n的奇偶性返回值

   * A[ i-1 ] > B[ j ] 

     说明 A[ i-1 ] 太大了，需要将 i 减小，则搜索范围调整为[ imin, i−1 ]，更新 imax 和 i

   * B[ j-1 ] > A[ i ]

     说明A[ i ] 太小了，需要将 i 增大，则搜索范围调整为[ i+1, imax ]，更新 imin 和 i

##### 4. 临界值分析

当 i=0，i=m , j=0 , j=n 时会存在 i-1, i+1 越界的情况。

我们先分析i和j是否会取到临界值：

1. i=0时，A数组全部被分到右边，可能存在j=n的临界值情况，B[j-1] ≤ A[i]

   ![image-20200506203132066](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-1.png)

2. i=m时，A数据全部被分到左边，可能存在j=0的临界值情况，A[i-1] ≤ B[j]

![image-20200506202605921](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-2.png)

3. 根据下面的推论可知，当i不为上面的值时，j不可能取到边界值：

![image-20200506204735240](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-3.png)