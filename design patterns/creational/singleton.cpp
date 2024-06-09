#include <mutex>
#include <iostream>
#include <thread>
#include <string>

using namespace std;

class Singleton
{
private:
    string value_;
protected:
    Singleton(const string val) : value_(val) {};
    ~Singleton();
    static Singleton *singleton_;
    static std::mutex mutex_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const string &val);

    string value();
};

Singleton *Singleton::singleton_ = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const string &val) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(val);
    }

    return singleton_;
}

string Singleton::value() {
    return value_;
}

void ThreadFoo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}

int32_t main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
