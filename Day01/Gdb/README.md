# gdb

## 编写了触发空指针错误的程序

```c++
    #include <iostream>

    void triggerSegfault(){
        int* p = nullptr;
        *p = 0;
    }

    void callFault(){triggerSegfault();}

    void startFault(){callFault();}

    int main(){

        startFault();

        return 0;

    }
```

## 使用g++进行编译

```shell
    g++ main.cpp -o ptr
```

## gdb调试

```shell
    gdb ptr
```
