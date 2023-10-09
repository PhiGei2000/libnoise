#include "module/ceil.h"

using namespace noise::module;

Ceil::Ceil()
    : Module(GetSourceModuleCount()) {
}

double Ceil::GetValue(double x, double y, double z) const {
    assert(m_pSourceModule[0] != NULL);

    return ceil(m_pSourceModule[0]->GetValue(x, y, z));
}
