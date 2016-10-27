#include "args.h"
#include "fastq_reader.h"
#include <iostream>

int main(int argc, const char *argv[]) {
//    struct cmd_args args;
//    args = parse_command_line(argc, argv);

    fastq_reader fqreader();
    struct fastq_pair fqpair = fqreader.read();
    return 0;
}