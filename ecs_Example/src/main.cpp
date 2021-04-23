#include "scene.h"
#include "entity.h"

void create_object(Scene& scene,
    double init_pos_x, double init_pos_y,
    double init_vel_x, double init_vel_y
    )
{
    Entity object_entity = scene.create_entity("object");
    object_entity.add_component<PositionComponent>(init_pos_x, init_pos_y);
    object_entity.add_component<VelocityComponent>(init_vel_x, init_vel_y);
    object_entity.add_component<AccelerationComponent>(0.0, 0.0);

    PositionComponent& pos = object_entity.get_component<PositionComponent>();
}

int main()
{
    Scene scene;
    
    create_object(scene, 0.0, 500.0, 0.0, 0.0);
    create_object(scene, 0.0, 250.0, 0.0, 50.0);

    while (getchar())
    {
        scene.update();
    }
    
    return 0;
}