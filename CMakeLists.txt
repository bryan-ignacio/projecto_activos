cmake_minimum_required(VERSION 3.30)
project(project_uno)

set(CMAKE_CXX_STANDARD 20)

add_executable(project_uno main.cpp
        Usuario.h
        MatrizDispersa.h
        Node.h
        Activo.h)
