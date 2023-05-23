cmake_minimum_required(VERSION 3.24)
project(VectorialDraw4 C)

set(CMAKE_C_STANDARD 99)

add_executable(VectorialDraw4 main.c point.c point.h line.c line.h circle.c circle.h square.c square.h rectangle.c rectangle.h polygon.c polygon.h point.c manageString.c manageString.h manageCommand.c manageCommand.h Shape.c Shape.h control.c control.h CellOfForms.c CellOfForms.h manageID.c manageID.h area.c area.h Pixel.c Pixel.h)
