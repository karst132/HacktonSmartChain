#include "states/ReadyState.h"
#include "RelationMatchContext.h"

ReadyState::ReadyState() 
    : context(nullptr), leds(nullptr) {
}

void ReadyState::set_context(RelationMatchContext* context) {
    this->context = context;
}

void ReadyState::scan_tag() {
    // Implementation of scan_tag method
}