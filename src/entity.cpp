#include "entity.hpp"

ccomp::Entity::Entity(entity_id_t id)
  : id(id) {}

entity_id_t ccomp::generate_id() {
  static entity_id_t counter = 0;

  return counter++;
}

ccomp::Entity ccomp::new_entity() {
  return Entity(ccomp::generate_id());
}