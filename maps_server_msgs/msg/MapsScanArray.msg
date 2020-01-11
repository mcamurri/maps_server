Header header

# id of map
int64 map_id

# id of view
int64 view_id

# number of scans
int32 num_scans

# approximate payload size
int32 data_bytes

# transform from reference to cloud coords
float32[16] transform

# scan data
MapsScan[] scans

# sequence info
int32 chunk_id
int32 num_chunks

