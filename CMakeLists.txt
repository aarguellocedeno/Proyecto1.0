cmake_minimum_required(VERSION 3.26)
project(proyecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proyecto
        aeronave.cpp
        aeronave.h
        persona.cpp
        persona.h
        pro.cpp
        vuelo.h
        vuelo.cpp
        aeropuerto.h
        puerta.h
        puerta.cpp
        torre.h
        torre.cpp
)
