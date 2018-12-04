//
//  consumer.cpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#include "consumer.hpp"
#include <optional>
#include <iostream>
#include <iomanip>

void consumer_func(ConcurrentQueue<knu_msg> &queue){
    while(true) {
        // run as fast as possible
        std::optional<knu_msg> msg = queue.pop();
        
        if(msg) {
            std::cout << msg->index << ": " << std::setw(10) << msg->msg << "\n";
            
            if(msg->index >= 9) // last message
                break;
        }
    }
}
