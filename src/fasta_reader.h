#ifndef FASTA_READER_H_
#define FASTA_READER_H_

#include <map>
#include <string>
#include <utility>
#include <vector>

class fasta_reader {
public:
	fasta_reader(std::string fp);
	std::map<std::string, std::string> read();

private:
	std::string _fp;
};


#endif // FASTA_READER_H_
