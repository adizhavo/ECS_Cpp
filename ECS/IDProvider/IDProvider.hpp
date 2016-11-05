#ifndef IDProvider_hpp
#define IDProvider_hpp

#include <typeinfo>

namespace ECS {
    class IdProvider {
        public :
        template <typename T> static const long ID() {
            return typeid(T).hash_code();
        }
    };
}

#endif
