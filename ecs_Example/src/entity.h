#pragma once

#include "../vendor/entt.hpp"

#include "scene.h"


class Entity
{
private:
	entt::entity entity_handle = entt::null;
	Scene* scene = NULL;

public:
	Entity(entt::entity s_entity_handle, Scene* s_scene);

	inline entt::entity get_handle() { return entity_handle; }

	template<typename T, typename... Args>
	T& add_component(Args&&... args)
	{
		return scene->registry.emplace<T>(entity_handle, std::forward<Args>(args)...);
	}

	template<typename T>
	T& get_component()
	{
		return scene->registry.get<T>(entity_handle);
	}

	template<typename T>
	void remove_component()
	{
		return scene->registry.remove<T>(entity_handle);
	}

	template<typename T>
	bool has_component()
	{
		return scene->registry.has<T>(entity_handle);
	}
};