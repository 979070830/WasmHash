# WasmUtil
WasmUtil is a WebAssembly implementation for some general purpose functions. It is written in C++ with some JavaScript glue code. The C++ code was compiled into WebAssembly with Emscripten 1.39.8.

### Functions
 - md5_hash_from_string - generates an MD5 hash from a string
 - md5_hash_from_buffer - generates an MD5 hash from a Uint8array
 
### Performance
 Preformance of the MD5 hashing functions in the WebAssembly implementation was compared to a JavaScript implementation. Test was done in Chrome.
 - For small strings in a range of a few bytes we do not see a significant performance boost. JavaScript implementation can even be faster due to the WebAssembly call overhead.
 - We start seeing s significant difference when the input data exceeds 1 kB. When hashing large amounts of data we can expect a 5x performance boost compared to a JavaScript implementation.
 
# Installation
Clone the repository

git clone https://github.com/bpajk/WasmUtil.git

# Usage
To execute WebAssembly functions in your browser you need a wasm file (compiled WebAssembly) and JavaScript glue code. Both are provided in this project (main.wasm and main.js). You can call the WebAssembly functions by loading the main.js script and using ccall or cwrap methods. Usage of the cwrap method is provided in the index.html example.

### Example
To run the example web page, you have to serve it with a web server. You can install a http-server with npm:

npm install http-server -g

Serve from the project source folder:

cd src

http-server -p 8080

Open the example page in a web browser on the url: http://localhost:8080

### Known limitations
Function md5_hash_from_string can fail if we pass a large string (larger than 1 MB). If you plan to hash large amounts of data, you should use md5_hash_from_buffer function.

## Credits
C++ implementation of the MD5 algoritm (RSA Data Security, Inc. MD5 Message-Digest
Algorithm):

http://www.zedwood.com/article/cpp-md5-function

## License
WasmUtil is licensed under the MIT license.
