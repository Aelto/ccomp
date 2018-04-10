@echo off

cl^
 -I example -I src -EHsc^
 example/main.cpp^
 ccomp.lib

echo done