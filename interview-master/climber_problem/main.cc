#include <stdio.h>
#include <assert.h>
#include<sstream>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
#define H_ARRAYSIZE(a) \
	((sizeof(a) / sizeof(*(a))) / \
	static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

#define BEG(vec) vec[0] 
#define END(vec) vec[1]
#define HiGH(vec) vec[2]

int  FindIsolatedEnd(int beg, vector<vector<int> > mountains)
{
	int cur = beg;
	if (cur >= mountains.size() - 1)
		return cur;
	while (BEG(mountains[cur+1])<=END(mountains[cur]))
	{
		cur++;
		if (cur >= mountains.size() - 1)
			return cur;
	}
	return cur;
}

int resolve(const char* input)
{
#pragma region 数据保存
	istringstream istr(input);
	int count;
	istr >> count;
	istr.get();
	vector<vector<int> > mountains;
	while (istr.get() != '\n')
	{
		istr.unget();
		vector<int> mt;
		int entry = 0;
		int val = 0;
		while (true)
		{
			while (istr.get() != ',')
			{
				istr.unget();
				istr >> val;
				mt.push_back(val);
				entry++;
			}
			if (entry == 2)
				break;
		}
		istr >> val;
		mt.push_back(val);
		mountains.push_back(mt);
		if (--count == 0)
		{
			break;
		}
		else if (istr.get() == '\n')
		{
			continue;
		}
	}
#pragma endregion
	int res = 0;
	int i = 0;
	res += BEG(mountains[0]);
	int beg = 0;
	int end = 0;
	while (beg<=mountains.size()-1)
	{
		end = FindIsolatedEnd(beg, mountains);
		if (end<mountains.size()-1)
			res += BEG(mountains[end + 1]) - END(mountains[end]);
		res += END(mountains[end]) - BEG(mountains[beg]);
		res += HiGH(mountains[beg]);
		for (int cur = beg; cur < end; cur++)
		{
			res += abs(HiGH(mountains[cur]) - HiGH(mountains[cur + 1]));
		}
		res += HiGH(mountains[end]);
		beg = end + 1;
	}
	return res;
}

int main(int argc, char* argv[])
{
	const char* input[] = {
		"3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
		"1\n1,2,1\n",
		"2\n1,2,1\n2,3,2",
		"3\n1,2,1\n2,3,2\n3,6,1",
		"4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
		"5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
		"1\n0,1,1",
		"2\n0,1,1\n2,4,3",
		"3\n0,1,1\n2,4,3\n3,5,1",
		"4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
		"5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
		//TODO please add more test case here
	};
	int expectedSteps[] = { 25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20 };
	for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
	{
		assert(resolve(input[i]) == expectedSteps[i]);
	}
	cout << "it is ok!" << endl;
	return 0;
}

