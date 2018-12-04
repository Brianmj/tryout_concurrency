//
//  my_concurrent_queue.hpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#ifndef my_concurrent_queue_h
#define my_concurrent_queue_h

#include <vector>
#include <thread>
#include <optional>
#include <mutex>                // need this for scoped_lock

template<typename T, int max_buffers = 5>
class ConcurrentQueue {
private:
    std::mutex mu;
    std::vector<T> queue;
    
public:
    ConcurrentQueue():mu{}, queue(){
        queue.reserve(max_buffers);
    }
    
    ConcurrentQueue(ConcurrentQueue &other) = delete;
    ConcurrentQueue &operator=(ConcurrentQueue &other) = delete;
    
    ConcurrentQueue(ConcurrentQueue &&other) = delete;
    ConcurrentQueue &operator=(ConcurrentQueue &&other) = delete;
    
    // for now, if the queue is full, push an item in the queue is a no-op
    void push(T val) {
        std::scoped_lock lk{mu};
        if(queue.size() < max_buffers) {
            queue.emplace_back(val);
        }
    }
    
    std::optional<T> pop() {
        std::scoped_lock lk{mu};
        if(!queue.empty()) {
            T val{ std::move(queue.front())};
            queue.erase(queue.begin());
            return std::optional<T>{std::move(val)};
        }
        
        return {};  // return null optional?
    }
};


#endif /* my_concurrent_queue_h */
