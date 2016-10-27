#ifndef FASTQ_READER_H
#define FASTQ_READER_H

#include <unordered_map>
#include <vector>
#include <string>

struct fastq_pair {
	std::unordered_map< std::string, std::vector<std::string> > read_pairs;
};

class fastq_reader {
public:
	std::unordered_map< std::string, std::vector<std::string> > read_fastq_pair();
	struct fastq_pair read();
};

#endif // FASTQ_READER_H
