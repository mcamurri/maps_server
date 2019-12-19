Header header

# number of dimensions
int8 num_dims

# dimensions
int32[] dimensions

# stride of each dimension in bytes
int32[] stride_bytes

# compression type
int8 compression

# underlying data type
int8 dataype

# size of data
int32 num_bytes

# raw data
int8[] data

# enums for compression type
int8 UNCOMPRESSED = 0
int8 ZLIB = 1

# enums for data type
int8 UINT8 = 0
int8 UINT16 = 1
int8 FLOAT32 = 2

