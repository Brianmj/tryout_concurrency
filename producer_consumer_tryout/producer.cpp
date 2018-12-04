//
//  producer.cpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#include "producer.hpp"
#include <chrono>

using namespace std::chrono_literals;

void producer_func(ConcurrentQueue<knu_msg> &queue){
    
    std::vector<std::string> vs {"the one and only",
        "true power comes to those who deserve it",
        "gonna try for a job",
        "Lua programming",
        "Raaashiiiiidoooooo",
        "The Rust Programming Language",
        "OpenGL 2/(right - left) to calculate the span of range mapped to 0-1",
        "Very important formula, the previous message",
        "Java 8 SE",
        "The last line",
    };
    
    
    for(int i = 0; i < 10; ++i) {
        knu_msg msg {i, vs[i]};
        
        queue.push(msg);
        
        std::this_thread::sleep_for(2s);
    }
}
