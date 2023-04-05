# c++在类中使用static和const的用法

我用到的几个场景：

* 第一种

    如果类里面需要定义一个数组，比较好的方式在把size写为static const（在类中可见）
    ```
    class CO_SCHEDULE
    {
    public:
        // xxxx

    private:
        static const int STACK_SIZE = 1024 * 1024;
        char stack[STACK_SIZE];
    };
    ```

* 第二种
    类中定义static变量

    而静态数据成员被当作是类的成员。也就是说，静态数据成员是该类的所有对象所共有的。对该类的多个对象来说，静态数据成员只分配一次内存，供所有对象共用。所以，静态数据成员的值对每个对象都是一样的，**它的值可以更新**。
    ```
    class Myclass
    {
    public:
        int val;
        static int mysum;
    };
    int Myclass::mysum = 0;   // 定义放在类的外面，并且这个不需要再写static了

    int main()
    {
        cout << Myclass::mysum++ << endl;
        cout << Myclass::mysum << endl;
        return 0;
    }
    ```

* 第三种

    在函数中定义static，这样可以避免反复初始化一个变量。
    ```
    struct LARGE_STRUCT
    {
        // 一个特定大的结构体
    };

    int test_func()
    {
        static LARGE_STRUCT obj;        // 定义为static，这个可以避免每次调用这个函数的时候，会进行初始化
        memset(&obj, 0, sizeof(obj));  
    }
    ```


* 第四种

    这个是val的可见性只在当前文件内部可见。避免了暴露不必要的符号。
    ```
    static int val;  // 定义一个全局static变量
    ```

* 第五种

    在程序中定义全部变量的时候
    file1.cpp
    ```
    XXX obj1;   // 定义一个全局变量
    ```

    file2.cpp
    ```
    cout << obj1.val << endl;   // 在另外一个文件访问
    ```

    我一般会写成这样：
    file1.cpp
    ```
    XXX& get_obj()
    {
        static XXX obj1;   // 定义一个全局变量
        return ob1;
    }
    ```

    file2.cpp
    ```
    cout << get_obj().val <<endl;
    ```
    
    这样除了封装了一个接口之外，更重要的好处是可以避免 由于多个（相互依赖的）全局变量初始化顺序不同而导致的初始化问题。（https://github.com/zhaozhengcoder/CoderNoteBook/blob/master/note/c%2B%2B%E5%A4%9A%E4%B8%AA%E6%96%87%E4%BB%B6%E9%93%BE%E6%8E%A5%E5%88%9D%E5%A7%8B%E5%8C%96%E9%A1%BA%E5%BA%8F%E9%97%AE%E9%A2%98.md）

* 关于static的其他
    一个进程中，static和全局变量会被放在程序的数据段和bss段里面。（取决于是否初始化，没有初始化的放在bss段里面）。也就是说，在程序进入mian之前，这样已经被分配好的了。

    可以参考：https://www.jianshu.com/p/f9760cb3cea2

