# ccomp
C++ component system

# Goal

Creating a component
```cpp
declare_component(
  struct Position {
    float x;
    float y;
  }
);
```

Creating entities made of components
```cpp
auto small_entity = World::new_entity()
  .attach_component(Position);
```

Altering a component
```cpp
auto * entity_position = get_component(small_entity, Position);
```

Getting pairs of components
```cpp
std::vector<int> filter = 
auto pairs_position_velocity = get_components<Position, Velocity>(entities);
```

Modifying pairs
```cpp
for (auto & pair : pairs_position_velocity) {
  pair[0]->x += pair[1]->x;
  pair[0]->y += pair[1]->y;
}
```