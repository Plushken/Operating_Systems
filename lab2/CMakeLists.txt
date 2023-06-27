cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(MyProject)

# Устанавливаем стандарт языка С++
set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# Подключаем библиотеку Google Test
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Добавляем исполняемый файл для тестов
add_executable(my_tests test.cpp main.cpp)

# Добавляем библиотеку с функциями
add_library(my_functions function.cpp main.cpp)

# Линкуем библиотеку с функциями к тестовому исполняемому файлу
target_link_libraries(my_tests ${GTEST_LIBRARIES} pthread)

# Добавляем тест в CTest
include(GoogleTest)
gtest_discover_tests(my_tests)