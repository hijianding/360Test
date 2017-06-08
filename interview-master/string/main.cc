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
	//����ַ����±�Խ�磬����NULL
	assert(str[1] == NULL);
	
	str = "abc";
	assert(str.size() == 3);
	//data(),c_str()���ص�������һ����ַ���������ݺ�ԭ�ַ�����ͬ
	//���ݲ���
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//��ַ����
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
	//����ַ����±�Խ�磬����NULL
	assert(str[4] == NULL);

	//data(),c_str()���ص�������һ����ַ���������ݺ�ԭ�ַ�����ͬ
	//���ݲ���
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//��ַ����
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
	//����ַ����±�Խ�磬����NULL
	assert(str[4] == NULL);

	//data(),c_str()���ص�������һ����ַ���������ݺ�ԭ�ַ�����ͬ
	//���ݲ���
	assert(str.data()[0] == *str[0]);
	assert(str.c_str()[0] == *str[0]);
	//��ַ����
	assert(str.data() != str[0]);
	assert(str.c_str() != str[0]);

	printf("test3 accept\n");
}

int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	test1();
	test2();
	test3();
	printf("it is ok!\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}


