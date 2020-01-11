# high-level type of data requested (see enum)
int8 type

# send period in tenths of seconds (0 for one-shot request)
int8 period

# enum for data request type
int8 MINIMAL_ROBOT_STATE     =  1
int8 AFFORDANCE_LIST         =  2
int8 CAMERA_IMAGE_HEAD_LEFT  = 10
int8 CAMERA_IMAGE_HEAD_RIGHT = 11
int8 CAMERA_IMAGE_LHAND      = 13
int8 CAMERA_IMAGE_RHAND      = 14
int8 CAMERA_IMAGE_LCHEST     = 17
int8 CAMERA_IMAGE_RCHEST     = 18
int8 MAP_CATALOG             = 20
int8 OCTREE_SCENE            = 21
int8 OCTREE_WORKSPACE        = 22
int8 CLOUD_SCENE             = 23
int8 CLOUD_WORKSPACE         = 24
int8 HEIGHT_MAP_SCENE        = 31
int8 HEIGHT_MAP_CORRIDOR     = 32
int8 HEIGHT_MAP_COARSE       = 33
int8 HEIGHT_MAP_DENSE        = 34
int8 HEIGHT_MAP_SCENE_LONG   = 35
int8 DEPTH_MAP_SCENE         = 41
int8 DEPTH_MAP_WORKSPACE     = 42
int8 DEPTH_MAP_WORKSPACE_C   = 43
int8 DEPTH_MAP_WORKSPACE_L   = 44
int8 DEPTH_MAP_WORKSPACE_R   = 45
int8 DENSE_CLOUD_BOX         = 51
int8 DENSE_CLOUD_LHAND       = 52
int8 DENSE_CLOUD_RHAND       = 53
int8 STEREO_MAP_HEAD         = 61
int8 STEREO_MAP_LHAND        = 62
int8 STEREO_MAP_RHAND        = 63
int8 SCANS_HALF_SWEEP        = 71
int8 TERRAIN_COST            = 90
int8 FUSED_DEPTH             = 100
int8 FUSED_HEIGHT            = 101
int8 STEREO_HEIGHT           = 102
