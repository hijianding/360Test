#include "ini_parser.h"

#include <string.h>
#include <assert.h>

void test1()
{
	const char* ini_text = "a=1\nb=2\n";
	qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");

	std::string b = parser.Get("b", NULL);
	assert(b == "2");

	const std::string& c = parser.Get("c", NULL);
	assert(c == "");
}

void test2()
{
	const char* ini_text = "a=1||b=2||c=3";
	qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");

	std::string b = parser.Get("b", NULL);
	assert(b == "2");

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3");
}

void test3()
{
	const char* ini_text = "||||a:1||b:2||||c:3||||||";
	qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");

	std::string b = parser.Get("b", NULL);
	assert(b == "2");

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3");
}

void test4()
{
	const char* ini_text = "||[s1]||a:1||b:2||b=3||c:3||d=4|||||e:5||[[s2]||a:2";
	qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("s1","a", NULL);
	assert(a == "1");

	std::string b = parser.Get("b", NULL);
	assert(b == "");

	const std::string& c = parser.Get("s2","a", NULL);
	assert(c == "");
}

void test5()
{
	const char* ini_text = "||		 [s1]	||    a  : 1	||b	:	2||b	=3||	c	:	3||d=4||	  ||	e:5||[[s2]||a:2";
	qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("s1", "a", NULL);
	assert(a == "1");

	std::string b = parser.Get("b", NULL);
	assert(b == "");

	const std::string& c = parser.Get("s2", "a", NULL);
	assert(c == "");
}

void test6()
{
	const char* ini_file_path = "./test.txt";
	qh::INIParser parser;
	if (!parser.Parse(ini_file_path)) {
		assert(false);
	}
			
	const std::string& a = parser.Get("s1", "a", NULL);
	assert(a == "");

	std::string b = parser.Get("b", NULL);
	assert(b == "2");

	const std::string& c = parser.Get("s2", "c", NULL);
	assert(c == "4");
}

int main(int argc, char* argv[])
{
	//TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

	test1();
	test2();
	test3();

	test4();
	test5();
	test6();

	printf("it is ok!\n");
	return 0;
}



