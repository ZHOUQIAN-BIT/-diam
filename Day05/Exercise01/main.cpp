# include <thread>
# include <iostream>
# include <string>
# include <memory>
# include <mutex>


int num = 0;
std::timed_mutex m;

void threadFunction() {
    // Add your code here
    std::cout << "hello, world1!" << std::endl;
};

void threadFunction2(std::string message) {
    // Add your code here
    std::cout << message << std::endl;
};

class A{
    public:
        void operator()(){
            std::cout << "hello, world5!" << std::endl;
        }

        static std::shared_ptr<A> getSharedPtr(){
            return std::make_shared<A>();
        }
};

// void count(){
//     for(int i = 0; i < 1000000; i++){

//         m.lock();
//         num++;
//         m.unlock();
//     }
// }


// void count(){
//     for(int i = 0; i < 1000000; i++){
//         std::lock_guard<std::mutex> lock(m);
//         num++;
//     }
// }

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

int main(){
    // Start thread
    std::thread t(threadFunction);

    std::string message = "hello, world2!";
    std::thread t2(threadFunction2, message);

    // Wait for thread to finish
    t.join();
    t2.join();

    std::string message2 = "hello, world3!";
    std::thread t3([message2](){
        std::cout << message2 << std::endl;
    });

    t3.detach();// detach the thread from the main thread


    std::thread t4([](){
        std::cout << "hello, world4!" << std::endl;
    });

    bool  isRun = t4.joinable();// check if the thread is joinable
    if(isRun){
        t4.join();
    }

    std::shared_ptr<A> a = A::getSharedPtr();

    std::thread t5(*a);
    t5.join();

    std::shared_ptr<A> a2 = std::make_shared<A>();

    std::thread t6(count);
    std::thread t7(count);

    t6.join();
    t7.join();


    std::cout << num << std::endl;

    for(int i = 0; i < 10; i++){
        std::thread t8([](){
            Log::get_instance()->print_time();
        });
        t8.join();
    }

    return 0;
}