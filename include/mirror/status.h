#pragma once

#include <string>

namespace mirror {
    class Status {
    public:
        Status();

        enum class Codes {
            OK,
            STALE,
            ERROR,
            RECOVERY
        };
        
        Codes getCode() { return code; };
    
    private:
        Codes code;
    };
}