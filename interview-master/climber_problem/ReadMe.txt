## Introduction ##

- 完成一个用户在二维空间的排山路径的计算问题
- 每座山被结构化成一个三元组（起点坐标，终点坐标，高度）
- 每座山的输入应该符合常识，比如不应该出现山中夹着山的情况，比如（1,6,3）、（2,3,5）、（4,5,6），这种情况，应该把山分割成符合常识的5座山来进行合法输入

## Environment ##

- ubuntu 14.04
- g++ (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4



题目内容请通过图片链接阅读：https://github.com/zieckey/interview/blob/master/climber_problem/The%20problem.png  
### 测试用例说明 ###
测试用在在main.cc中的main函数的数组中有表示，程序通过了其中的测试用例。
