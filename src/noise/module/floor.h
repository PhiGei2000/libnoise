#ifndef NOISE_MODULE_FLOOR_H
#define NOISE_MODULE_FLOOR_H

#include "modulebase.h"

namespace noise {
    namespace module {
        class NOISE_EXPORT Floor : public Module {
            public:

                Floor();

                virtual int GetSourceModuleCount() const {
                    return 1;
                }

                virtual double GetValue(double x, double y, double z) const;
        };
    }
} // namespace noise

#endif