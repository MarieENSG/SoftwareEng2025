# add the executable target
add_executable(HelloWorld hello.cpp)
target_link_libraries(HelloWorld PRIVATE basic)
install(TARGETS HelloWorld DESTINATION bin)