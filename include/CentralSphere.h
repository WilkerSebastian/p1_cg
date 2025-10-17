#pragma once 

#include "Actor.h"
#include "graphics/Application.h" 
#include "SphereShape.h"

class CentralSphere : public Actor {

public:

    cg::Color color = cg::Color::green;

    void start() override {

        shape = std::make_unique<SphereShape>();

        position.set(-7.5f, 0, 3);

        material.diffuse = cg::Color::red;
        material.specular = cg::Color::white;
        material.shine = 32.0f;
        
        updateTransform();
        
    }

    void render(cg::GLGraphics3& g3) override {

        g3.setMeshColor(color);
        const cg::TriangleMesh* sphereMesh = g3.sphere();
        
        cg::mat3f normal = cg::normalMatrix((cg::mat3f)rotation, scale);

        g3.drawMesh(*sphereMesh,
            transform,
            normal
        );

    }

    Intersection intersect(cg::Ray3f& ray) override {
        
        if (!shape)
            return {}; 

        auto hit = shape->intersect(ray, transform);

        if (hit.distance > 0) {
            hit.actor = this; 
            return hit;       
        }

        return {};

    }

};