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
        decision->explanation = "[S: " + std::to_string(priority_threads[0]) + " I: " + std::to_string(priority_threads[1]) + " N: " + std::to_string(priority_threads[2]) + " B: " + std::to_string(priority_threads[3]) + "] -> ";
        
        switch(decision->thread->priority){
            case SYSTEM:
                priority_threads[0] --;
                break;
            case INTERACTIVE:
                priority_threads[1] --;
                break;
            case NORMAL:
                priority_threads[2] --;
                break;
            case BATCH:
                priority_threads[3] --;
                break;
        }

        decision->explanation += "[S: " + std::to_string(priority_threads[0]) + " I: " + std::to_string(priority_threads[1]) + " N: " + std::to_string(priority_threads[2]) + " B: " + std::to_string(priority_threads[3]) + "]. Will run to completion of burst.";
        //decision->explanation = "testing";
        ready_queue.pop();
    }

    return decision;
}

void PRIORITYScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    switch(thread->priority){
        case SYSTEM:
            ready_queue.push(0, thread);
            priority_threads[0] ++;
            break;
        case INTERACTIVE:
            ready_queue.push(1, thread);
            priority_threads[1] ++;
            break;
        case NORMAL:
            ready_queue.push(2, thread);
            priority_threads[2] ++;
            break;
        case BATCH:
            ready_queue.push(3, thread);
            priority_threads[3] ++;
            break;
        }
}

size_t PRIORITYScheduler::size() const {
    return ready_queue.size();
}
