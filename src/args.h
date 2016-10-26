#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

struct cmd_args {
    std::string pipeline;
    std::string fa_fp;
    std::string fq_f_fp;
    std::string fq_r_fp;
    std::string annot;
};

static void usage() {
    std::cout << "\nUsage:\n\tmeg-fastxtk [Options] <FASTX> [<MATE>]\n\n" << std::endl;
    std::cout << "Options:\n\n";
	exit(EXIT_FAILURE);
}

static inline cmd_args
parse_command_line(int argc, const char *argv[]) {
	struct cmd_args args;
	std::vector<std::string> arg_list(argv, argv+argc);
    	if(arg_list[1] == "build") {
        	if(argc < 4) {
				usage();
			}
        	args.pipeline = "build";
        	args.fa_fp = arg_list[2];
        	args.annot = arg_list[3];
//            for(int i = 4; i < argc; i++) {
//				if(arg_list[i] == "-gpu")           args.gpu = true;
//				else                                usage();
//            }
    	}
    	else if(arg_list[1] == "test") {
        	if(argc < 8) {
			usage();
		}
        	args.pipeline = "test";
        	for(int i = 2; i < argc; i++) {
            		if(arg_list[i] == "-db")        args.fa_fp = arg_list[++i];
            		else if(arg_list[i] == "-1")    args.fq_f_fp = arg_list[++i];
            		else if(arg_list[i] == "-2")    args.fq_r_fp = arg_list[++i];
            		else                            usage();
        	}
    	}
    	else {
        	usage();
	}

	return args;
}

#endif // ARGS_H
