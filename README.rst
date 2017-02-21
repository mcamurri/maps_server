***********
Maps Server
***********

The maps server is a request-respond application for collating local LIDAR (or stereo) data into a point cloud and the serving outputs from that point cloud such as heightmaps, depthmaps or octrees. 

Care is take to make the application:

* Minimal: except for the standard libararies mentioned below
* Data-efficient: an support transmission of local maps at 5KB/sec - sufficient for a very very weak wireless link
* Stateless: all content output by the server is self enclosed

The software was developed for the 2015 MIT DARPA Robotics Challenge team.

**Details about message flow**

TODO: put flow chart here

1. DATA_REQUEST: tiny message requesting a high level type of map (a few bits in size). Made by UI e.g. Director. (A)
2. MAP_REQUEST: specific details of map of interest (a few bytes). Made by the data-request-server. (B)
3. MAP_DEPTH: actual height/depth map data stream. Published by maps-server (C)

MAP_OCTREE: as for MAP_DEPTH above except an Octree, messages 10x larger

**(A) enum types supported by data request**

- short range, detailed height map (for footstep planning)
- long range, coarse height map (for navigation planning)
- short range depth map (for manipulation)
- long range depth map (for situational awareness)
- octomap (for manipulation)
- stereo depth map

**(B) information in the maap request**

- which data type to use (depth image, point cloud, octree
- time window to accumulate
- virtual camera to use to project data
- quantization level, resolution
- height estimation mode e.g. median, mean, nearest

**(C) details about the actual maps produced**

The maps is entirely self contained e.g. it doesn't use bot frames or tf, or joint angles. It contains:

- id to identify it
- resolution, compression (e.g. Zlib usually)
- projective transformation matrix for data
- data blob

Example data rate for short range height map: 5KB at 1Hz


**Dependencies**

* Required: PCL, Octomap
* Optional: LCM, libbot

**Pods**

This software is constructed according to the Pods software policies and
templates.  The policies and templates can be found at:

* http://sourceforge.net/projects/pods


