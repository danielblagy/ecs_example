#include "scene.h"

#include "entity.h"

#include <stdio.h>


Scene::Scene()
{}

Scene::~Scene()
{}

Entity Scene::create_entity(std::string tag)
{
	Entity entity(registry.create(), this);
	entity.add_component<TagComponent>(tag);
	return entity;
}

void Scene::print_system()
{
    // Print System
    for (
        auto [entity, pos, vel, acc] : 
        registry.view<PositionComponent, VelocityComponent, AccelerationComponent>().each()
        )
    {
        printf("pos: %lf  %lf\nvel: %lf  %lf\nacc: % lf % lf\n--------------------\n", pos.x, pos.y, vel.x, vel.y, acc.x, acc.y);
    }
}

void Scene::move_system()
{
    // Move System
    for (
        auto [entity, pos, vel, acc] :
        registry.view<PositionComponent, VelocityComponent, AccelerationComponent>().each()
        )
    {
        acc.y = -9.8;

        vel.x += acc.x;
        vel.y += acc.y;

        pos.x += vel.x;
        pos.y += vel.y;
    }
}

void Scene::update()
{
    print_system();
    move_system();
}