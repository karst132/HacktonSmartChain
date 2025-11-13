#include "states/SetupState.h"
#include "RelationMatchContext.h"

SetupState::SetupState() 
    : context(nullptr), leds(nullptr) {
}

void SetupState::set_context(RelationMatchContext* context) {
    this->context = context;
}

void SetupState::scan_tag() {
    // Implementation of scan_tag method
}