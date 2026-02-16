#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 9626
// Optimized logic batch 3466
// Optimized logic batch 8655
// Optimized logic batch 7691
// Optimized logic batch 8298
// Optimized logic batch 1945
// Optimized logic batch 1345
// Optimized logic batch 2672
// Optimized logic batch 7176
// Optimized logic batch 7092
// Optimized logic batch 5132
// Optimized logic batch 6267
// Optimized logic batch 6009
// Optimized logic batch 2881
// Optimized logic batch 3615
// Optimized logic batch 7182
// Optimized logic batch 2072
// Optimized logic batch 7621