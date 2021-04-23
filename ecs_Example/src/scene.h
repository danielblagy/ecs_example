#pragma once

#include "../vendor/entt.hpp"

#include "components.h"


class Entity;

class Scene
{
private:
	entt::registry registry;

	void print_system();
	void move_system();

public:
	Scene();
	~Scene();

	Entity create_entity(std::string tag);

	void update();

	friend class Entity;
};