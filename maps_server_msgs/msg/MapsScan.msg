Header header

# scan information
int16 num_ranges
float32 theta_min
float32 theta_step

# scan-to-reference transforms
float32[3] translation_start
float32[4] quaternion_start
float32[3] translation_end
float32[4] quaternion_end

# scan data blob
float32 range_scale
MapsBlob range_blob

# intensity blob
float32 intensity_scale
MapsBlob intensity_blob

