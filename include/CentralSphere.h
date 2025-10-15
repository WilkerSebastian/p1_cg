#pragma once 

#include "Actor.h"
#include "graphics/Application.h" 

class CentralSphere : public Actor {

public:

    float speed = 50.0f;
    cg::Color color = cg::Color::green;

    void start() override {
        position.set({0, 1, 0});    
    }

    void update(float deltaTime) override {
        cg::quatf rotacaoNesteFrame = cg::quatf(speed * deltaTime, {0, 1, 0});
        rotation = rotacaoNesteFrame * rotation;
    }

    void render(cg::GLGraphics3& g3) override {

        g3.setMeshColor(color);
        const cg::TriangleMesh* sphereMesh = g3.sphere();
        
        g3.drawMesh(*sphereMesh,
            position,
            (cg::mat3f)rotation, 
            scale
        );

    }

};