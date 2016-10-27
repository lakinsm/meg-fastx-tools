#include "args.h"
#include "fastq_reader.h"
#include <iostream>

int main(int argc, const char *argv[]) {
//    struct cmd_args args;
//    args = parse_command_line(argc, argv);

    fastq_reader fqreader;
    struct fastq_pair fqpair = fqreader.read();

    for( auto const& x : fqpair.read_pairs) {
//        std::cout << x.first << std::endl;
        std::cout << x.second[0] << std::endl;
        std::cout << x.second[1] << std::endl;
        std::cout << x.second[2] << std::endl;
        std::cout << x.second[3] << std::endl;
        std::cerr << x.second[4] << std::endl;
        std::cerr << x.second[5] << std::endl;
        std::cerr << x.second[6] << std::endl;
        std::cerr << x.second[7] << std::endl;
    }

    return 0;
}