#### 1. 数字总是默认都是自然数或者INT

* 考虑负数
* 考虑大数（long甚至更大）
* 考虑浮点数

e.g

Given a 32-bit signed integer, reverse digits of an integer.

```
Input: 123
Output: 321
```

```c++
int reverse(int x) {
    int sum = 0;
    int digit;
    while (x) {
        // 取个位数
        digit = x % 10;
        // 大于INT的最大值
        if ((sum > INT32_MAX / 10) || ((sum == INT32_MAX / 10) && digit > 7))return 0;
        if ((sum < INT32_MIN / 10) || ((sum == INT32_MIN / 10) && digit < -8))return 0;
        sum = sum * 10 + digit;
        x = x / 10;
    }
    return sum;
}
```



#### 2. 忘记 return 返回值



#### 3.参数为指针，没有考虑nullptr的情况（未考虑临界值）



#### 4. / 和 % 用反

