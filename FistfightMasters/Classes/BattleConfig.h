#pragma once

#include "RPGHead.h"

#define MAP_GRID_WIDTH					90

#define MAP_GRID_HEIGHT					90

#define MAP_GRID_X_COUNT				10

#define MAP_GRID_Y_COUNT				5


#define ZORDER_MAP_BG					800

#define ZORDER_MAP_GRID					900

#define ZORDER_BATTLE_ROLE				1000

#define ZORDER_BATTLE_EFFECT			2000

#define ZORDER_MESSAGE					99999


#define CHECK_GRID_BOUNDS(_GRID_X_, _GRID_Y_) (_GRID_X_<0 || _GRID_X_>=MAP_GRID_X_COUNT || _GRID_Y_<0 || _GRID_Y_>=MAP_GRID_Y_COUNT)

#define GRID_CONVER_TO_PIXEL(_GRID_X_, _GRID_Y_) (Point(_GRID_X_*MAP_GRID_WIDTH+MAP_GRID_WIDTH/2+30, _GRID_Y_*MAP_GRID_HEIGHT+MAP_GRID_HEIGHT/2+15))
