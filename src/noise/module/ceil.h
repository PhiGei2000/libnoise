#ifndef NOISE_MODULE_CEIL_H
#define NOISE_MODULE_CEIL_H

#include "modulebase.h"

namespace noise {
    namespace module {
        class NOISE_EXPORT Ceil : public Module {
            public:

                Ceil();

                virtual int GetSourceModuleCount() const {
                    return 1;
                }

                virtual double GetValue(double x, double y, double z) const;
        };
    }
} // namespace noise

#endif