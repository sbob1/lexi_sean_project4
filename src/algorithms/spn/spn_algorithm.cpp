#include "algorithms/spn/spn_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the SPN algorithm.
*/

SPNScheduler::SPNScheduler(int slice) {
    if (slice != -1) {
        throw("SPN must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> SPNScheduler::get_next_thread() {
        std::shared_ptr<SchedulingDecision> decision = std::make_shared<SchedulingDecision>();
        if(ready_queue.empty()) {
            decision->thread = nullptr;
            decision->explanation = "No threads available for scheduling.";
        }
        else {
            decision->thread = ready_queue.top();
            decision->explanation = "Selected from " + std::to_string(ready_queue.size()) + " threads. Will run to completion of burst.";
            ready_queue.pop();
        }
        return decision;
}

void SPNScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    ready_queue.push(thread->get_next_burst(BurstType::CPU)->length, thread);
}

size_t SPNScheduler::size() const {
    return ready_queue.size();
}
