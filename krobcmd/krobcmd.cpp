#include "krobcmd.hpp"
#include <string>
#include <iostream>

StrIO::StrIO(){
	this->fullContents = "\n";
}
 
void StrIO::write(std::string contents){
	this->clear();
	this->fullContents = this->fullContents + contents;
	this->inOp();
}

std::string StrIO::read(){ return this->outOp(); }

void StrIO::clear(){
	this->fullContents = "\n";
}

std::string MainIO::inOp(){
	std::cout << "\n" << this->fullContents;
	return this->fullContents;
}

std::string MainIO::outOp(){
	std::string inp;
	std::cin >> inp;
	return inp; 
}


int main(){
	while(true){
		std::string command;
		vars::mainio.write("$>");
		command = vars::mainio.read();
		vars::mainio.clear();
	}
}
