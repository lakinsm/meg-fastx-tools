#include "fasta_reader.h"

#include <fstream>
#include <assert.h>
#include <iostream>

fasta_reader::fasta_reader(std::string fp) : _fp(fp) {}

std::map<std::string, std::string> fasta_reader::read() {
	std::ifstream ifs(_fp);
	if(!ifs) {
		std::cerr << "Unable to open fasta file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string seq_id, seq;
	std::map<std::string, std::string> fasta_records;
	while(std::getline(ifs, seq_id)) {
		if(seq_id[0] == '>') {
			getline(ifs, seq);
		}
		fasta_records.insert({seq_id.erase(0, 1), seq});
	}
	assert(fasta_records.size() > 0);
	ifs.close();
	return fasta_records;
}
