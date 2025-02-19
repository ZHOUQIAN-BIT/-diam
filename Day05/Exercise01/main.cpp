# include <thread>
# include <iostream>

void threadFunction() {
    // Add your code here
    std::cout << "hello, world1!" << std::endl;
};

void threadFunction2(std::string message) {
    // Add your code here
    std::cout << message << std::endl;
};


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

    return 0;


}