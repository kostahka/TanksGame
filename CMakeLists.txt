# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.21)

project ("TanksGame" LANGUAGES CXX)

# Включите подпроекты.
add_subdirectory ("TanksGame")