#pragma once

#include "entity.hpp"

#include <vector>
#include <atomic>

namespace ccomp {

  typedef unsigned int component_id_t;

  class ComponentCounter {
    public:

    template <typename T>
    static component_id_t getComponentId() {
      static const component_id_t counter = component_type_counter++;

      return counter;
    }

    static std::atomic<component_id_t> component_type_counter;
  };

  struct Component {
    entity_id_t entity_id;

    template <class T>
    static component_id_t getComponentId() {
      return ComponentCounter::getComponentId<T>();
    };
  };

  template<typename T>
  class ComponentStorage {
    public:
    std::vector<T> components;

    ComponentStorage() {};

    void addComponent(ccomp::Entity & entity) {
      if (components.size() <= entity.id + 1) {
        components.resize(entity.id + 1);
      }
    }

    T * getComponent(ccomp::Entity & entity) {
      if (components.size() <= entity.id) {
        return nullptr;
      }

      return &(components[entity.id]);
    }
  };

}