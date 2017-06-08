#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "qh_vector.h"


void test1()
{
	size_t size = 10;
	qh::vector<int> num_vect;
	assert(num_vect.empty() == true);
	//push_back
	for (int i = 0; i < size; i++)
	{
		num_vect.push_back(i);
	}
	assert(num_vect.size() == size);
	assert(num_vect[0] == 0);
	assert(num_vect[4] == 4);
	assert(num_vect[9] == 9);
	//=
	qh::vector<int> num_vect_other;
	num_vect_other = num_vect;
	assert(num_vect_other.size() == size);
	assert(num_vect_other[0] == 0);
	assert(num_vect_other[4] == 4);
	assert(num_vect_other[9] == 9);
	//set
	num_vect[9] = 10;
	assert(num_vect[9] == 10);
	//deep clone
	assert(num_vect_other[9] == 9);

	//pop_back
	num_vect.pop_back();
	assert(num_vect.size() == size - 1);
	//clear
	num_vect.clear();
	assert(num_vect.size() == 0);
	//resize
	num_vect.resize(5);
	assert(num_vect.size() == 5);
	assert(num_vect[0] == 0);
	assert(num_vect[4] == 0);

	printf("test1 accept\n");
}

void test2()
{
	size_t size = 10;
	qh::vector<int> num_vect(size);
	assert(num_vect.empty() == false);
	//push_back
	for (int i = 0; i < size; i++)
	{
		num_vect[i] = i;
	}
	assert(num_vect.size() == size);
	assert(num_vect[0] == 0);
	assert(num_vect[4] == 4);
	assert(num_vect[9] == 9);
	//=
	qh::vector<int> num_vect_other;
	num_vect_other = num_vect;
	assert(num_vect_other.size() == size);
	assert(num_vect_other[0] == 0);
	assert(num_vect_other[4] == 4);
	assert(num_vect_other[9] == 9);
	//set
	num_vect[9] = 10;
	assert(num_vect[9] == 10);
	//deep clone
	assert(num_vect_other[9] == 9);

	//pop_back
	num_vect.pop_back();
	assert(num_vect.size() == size - 1);
	//clear
	num_vect.clear();
	assert(num_vect.size() == 0);
	//resize
	num_vect.resize(5);
	assert(num_vect.size() == 5);
	assert(num_vect[0] == 0);
	assert(num_vect[4] == 0);
	
	printf("test2 accept\n");
}


int main(int argc, char* argv[])
{
	//TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
	//TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

	test1();
	test2();
	printf("it is ok!\n");

#ifdef WIN32
	system("pause");
#endif

	return 0;
}


