#include "algorithms/priority/priority_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"


/*
    Here is where you should define the logic for the priority algorithm.
*/

PRIORITYScheduler::PRIORITYScheduler(int slice) {
    if (slice != -1) {
        throw("PRIORITY must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> PRIORITYScheduler::get_next_thread() {
    // TODO: implement me!
    std::shared_ptr<SchedulingDecision> decision = std::make_shared<SchedulingDecision>();
    if(ready_queue.empty()) {
        decision->thread = nullptr;
        decision->explanation = "No threads available for scheduling.";
    }
    else{
        decision->thread = ready_queue.top();
        decision->explanation = "[S: " +  + "I:"
        
        switch(decision->thread->priority){
            case SYSTEM:
                
                break;
            case INTERACTIVE:
                
                break;
            case NORMAL:
                
                break;
            case BATCH:
                
                break;
        }

        decision->explanation += "Will run to completion of burst.";
        ready_queue.pop();
    }

    return nullptr;
}

void PRIORITYScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    // TODO: implement me!
}

size_t PRIORITYScheduler::size() const {
    //TODO: Implement me!!
    return 0;
}
