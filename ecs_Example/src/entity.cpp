#include "entity.h"


Entity::Entity(entt::entity s_entity_handle, Scene* s_scene)
	: entity_handle(s_entity_handle), scene(s_scene)
{}