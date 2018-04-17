cmake_minimum_required(VERSION 3.9)
project(PRI_Project_3 C)

set(CMAKE_C_FLAGS  "-Wall -ansi")

add_executable(PRI_Project_3 main.c Katalog.h Samochod.h Katalog.c Samochod.c BazaSamochodow.h)