Header header

# ID of the map
int64 map_id

# ID assigned to requested view
int64 view_id

# Whether the view should be active
bool active

# Whether the time range is absolute or relative
int8 time_mode

# Whether the clip planes are absolute or relative
bool relative_location

# Type of data requested
int8 type

# Resolution or subsampling
float32 resolution

# How frequently to send, in Hz (0 = one time only)
float32 frequency

# Tolerance for quantization
float32 quantization_max

# What topic to publish the response on
string topic

# Time bounds (set to -1 for unbounded)
int64 time_min
int64 time_max

# Clip planes
int8 num_clip_planes
float32[] clip_planes

# Transform applied (reference to view)
float32[16] transform

# Sizes (for image types)
int16 width
int16 height

# Accumulation method (for image types)
int8 accum_type

# enum for request types
int8 NONE = 0
int8 POINT_CLOUD = 1
int8 OCTREE = 2
int8 DEPTH_IMAGE = 3
int8 SCAN_BUNDLE = 4

# enum for time types
int8 ABSOLUTE = 0
int8 RELATIVE = 1
int8 ROLL_ANGLE_ABSOLUTE = 2
int8 ROLL_ANGLE_RELATIVE = 3

# enum for accumulation types
int8 CLOSEST = 0
int8 FURTHEST = 1
int8 MEAN = 2
int8 MEDIAN = 3
int8 CLOSEST_PERCENTILE = 4
int8 ROBUST_BLEND = 5

