# WasmHash
WasmHash is a WebAssembly implementation of some general hashing functions. It is written in C++ with some JavaScript glue code. The C++ code was compiled into WebAssembly with Emscripten 1.39.8.

### Functions
 - md5_hash_from_string - generates an MD5 hash from a string
 - md5_hash_from_buffer - generates an MD5 hash from a Uint8array
 - sha1_hash_from_string - generates a SHA1 hash from a string
 - sha1_hash_from_buffer - generates a SHA1 hash from a Uint8array
 - sha224_hash_from_string - generates an SHA224 hash from a string
 - sha224_hash_from_buffer - generates an SHA224 hash from a Uint8array
 - sha256_hash_from_string - generates an SHA256 hash from a string
 - sha256_hash_from_buffer - generates an SHA256 hash from a Uint8array
 - sha384_hash_from_string - generates an SHA384 hash from a string
 - sha384_hash_from_buffer - generates an SHA384 hash from a Uint8array
 - sha512_hash_from_string - generates an SHA512 hash from a string
 - sha512_hash_from_buffer - generates an SHA512 hash from a Uint8array
 
### Performance
 Preformance was measured for the MD5 hashing function in a WebAssembly implementation in comparison to a JavaScript implementation. The WebAssembly build was optimised with -O3 attribute. Test was done in Chrome.
 - For small strings in a range of a few bytes we do not see a significant performance boost. This is due to WebAssembly call overhead.
 - We can expect up to 20x performance boost compared to a JavaScript implementation when the input data is in the Megabyte range.
 
# Installation
Clone the repository

git clone https://github.com/bpajk/WasmHash.git

# Usage
To execute WebAssembly functions in your browser you need a wasm file (compiled WebAssembly) and JavaScript glue code. Both are provided in this project (main.wasm and main.js). You can call the WebAssembly functions by loading the main.js script and using ccall or cwrap methods. Usage of the cwrap method is provided in the index.html example.

### Example
A live example page can be found at:

https://bpajk.github.io/WasmHash

To run the example web page localy, you have to serve it with a web server. You can install a http-server with npm:

npm install http-server -g

Serve from the project source folder:

cd docs

http-server -p 8080

Open the example page in a web browser on the url: http://localhost:8080

### Known limitations
Hashing functions with input parameter string can fail if we pass a large string (larger than 1 MB). If you plan to hash large amounts of data, you should use functions with input parameter buffer.

## Credits
C++ implementation of the MD5 algorithm (RSA Data Security, Inc. MD5 Message-Digest Algorithm):

http://www.zedwood.com/article/cpp-md5-function

C++ implementation of the SHA1 algorithm:

http://www.zedwood.com/article/cpp-sha1-function

C++ implementation of the SHA2 algorithm:

http://www.zedwood.com/article/cpp-sha1-function

## License
WasmUtil is licensed under the MIT license.
