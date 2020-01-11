Header header

# view id to return
int64 view_id

# point spacing in meters to remove redundant points
# use 0 to include all points
float32 resolution

# angle in radians in [0,2*pi]
# use -1 to accumulate from the most current scan instead
float32 spindle_angle_start

# number of spindle revolutions from requested spindle angle
float32 num_revolutions

# lidar range limits
# use -1 to use default ranges from config 
float32 min_range
float32 max_range

