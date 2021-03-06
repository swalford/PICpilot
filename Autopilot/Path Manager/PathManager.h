/* 
 * File:   PathManger.h
 * Author: Chris Hajduk
 *
 * Created on February 4, 2014, 9:13 PM
 */

#ifndef PATHMANGER_H
#define	PATHMANGER_H

//Include
#include "main.h"
#include "../Common/Common.h"

//Constants

//In Radians or (90 degrees)
#define MAX_PATH_APPROACH_ANGLE PI/2 

#define PATH_BUFFER_SIZE 50
#define PATH_FREE 0
#define PATH_FULL 1

#define PATH 0
#define ORBIT 1

//Waypoint Management Commands
#define PM_DEBUG_TEST 0
#define PM_NEW_WAYPOINT 1
#define PM_CLEAR_WAYPOINTS 2
#define PM_INSERT_WAYPOINT 3
#define PM_REMOVE_WAYPOINT 4
#define PM_SET_TARGET_WAYPOINT 5
#define PM_SET_RETURN_HOME_COORDINATES 6
#define PM_RETURN_HOME 7
#define PM_CANCEL_RETURN_HOME 8
#define PM_CALIBRATE_ALTIMETER 32
#define PM_SET_PATH_GAIN 64
#define PM_SET_ORBIT_GAIN 65


//Structs and typedefs

//Function Prototypes
//TODO:Add descriptions to all the function prototypes
void pathManagerInit(void);
void pathManagerRuntime(void);

char followWaypoints(PathData* currentWaypoint, float* position, float heading, int* sp_Heading);
int followLineSegment(PathData* currentWaypoint, float* position, float heading);
int followLastLineSegment(PathData* currentWaypoint, float* position, float heading);
float followOrbit(float* center, float radius, char direction, float* position, float heading);
float followStraightPath(float* waypointDirection, float* targetWaypoint, float* position, float heading);
float maintainAltitude(PathData* cPath);
void getCoordinates(long double longitude, long double latitude, float* xyCoordinates);
int calculateHeadingHome(PathData home, float* position, float heading);
PathData* initializePathNode(void);
unsigned int destroyPathNode(PathData* node);
PathData* initializePathNodeAndNext(void);
unsigned int appendPathNode(PathData* node);
unsigned int removePathNode(unsigned int ID);
void clearPathNodes(void);
unsigned int insertPathNode(PathData* node, unsigned int previousID, unsigned int nextID);
void copyGPSData(void);
void checkAMData(void);
char getWaypointChecksum(void);
char generatePMDataDMAChecksum(void);
float getDistance(long double lat1, long double lon1, long double lat2, long double lon2);
float* getWindVelocity(float groundSpeed, float gpsHeading, float airspeed, float magHeading);


#endif	/* PATHMANGER_H */

