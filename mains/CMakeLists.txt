# add the executable target
add_executable(HelloWorld hello.cpp)

# add binary tree to the list of paths to search includes
target_include_directories(HelloWorld PUBLIC "${PROJECT_BINARY_DIR}")