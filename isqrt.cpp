// isqrt.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/* 出力例
sqrt(                   0) =                 0.00 =                    0
sqrt(                  15) =                 3.87 =                    3
sqrt(                  53) =                 7.28 =                    7
sqrt(                 193) =                13.89 =                   13
sqrt(                 456) =                21.35 =                   21
sqrt(               46340) =               215.27 =                  215
sqrt(          4200000000) =             64807.41 =                64807
sqrt(   12345678901234567) =         111111110.61 =            111111110
sqrt(       1111111111111) =           1054092.55 =              1054092
sqrt( 9223372036854775807) =        3037000499.98 =           3037000499
sqrt(18446744073709551615) =        4294967296.00 =           4294967295		← sqrt(double) が 18446744073709551615 有効桁数が足りないため

http://itchyny.hatenablog.com/entry/20101222/1293028538 より

 */

#include "stdafx.h"

#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned __int64 mysqrt(unsigned __int64);

int main() {
	unsigned __int64 arr[] = { 0, 15, 53, 193, 456, 46340, 4200000000, 12345678901234567, 1111111111111, _I64_MAX, _UI64_MAX };
	
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		unsigned __int64 ans = mysqrt(arr[i]);
		printf("sqrt(%20llu) = %20.2lf = %20llu \n", arr[i], sqrt(arr[i]), ans);
	}
	
	return 0;
}

unsigned __int64 mysqrt(unsigned __int64 x) {
	unsigned __int64 a = 0, c = 0, y = 0, t = x;
	int i = 0;
	while (t >>= 1) {
		++i;
	}
	for (i += i & 1; i >= 0; i -= 2) {
		c = (y << 1 | 1) <= x >> i;
		a = a << 1 | c;
		y = y << 1 | c;
		x -= c * y << i;
		y += c;
	}
	return a;
}
