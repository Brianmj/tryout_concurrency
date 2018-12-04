//
//  producer.hpp
//  producer_consumer_tryout
//
//  Created by Brian Jones on 12/3/18.
//  Copyright © 2018 Brian Jones. All rights reserved.
//

#ifndef producer_h
#define producer_h

#include "my_concurrent_queue.hpp"
#include "my_message.hpp"

void producer_func(ConcurrentQueue<knu_msg> &queue);

#endif /* producer_h */
