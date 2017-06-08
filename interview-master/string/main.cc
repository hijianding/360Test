#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

void test1()
{
	qh::string str;
	assert(str.size() == 0);
	assert(str.data() == NULL);
	assert(str.c_str() == NULL);
	//如果字符串下标越界，返回NULL
	assert(str[1] == NULL);
	
	str = "abc";
	assert(str.size() == 3);
	//data(),c_str()返回的是另外一个地址，但是内容和原字符串相同
	//内容测试
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//地址测试
	assert(str.data() != str[0]);
	assert(str.c_str() != str[0]);

	printf("test1 accept\n");
}

void test2()
{
	qh::string str("abc");
	assert(str.size() == 3);
	assert(*str[0] == 'a');
	assert(*str[3] == '\0');
	*str[0] = '1';
	assert(*str[0] == '1');
	//如果字符串下标越界，返回NULL
	assert(str[4] == NULL);

	//data(),c_str()返回的是另外一个地址，但是内容和原字符串相同
	//内容测试
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//地址测试
	assert(str.data() != str[0]);
	assert(str.c_str() != str[0]);

	printf("test2 accept\n");
}

void test3()
{
	qh::string str("abcd", 3);
	assert(str.size() == 3);
	assert(*str[0] == 'a');
	assert(*str[3] == '\0');
	*str[0] = '1';
	assert(*str[0] == '1');
	//如果字符串下标越界，返回NULL
	assert(str[4] == NULL);

	//data(),c_str()返回的是另外一个地址，但是内容和原字符串相同
	//内容测试
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//地址测试
	assert(str.data() != str[0]);
	assert(str.c_str() != str[0]);

	printf("test3 accept\n");
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
	test1();
	test2();
	test3();
	printf("it is ok!\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}


