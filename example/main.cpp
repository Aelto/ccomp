#include "ccomp.hpp"

#include <iostream>

struct Position : public ccomp::Component {
  float x;
  float y;
};

struct Velocity : public ccomp::Component {
  float x;
  float y;
};

struct Acceleration : public ccomp::Component {
  float x;
  float y;
};

int main() {
  auto * position_storage = new ccomp::ComponentStorage<Position>();

  auto ent = ccomp::new_entity();
  position_storage->addComponent(ent);

  auto ent_1 = ccomp::new_entity();
  position_storage->addComponent(ent_1);

  return 0;
}