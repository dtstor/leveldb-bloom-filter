/*
 * test.cc
 *
 *  Created on: 2016Äê5ÔÂ12ÈÕ
 *      Author: gzl
 */

#include "stdio.h"
#include "bloomfilter.h"
#include <string>

#define TESTCOUNT 100000

int main() {
	BloomFilterPolicy* filter = new BloomFilterPolicy(10);
	std::string dst, keys[TESTCOUNT];
	char buf[10];
	int true_count=0, false_count=0;
	bool rst;

	for(int i=0; i<TESTCOUNT; i++){
		sprintf(buf, "key%d", i);
		keys[i] = std::string(buf);
	}
	filter->CreateFilter(keys, TESTCOUNT, &dst);

	for(int i=0; i<TESTCOUNT*10; i++){
		sprintf(buf, "key%d", i);
		rst = filter->KeyMayMatch(std::string(buf), dst);
//		printf("%s result : %d\n", buf, rst);
		if(rst)
			true_count++;
		else
			false_count++;
	}
	printf("true_count:%d, false_count:%d\n", true_count, false_count);
	printf("false positive count:%d, false positive ratio:%.3f\n", true_count-TESTCOUNT, (float)(true_count-TESTCOUNT)/(TESTCOUNT*9));

	return 0;
}
