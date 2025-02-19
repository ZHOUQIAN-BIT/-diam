# 多线程使用

## 接口介绍

1. 创建线程,并使用join运行

   ```c++
    void threadFunction() {
        // Add your code here
        std::cout << "hello, world1!" << std::endl;
    };

    int main(){
        std::thread t(threadFunction);
        bool isJoin = t.joinable();
        if(isJoin){
            t.join();
        }
    }
   ```

2. 令子线程后台执行

   ```c++
    void threadFunction() {
        // Add your code here
        std::cout << "hello, world1!" << std::endl;
    };

    int main(){
        std::thread t(threadFunction);
        t.detach();

    }
   ```

3. 调用引用类型变量

    ```c++
    class A{
        public:
            void operator()(){
                std::cout << "hello, world5!" << std::endl;
            }

            static std::shared_ptr<A> getSharedPtr(){
                return std::make_shared<A>();
            }
    };

    int main(){

        std::shared_ptr<A> a = A::getSharedPtr();
        std::thread t(*a);

    }
    ```

4. 调用mutex进行加锁操作

    ```c++
    int num = 0;
    std::mutex m;
    void count(){
        for(int i = 0; i < 1000000; i++){
            m.lock();
            num++;
            m.unlock();
        }
    }

    int main(){
        std::thread t6(count);
        std::thread t7(count);

        t6.join();
        t7.join();
    }
    ```

5. 自动进行加锁操作

    ```c++
    int num = 0;
    std::mutex m;
    void count(){
        for(int i = 0; i < 1000000; i++){
            std::lock_guard<std::mutex> lock(m);
            num++;
        }
    }

    int main(){
        std::thread t6(count);
        std::thread t7(count);

        t6.join();
        t7.join();
    }
    ```

6. unique_lock的接口测试

    ```c++
    int num = 0;
    std::timed_mutex m;
    void count(){
        for(int i = 0; i < 2; i++){
            std::unique_lock<std::timed_mutex> lock(m,std::defer_lock);
            bool isLock = lock.try_lock_for(std::chrono::seconds(1));
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if(isLock){
                num++;
            }
        }
    }

    int main(){
        std::thread t6(count);
        std::thread t7(count);

        t6.join();
        t7.join();
    }
    ```

7. call_once的执行

    ```c++
    static std::once_flag flag;

    class Log{
        public:
            Log(){
                std::cout << "Logger created" << std::endl;
            }

            Log(const Log& other) = delete;
            Log& operator=(const Log& other) = delete;

            void print_time(){
                std::cout<<__TIME__<<std::endl;
            }

            static Log* get_instance(){
                std::call_once(flag, [](){
                    logger = new Log();
                });
                return logger;
            }

            ~Log(){
                std::cout << "Logger destroyed" << std::endl;
            }

        private:
            static Log* logger;
    };
    Log* Log::logger = Log::get_instance();
    ```
