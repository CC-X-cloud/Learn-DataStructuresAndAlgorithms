#include "SlideRule.h"
#include "simplesort.h"
#include <algorithm>
using namespace std;

int main() {
	//对数器主要用于生成随机数组，作为测试数据
	int Times = 1000; //测试次数
	int maxsize = 100; //数组最大长度
	int maxvalue = 100; //数组最大值
	bool succeed = true; //标记是否成功

	for(int i = 0 ; i< Times ; i++) {
		// 生成随机数组
		SlideRule sr;
		int* arr = sr.generate_random_array(maxsize, maxvalue);

		// TODO: 在这里添加对生成的随机数组的测试代码
		


		// 释放内存
		delete[] arr;
	}

	return 0;
}
