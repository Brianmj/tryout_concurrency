//
//  consumer.hpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#ifndef consumer_hpp
#define consumer_hpp

#include "my_concurrent_queue.hpp"
#include "my_message.hpp"

void consumer_func(ConcurrentQueue<knu_msg> &queue);

#endif /* consumer_hpp */
