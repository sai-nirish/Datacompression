DATA COMPRESSION AND DECOMPRESSION :

	To compress and decompress the data (which is an array of characters) i have used 
	"easyzlib" which is an shorter version of the C++ library "zlib" .
	zlib uses Deflate algorithm for its functioning which is a data compression/decompression algorithm that uses a combination of the LZ77 algorithm and Huffman coding. 

	I have a made two functions "compresss" and "decompress" which take char array as parameters and returns an integer which characterizes compression/decompression

	In the "compress" function i have added a "_<length of uncompressed char array(upto null character)>" at the end of the decompressed string as length of the uncompressed string will be needed by the "decompress" function

	The "decompress" function reads upto the "_" and checks whether the next char is a
	number between 0-9 if the above is satisfied then it extracts the length of uncompressed char . the probability that there is a digit after an "_" is very less in the decompressed string so we can safely assume that when the above happens it is of the  form  "_<length of uncompressed char array(upto null character)>"  
	Thus this we can extract the length of the uncompressed char and use it in decompress functio