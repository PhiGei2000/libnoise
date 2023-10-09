#include "module/floor.h"

using namespace noise::module;

Floor::Floor()
    : Module(GetSourceModuleCount()) {
}

double Floor::GetValue(double x, double y, double z) const {
    assert(m_pSourceModule[0] != NULL);

    return floor(m_pSourceModule[0]->GetValue(x, y, z));
}