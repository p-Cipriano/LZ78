# LZ78
University project where I implemented the LZ78 compression algorithm as well as its decompression.

While not very useful as it can not compress really large files due to overflow in the number of keys, it is an interesting algorithm.

To compile enter "make" in the main directory.

To execute, type .\tp1.out -c <inFileName.txt> [-o <outputFileName>] when compressing and \tp1.out -x <inFileName.z78> [-o <outputFileName>] to decompress. [] indicates the parameters are optional. When not provided the output file has the same name as the input file but with a different extension.
