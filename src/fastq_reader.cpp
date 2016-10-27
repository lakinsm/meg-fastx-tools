#include "fastq_reader.h"
#include <fstream>
#include <iostream>
#include <assert.h>

std::unordered_map< std::string, std::vector<std::string> > fastq_reader::read_fastq_pair() {
    std::unordered_map< std::string,  std::vector<std::string> > read_map;
    std::string seq_id, seq, plus, qual;
    std::string short_id;
    while(std::getline(std::cin, seq_id)) {
        std::cout << seq_id << std::endl;
        if(seq_id[0] == '@') {
                std::getline(std::cin, seq);
                std::getline(std::cin, plus);
                std::getline(std::cin, qual);
        }
        short_id = seq_id.substr(0, seq_id.find(' '));
        read_map[short_id].push_back(seq_id);
        read_map[short_id].push_back(seq);
    }
	assert(read_map.size() > 0);
    return read_map;
}

struct fastq_pair fastq_reader::read() {
	struct fastq_pair fp;
	fp.read_pairs = read_fastq_pair();
	return fp;
}
