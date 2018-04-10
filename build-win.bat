@echo off

cls

cl^
 -c -I src^
 src/ccomp.cpp^
 src/component.cpp^
 src/entity.cpp

lib *.obj
del *.obj

echo done