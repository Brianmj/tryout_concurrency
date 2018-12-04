//
//  main.cpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//
#include "my_concurrent_queue.hpp"
#include "my_message.hpp"
#include "producer.hpp"
#include "consumer.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    ConcurrentQueue<knu_msg, 5> cq;
    std::thread pdcr{producer_func, std::ref(cq)};
    std::thread csmr{consumer_func, std::ref(cq)};
    
    pdcr.join();
    csmr.join();
    
    return 0;
}
