#ifndef FASTQ_READER_H
#define FASTQ_READER_H

#include <vector>
#include <string>

struct fastq_pair {
	std::vector<std::string> forward;
	std::vector<std::string> reverse;
};

class fastq_reader {
public:
	fastq_reader(std::string forward_fp, std::string reverse_fp);
	std::vector<std::string> read_fastq(const std::string &fp);
	struct fastq_pair read();
private:
	std::string _forward_fp;
	std::string _reverse_fp;
};

#endif // FASTQ_READER_H
