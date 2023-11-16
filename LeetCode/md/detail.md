# detail

---

- **c++ string 和 char[]转换**
  
  > 1. string 转 char[]
  >    
  >    str.c_str()会返回一个const char* ,因此想要得到一个char*,需要使用strcpy
  >    
  >    ```c++
  >    char* cstr;
  >    
  >    strcpy(cstr,s.c_str());//1.
  >    strncpy(cstr,s.c_str(),n);//2.
  >    ```
  > 
  > 2. char[] 转 string
  >    
  >    使用构造方法，string(ch) 或者 string str = ch

- **c++ string与数字类型转换**
  

- **c++ substr()**
  
  > ​    string s = "012345";
  > 
  > ​    string sub1 = s.**substr**(2); //只有一个数字5表示从下标为2开始一直到结尾：sub1 = “2345”
  > 
  > ​    string sub2 = s.**substr**(2, 2); //从下标为5开始截取长度为2位：sub2 = “23”，如果长度超过末尾，只截取到末尾

- **c++ 分割字符串**
  
  > 1. strtok()
  >    
  >    详见zqh作业
  > 
  > 2. find_first_of()和find_first_not_of()
  >    
  >    详见10.md

- 
