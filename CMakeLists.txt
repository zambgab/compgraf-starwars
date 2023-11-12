project(starwars)
add_executable(${PROJECT_NAME} background.cpp yoda.cpp main.cpp window.cpp
                               trackball.cpp)
enable_abcg(${PROJECT_NAME})
