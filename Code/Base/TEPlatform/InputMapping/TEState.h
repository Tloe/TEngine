#ifndef TESTATE_H
#define TESTATE_H

#include "TEDataTypes.h"
#include "TEInput.h"

namespace TE::InputMapping {
    struct State {
        std::string name;
        Hash nameHash;
        InputType defaultKey;
        InputType userKey;
    };
}

#endif
