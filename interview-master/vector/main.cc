#include <stdlib.h>
#include "qh_vector.h"
#include<vector>

int main(int argc, char* argv[])
{
	//TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
	//TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	std::vector<int> v(3);
	qh::vector<int> num_vect(5);
	num_vect[2] = 1;
	int i = num_vect[3];
	num_vect.push_back(1);
	num_vect.clear();

#ifdef WIN32
	system("pause");
#endif

	return 0;
}

