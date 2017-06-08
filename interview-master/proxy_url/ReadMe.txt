## Introduction ##

- 该程序在原本提供的程序上，通过调试，找到了通不过的测试用例，并修复了bug
- 具体的测试报告，请参照根目录下的report.md
- 由于自带的Makefile没有问题，所以没有修改Makefile

## Environment ##

- ubuntu 14.04
- g++ (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4













# 程序报告请看根目录下的report.md #

该项目是一道简单的面试题。

该面试题是我们从实际项目中抽出来的，完成一个项目中的局部的一个小功能。

该功能是从原始url中根据提供的参数key将value部分提取出来。

例如：
http://localhost/query.php?name=360&address=beijing

如果给定的参数是那么“name”,那么提取出来的value是“360”
如果给定的参数是那么“address”,那么提取出来的value是“beijing”

具体到实际应用中，有一个url是
“http://www.microsofttranslator.com/bv.aspx?from=&to=zh-chs&xxx&query=http://hnujug.com/”
我们给定的参数key是“query”，因此提取出来的value为“http://hnujug.com/”


项目当前是可以编译通过的，也有一个基本的实现，部分单元测试是对的，但部分单元测试错的。
请实现这个函数：
	void ProxyURLExtractor::Extract( const KeyItems& keys, const std::string& raw_url, std::string& sub_url )
	使得所有的单元测试都通过。

考察点：
	-	核心功能完备
	-	异常分支流程处理正确
	-	构建更多单元测试
	-	尽量优化性能
	-	最好能性能分析报告(gprofile or google profile)

实现完成之后，将工程代码打包(注意包文件名上带上自己的姓名)发给我们，并回答下面的几个问题：
1. 算法的时间复杂度
2. 算法的空间复杂度
3. 是否有资源泄露：内存泄露、文件句柄打开而没有关闭等等

