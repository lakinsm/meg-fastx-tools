#include "args.h"
#include <iostream>

int main(int argc, const char *argv[]) {
    struct cmd_args args;
    args = parse_command_line(argc, argv);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}