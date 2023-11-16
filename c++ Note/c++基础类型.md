# C++ 基础类型记录

## g++ version

![image-20221102183537204](.\pic\image-20221102183537204.png)

## int 类型

```cpp
#include <iostream>

int main(){
    std::cout << "sizeof int:" << sizeof(int) << std::endl;
    std::cout << "sizeof unsigned int:" << sizeof(unsigned int) << std::endl;
    std::cout << "sizeof long:" << sizeof(long) << std::endl;
    std::cout << "sizeof unsigned long:" << sizeof(unsigned long) << std::endl;
    std::cout << "sizeof long long:" << sizeof(long long) << std::endl;
    std::cout << "sizeof unsigned long long:" << sizeof(unsigned long long) << std::endl;

    std::cout << "sizeof int8_t:" << sizeof(int8_t) << std::endl;
    std::cout << "sizeof int16_t:" << sizeof(int16_t) << std::endl;
    std::cout << "sizeof int32_t:" << sizeof(int32_t) << std::endl;
    std::cout << "sizeof int64_t:" << sizeof(int64_t) << std::endl;

    std::cout << "sizeof uint8_t:" << sizeof(uint8_t) << std::endl;
    std::cout << "sizeof uint16_t:" << sizeof(uint16_t) << std::endl;
    std::cout << "sizeof uint32_t:" << sizeof(uint32_t) << std::endl;
    std::cout << "sizeof uint64_t:" << sizeof(uint64_t) << std::endl;

    return 0;
}
```

**`输出如下`**

> sizeof int:4
> sizeof unsigned int:4
> sizeof long:8
> sizeof unsigned long:8
> sizeof long long:8
> sizeof unsigned long long:8
> sizeof int8_t:1
> sizeof int16_t:2
> sizeof int32_t:4
> sizeof int64_t:8
> sizeof uint8_t:1
> sizeof uint16_t:2
> sizeof uint32_t:4
> sizeof uint64_t:8

## **区别与不同**

1. uint8_t 和 int8_t这种类型的基本类型，都是经过typedef重命名定义的，其中u表示unsigned

2. 取值范围与对应关系如下

   

| Specifier  | Common Equivalent    | Signing  | Bits | Bytes | Minimum Value              | Maximum Value              |
| ---------- | -------------------- | -------- | ---- | ----- | -------------------------- | -------------------------- |
| `int8_t`   | `signed char`        | Signed   | 8    | 1     | -128                       | 127                        |
| `uint8_t`  | `unsigned char`      | Unsigned | 8    | 1     | 0                          | 255                        |
| `int16_t`  | `short`              | Signed   | 16   | 2     | -32,768                    | 32,767                     |
| `uint16_t` | `unsigned short`     | Unsigned | 16   | 2     | 0                          | 65,535                     |
| `int32_t`  | `int`                | Signed   | 32   | 4     | -2,147,483,648             | 2,147,483,647              |
| `uint32_t` | `unsigned int`       | Unsigned | 32   | 4     | 0                          | 4,294,967,295              |
| `int64_t`  | `long long`          | Signed   | 64   | 8     | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807  |
| `uint64_t` | `unsigned long long` | Unsigned | 64   | 8     | 0                          | 18,446,744,073,709,551,615 |

