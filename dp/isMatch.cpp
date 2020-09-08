#include <string>
#include <iostream>
using namespace std;
//
// Created by 陈姝宇 on 2020/6/4.
//

bool isMatch(string s, string p) {
    s+="$";
    p+="$";
    bool dp[s.size()+1][p.size()];
    // i-->s
    // j-->p
    for(int i = s.size()-1; i >= 0 ; --i){
        for(int j = p.size()-1; j >= 0; --j){
            // single char is matched ?
            bool singleMatch = ( i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if( j+1 < p.size() && p[j+1] == '*'){ // 0 or more
                // aaaac 和 a*c
                // 对于最末尾的a也是可以的，因为c可以是匹配了0次a
                if(j+2 < p.size()) { // 0 time || 1 time
                    dp[i][j] = dp[i][j+2];
                    if(i+1 < s.size()) dp[i][j] = dp[i][j] || singleMatch && dp[i+1][j];
                    // i == s.size()-1, j+2<p.size(),说明p还剩得有字符串
                }else {
                    dp[i][j] = singleMatch;
                    if(i+1 < s.size()) dp[i][j] = dp[i][j] && dp[i+1][j];
                    // i == s.size()-1, j+2 =p.size(),说明p没有多余字符
                }
            }else {
                // 当前字符匹配，后面的字符也匹配
                if(i+1 < s.size() && j+1 < p.size()) dp[i][j] = singleMatch && dp[i+1][j+1];
                else if( i+1 < s.size() || j+1 < p.size() ) dp[i][j] = false;
                else dp[i][j] = singleMatch;
            }
            cout<<i<<" "<<j<<" "<<dp[i][j]<<"|";
        }
    }
    return dp[0][0];
}
