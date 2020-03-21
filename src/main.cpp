/*
 * main.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: bpajk
 */

// Compiled with emscripten 1.39.8
// em++ main.cpp md5.cpp sha1.cpp sha2.cpp -o ../docs/main.js -s "EXPORTED_FUNCTIONS=['_md5_hash_from_string', '_md5_hash_from_buffer', '_sha1_hash_from_string', '_sha1_hash_from_buffer', '_sha224_hash_from_string', '_sha224_hash_from_buffer', '_sha256_hash_from_string', '_sha256_hash_from_buffer', '_sha384_hash_from_string', '_sha384_hash_from_buffer', '_sha512_hash_from_string', '_sha512_hash_from_buffer']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -s ALLOW_MEMORY_GROWTH=1

#include <iostream>
#include "md5.h"
#include "sha1.h"
#include "sha2.h"
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
		//cast the buffer from unsigned char to const char
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

	char* sha1_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = sha1(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha1_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){
		//cast the buffer from unsigned char to const char
		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);
		//get the md5 hash as std::string
		std::string hash = sha1(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha224_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = sha224(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha224_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){
		//cast the buffer from unsigned char to const char
		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);
		//get the md5 hash as std::string
		std::string hash = sha224(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha256_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = sha256(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha256_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){
		//cast the buffer from unsigned char to const char
		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);
		//get the md5 hash as std::string
		std::string hash = sha256(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha384_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = sha384(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha384_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){
		//cast the buffer from unsigned char to const char
		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);
		//get the md5 hash as std::string
		std::string hash = sha384(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha512_hash_from_string(char* inputString){
		//get the md5 hash as std::string
		std::string hash = sha512(inputString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

	char* sha512_hash_from_buffer(unsigned char* buffer, unsigned long bufferSize){
		//cast the buffer from unsigned char to const char
		std::string bufferString(reinterpret_cast<const char*>(buffer), bufferSize);
		//get the md5 hash as std::string
		std::string hash = sha512(bufferString);
		//create a new char variable in he heap
		char * outputHash = new char [hash.length()+1];
		//copy the contents of the hash to the outputString
		std::strcpy (outputHash, hash.c_str());
		//return the hash as char*
		return outputHash;
	}

}

int main() {

	// generate a test string
	std::string generatedString(5, 'A');	// AAAAA
	char* testString = new char[generatedString.size()+1];
	std::strcpy(testString, generatedString.c_str());

	//test char buffer
	unsigned char testBuffer[5] = {65,65,65,65,65};	// AAAAA

	cout << "md5_hash_from_string: " << md5_hash_from_string(testString) << endl;
	cout << "md5_hash_from_buffer: " << md5_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	cout << "sha1_hash_from_string: " << sha1_hash_from_string(testString) << endl;
	cout << "sha1_hash_from_buffer: " << sha1_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	cout << "sha224_hash_from_string: " << sha224_hash_from_string(testString) << endl;
	cout << "sha224_hash_from_buffer: " << sha224_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	cout << "sha256_hash_from_string: " << sha256_hash_from_string(testString) << endl;
	cout << "sha256_hash_from_buffer: " << sha256_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	cout << "sha384_hash_from_string: " << sha384_hash_from_string(testString) << endl;
	cout << "sha384_hash_from_buffer: " << sha384_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	cout << "sha512_hash_from_string: " << sha512_hash_from_string(testString) << endl;
	cout << "sha512_hash_from_buffer: " << sha512_hash_from_buffer(testBuffer, sizeof(testBuffer)) << endl;

	return 0;
}
