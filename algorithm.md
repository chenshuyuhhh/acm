### hamiton



### sort

#### 二分查找



### 第k小

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

1. i=0时，A数组全部被分到右边，B[j-1] ≤ A[i]

   ![image-20200506203132066](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-1.png)

2. i=m时，A数据全部被分到左边，A[i-1] ≤ B[j]

![image-20200506202605921](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-2.png)

3. 根据下面的推论可知，当i不为上面的值时，j不可能取到边界值：

![image-20200506204735240](/Users/chenshuyu/Code/C:C++/leetcode/pho/k-3.png)