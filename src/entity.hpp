#pragma once

typedef unsigned int entity_id_t;

namespace ccomp {

  class Entity {
    public:
    entity_id_t id;

    Entity(entity_id_t id);
  };

  entity_id_t generate_id();

  Entity new_entity();

}