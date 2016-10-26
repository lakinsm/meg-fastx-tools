#include "fastq_reader.h"
#include <fstream>
#include <iostream>
#include <assert.h>

fastq_reader::fastq_reader(std::string forward_fp, std::string reverse_fp) : _forward_fp(forward_fp), _reverse_fp(reverse_fp) {}

std::vector<std::string> fastq_reader::read_fastq(const std::string &fastq_file) {
        std::ifstream ifs(fastq_file);
	if(!ifs) {
		std::cerr << "Could not open fastq file" << std::endl;
		exit(EXIT_FAILURE);
	}
        std::vector<std::string> reads;
        std::string seq_id, seq, plus, qual;
        while(std::getline(ifs, seq_id)) {
                if(seq_id[0] == '@') {
                        std::getline(ifs, seq);
                        std::getline(ifs, plus);
                        std::getline(ifs, qual);
                }
                reads.push_back(seq);
        }
	assert(reads.size() > 0);
        ifs.close();
        return reads;
}

struct fastq_pair fastq_reader::read() {
	struct fastq_pair fp;
	fp.forward = read_fastq(_forward_fp);
	fp.reverse = read_fastq(_reverse_fp);
	return fp;
}
