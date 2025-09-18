cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProj)

# export config to source code
configure8file(HelloProjConfig.h.in HelloProjConfig.h)

# add the executable target
add_executable(HelloWorld hello.cpp)