# 获取时间

**ctime头文件中包含的方法可以获取当前年份、月份直到秒**

```c++
#include<ctime>
#include<sstream>
#include<iostream>

using namespace std;

int main() {
    time_t now = time(NULL);
	tm* t = localtime(&now);

	// 将信息输出到字符串流
	stringstream ss;
	ss << t->tm_year + 1900 << "." << t->tm_mon + 1 << "." <<
		t->tm_mday << ".." << t->tm_hour << "." << t->tm_min << "." << t->tm_sec;
	cout <<  ss.str() << endl;
    return 0;
}
```



**`值得注意的是有的时候需要对时间进行格式化输出，比如YY-MM-DD，则可以考虑strftime()方法`**

```c++
size_t strftime(
char *strDest, //目标字符串
size_t maxsize,//最多传出字符数量
const char *format,//格式化方式
const  struct tm *timeptr //tm指针
);
```

则程序可以变为

```c++
#include<ctime>
#include<sstream>
#include<iostream>

using namespace std;

int main() {
    time_t now = time(NULL);
	tm* t = localtime(&now);
	
	char now_time[64];
	strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", t);
	std::cout << now_time << std::endl;
	
    return 0;
}
```

也可以采用sprintf()方法进行格式化输出，效果差不多。

[!更多](https://cloud.tencent.com/developer/article/1732371)



# 程序计时

**`有的时候想要对程序运行了多长时间进行测试，C/C++中的计时函数是clock()，而与其相关的数据类型是clock_t，示例如下`**

```c++
#include< stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start, finish;
	start = clock();
    
    /*code here*/
    
	finish = clock();
	auto Total_time = (double)(finish - start) / CLOCKS_PER_SEC; //单位换算成秒
	printf("%f seconds\n", Total_time);
	return 0;
}
```