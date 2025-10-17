#pragma once

#include "Shape3.h"

class SphereShape : public Shape3 {

public:

    float intersect(const cg::Ray3f& ray) const override {

        auto L = -ray.origin;
        auto a = ray.direction.dot(ray.direction);
        auto b = 2 * ray.direction.dot(L);
        auto c = L.dot(L) - 1.0f;

        float delta = (b * b) - (4 * a * c);

        if (delta < 0)
            return -1.0f;

        float t0 = (-b - sqrt(delta)) / (2 * a);
        
        if (t0 > 0.001f)
            return t0;
        
        float t1 = (-b + sqrt(delta)) / (2 * a);
        if (t1 > 0.001f)
            return t1;

        return -1.0f;

    }

};