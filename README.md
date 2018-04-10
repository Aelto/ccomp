# ccomp
C++ component system

## How to use

### Creating a component
```cpp
struct Position : public ccomp::Component {
  float x;
  float y;
};
```

### Creating entities and assigning them components
```cpp
auto * position_storage = new ccomp::ComponentStorage<Position>();
auto entity = ccomp::new_entity();

position_storage->addComponent(entity);
```

### Changing data in the components
```cpp
auto * pos = position_storage->getComponent(ent);

if (pos != nullptr) {
  pos->x += 25.0f;
  pos->y += 25.0f;
}
```

### Reading the unique id of a component type
```cpp
Position::getComponentId<Position>();
```

### Getting pairs of components
> To do!

### Modifying pairs of components
> To do!

## Goal
> What i want the api to be, not always what it actually is

Creating a component
```cpp
declare_component(
  struct Position {
    float x;
    float y;
  }
);
```

### Creating entities made of components
```cpp
auto small_entity = World::new_entity()
  .attach_component(Position);
```

### Altering a component
```cpp
auto * entity_position = get_component(small_entity, Position);
```

### Getting pairs of components
```cpp
std::vector<int> filter = 
auto pairs_position_velocity = get_components<Position, Velocity>(entities);
```

### Modifying pairs
```cpp
for (auto & pair : pairs_position_velocity) {
  pair[0]->x += pair[1]->x;
  pair[0]->y += pair[1]->y;
}
```