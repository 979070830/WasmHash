/*
 * main.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: bpajk
 */

// Compiled with emscripten 1.39.8
// em++ main.cpp md5.cpp -o main.js -s "EXPORTED_FUNCTIONS=['_md5_hash_from_string', '_md5_hash_from_buffer']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -s ALLOW_MEMORY_GROWTH=1


#include <iostream>
#include "md5.h"
using namespace std;

extern "C" {

	// Functions to be exported to WebAssembly are in this block

	char* md5_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = md5(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* md5_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){

		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);

		//get the md5 hash as std::string
		std::string hash = md5(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

}

int main() {

	// test 1 kB string
	std::string s(5, 'A');

	char* C = new char[s.size()+1];
	std::strcpy(C, s.c_str());

	cout << "md5_hash_from_string: " << md5_hash_from_string(C) << endl;


	//test char buffer
	unsigned char buffer[5] = {65,65,65,65,65};

	cout << "md5_hash_from_buffer: " << md5_hash_from_buffer(buffer, sizeof(buffer)) << endl;

	return 0;
}
