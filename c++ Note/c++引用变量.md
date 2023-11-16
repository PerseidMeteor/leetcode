# c++不建议返回指向局部变量的引用

### 1.  类定义如下

```cpp
#include <iostream>
using namespace std;
class Person
{
public:
 int num;
 ~Person()
 {
 cout << "调用析构函数 num:" << this->num << " destroy addr:" << this << endl;
 };
 Person(const Person &p) : num(p.num)
 {
 cout << "调用拷贝函数 copy num:" << p.num << " copy addr:" << &p << endl;
 }
 Person()
 {
 cout << "调用默认构造函数" << endl;
 }
};
```

### 2.返回对象或引用

**`函数返回对象，编译器会进行优化，如下：`**

```cpp
Person fun()
{
    Person p; //默认构造

    p.num = 2;

    cout << &p << endl; //输出0x7ffc9ccf3d14
    return p;
}

void Testobj()
{
    auto p2 = fun();

    cout << &p2 << endl;
}
/**
 * @brief 从fun到main
 * 1.fun 首先构造p
 * 2.编译器调用拷贝函数拷贝一个临时对象
 * 3.fun 析构p
 * 4.main函数调用拷贝构造函数，构造一个新的Person p2，内容和fun的p一致，但是地址不同
 * 5.编译器析构临时对象
 * 6.Testfun函数在结束后调用析构函数析构p2
 *
 * g++ test.cc -fno-elide-constructors -o testasd && ./testasd 输出:
 * 调用默认构造函数。。。。。。
   0x7ffc9ccf3d14
   调用拷贝函数。。。。。。
   调用析构函数。。。。。。
   调用拷贝函数。。。。。。
   调用析构函数。。。。。。
   0x7ffc9ccf3d40
   调用析构函数。。。。。。

 *
 * 注意，编译器会对这个过程优化，仅存在1、6两个步骤，同时p,p2的地址也是相同的
 *
 * 输出:
 * 调用默认构造函数。。。。。。
    0x7ffcd18ffea4
    0x7ffcd18ffea4
    调用析构函数。。。。。。
 */
```

**`返回局部变量的引用，则会造成局部变量释放之后，引用指向的地址内容可能会发生变化，具体看注释与链接`**

> [C++返回局部变量的引用是安全的吗？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/55304812)

```cpp
/**
 * @brief fun2 为错误用法，
 *
 *
 * Testref输出如下，可以看到num值不同，已经被覆盖了
 *
 *
 *
 * 调用默认构造函数
 调用析构函数 num:3 copy addr:0x7ffc10e56960
 ...
 Person num:0 addr:0x7ffc10e56960
 Person num:0 addr:0x7ffc10e56960
 *如果直接调用，比如std::cout << fun2().num的值可能来不及覆盖，可能是3
 */
Person &fun2()
{
 Person p; //默认构造
 Person &ref = p;
 p.num = 3;
 // cout << "Person num:" << ref.num << " addr:" << &ref << endl;
 return ref;
}
void Testref()
{
 //两种情况不同，第二种步骤更少
 // auto p1 = fun();
 cout << "---------------------------------" << endl;
 cout << "Person num:" << fun2().num << " addr:" << &fun2()<<endl;
 cout << "---------------------------------" << endl;
 auto& p5 = fun2();
 cout << "Person num:" << p5.num << " addr:" << &p5 << endl;
 cout << "Person num:" << p5.num << " addr:" << &p5 << endl;
}
```

### 3.以引用作为返回值的使用场景与方法

- 有参数传进函数，如  Person&  (Person&  a , Person&  b)
