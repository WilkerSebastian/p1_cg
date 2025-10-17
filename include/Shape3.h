#pragma once

#include "geometry/Ray.h"

class Shape3 {

public:

    virtual ~Shape3() = default;

    virtual float intersect(const cg::Ray3f& ray) const = 0;

};