project(demos)

add_executable(main main.cpp)
#add_executable(sprite sprite.cpp)
#add_executable(map map.cpp)

target_link_libraries(main PUBLIC pixel)
# target_link_libraries(sprite PUBLIC pixel)
# target_link_libraries(map PUBLIC pixel)
