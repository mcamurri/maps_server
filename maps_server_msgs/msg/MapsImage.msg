Header header

# id of map
int64 map_id

# id of view
int64 view_id

# projective transform from reference to image coords
float32[16] transform

# image data
MapsBlob blob

# linear transformation to restore raw data values
float32 data_scale
float32 data_shift

