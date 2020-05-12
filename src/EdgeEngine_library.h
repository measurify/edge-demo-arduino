/*
  EdgeEngine_library.h - Library for make Edge Engine devices.
  Created by Francesco Tornatore, February 24, 2020.
  Released into the public domain.
*/
#ifndef EdgeEngine_library_h
#define EdgeEngine_library_h

#include <myDefines.h>

#ifdef ARDUINO
#include "APIRest.h"
#include "connection.h"
#else
#include "APIRest_windows.h"
#include "connection_windows.h"
#endif
#include "average.h"

#include "edgine.h"
#include "filter.h"
#include "mapVal.h"
#include "maxVal.h"
#include "median.h"
#include "minVal.h"
#include "operation.h"
#include "postVal.h"
#include "reception.h"
#include "sample.h"
#include "script.h"
#include "slidingWindow.h"
#include "stdDeviation.h"
#include "window.h"

#endif