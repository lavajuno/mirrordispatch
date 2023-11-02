#include <mirror/module.h>

namespace mirror {
    DispatchModule::DispatchModule(std::string& name, std::string& address) {
        this->name = name;
        this->address = address;
        this->status = Status();
    }

    DispatchModule::DispatchModule() {
        this->name = "";
        this->address = "";
        this->status = Status();
    }
}