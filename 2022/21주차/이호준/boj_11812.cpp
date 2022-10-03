/*******************************************************************
Algorithm Study
BAEKJOON 21주차
11812 K진트리
2022/09/30 이호준
# 아이디어
1. LCA 공식 (최단 공통 부모 찾기)
P = (a + k - 2) / k
*******************************************************************/

#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;
typedef long long ll;
ll getParent(ll a, int k) {
    return (a + k - 2) / k;
}

int main(void){
    ll n;
    int k, q;
    scanf("%lld %d %d", &n, &k, &q);
    while(q--){
        ll left, right;
        scanf("%lld %lld", &left, &right);
        if (k == 1) {
            printf("%lld\n", abs(left - right));
            continue;
        }
        int len = 0;
        while(left !=right){
            while(left>right){
                len++;
                left=getParent(left,k);
            }
            while(right>left){
                len++;
                right=getParent(right,k);
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
