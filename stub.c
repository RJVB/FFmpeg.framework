/*
 *  stub.c
 *  FFmpeg
 *
 *  Created by René J.V. Bertin on 20130218.
 *  Copyright 2013 RJVB. All rights reserved.
 *
 *	Bootstrapping stub for pulling in static libraries
 *
 */

#ifdef NEEDS_STUB

#include "libavcodec/avcodec.h"

void ff_framework_loader_stub()
{ static int avc_version = -1;
	if( avc_version < 0 ){
		avc_version = avcodec_version();
	}
}
#endif