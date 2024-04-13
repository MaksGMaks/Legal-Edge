#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <unordered_map>

class ThreadPool
{
private:
    std::queue<std::function<void()>> tasks;
    std::vector<std::thread> threads;

    std::condition_variable cond;
    std::mutex qMutex;
    bool stop;

public:
    ThreadPool(int numThr);
    ~ThreadPool();

    template <class F>
    void enqueue(F &&task)
    {
        {
            std::cout << "METHOD: enqueue" << std::endl;
            std::unique_lock<std::mutex> lock(qMutex);
            tasks.emplace(std::forward<F>(task));
        }
        cond.notify_one();
    }

    void stoped();
};