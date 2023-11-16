# libgen.h 函数

## basename()

basename()方法可以获得路径上的文件名，比如 **basename("/usr/lib/a.cc")** 返回值为 **a.cc**



## dirname()

这个函数存在一些问题，目前尝试下来只有这个写法没有段错误,需要strdup()函数。

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char **argv)
{
	char *dirc, *basec, *bname, *dname;
	const char *path = "/usr/lib";

	dirc = strdup(path);
	basec = strdup(path);
	dname = dirname(dirc);
	bname = basename(basec);
	printf("dirname=%s, basename=%s\n", dname, bname);
	free(dirc);
	free(basec);

	return 0;
}

```

