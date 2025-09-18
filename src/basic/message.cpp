# include <iostream>
# include <HelloProjConfig.h>
# include <basic/message.h>

void hello_world(){
	std::cout << "Hello World" << std::endl;
}

void print_version(){
	std::cout << "Project version is " << HelloProj_VERSION_MAJOR
	<< "." << HelloProj_VERSION_MINOR << std::endl;
}