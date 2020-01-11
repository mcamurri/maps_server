Header header

# view to operate on
int64 view_id

# new id to assign (for STORE requests)
int64 new_view_id

# transform reference to view (for UPDATE_TRANSFORM requests)
float32[16] transform

# command to apply to map
int8 command

# command types
int8 STORE            = 1
int8 DELETE           = 2
int8 PUBLISH          = 3
int8 UPDATE_TRANSFORM = 4

