# add the executable target
add_executable(HelloWorld hello.cpp)
target_link_libraries(HelloWorld PRIVATE basic)
install(TARGETS HelloWorld DESTINATION bin)

# add the executable target
add_executable(Simtown_exe simtown_main.cpp)
target_link_libraries(Simtown_exe PRIVATE simtown)
install(TARGETS Simtown_exe DESTINATION bin)