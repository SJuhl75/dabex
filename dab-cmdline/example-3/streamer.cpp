#
/*
 *    Copyright (C) 2013 .. 2017
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Computing
 *
 *    This file is part of the DAB library
 *
 *    DAB library is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    DAB library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with DAB library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include	"streamer.h"
#include        <sys/time.h>
#include        <time.h>
#include	<unistd.h>
#include	<stdlib.h>

static inline
int64_t         getMyTime	() {
struct timeval  tv;

        gettimeofday (&tv, NULL);
        return ((int64_t)tv. tv_sec * 1000000 + (int64_t)tv. tv_usec);
}

	streamer::streamer	() {
	theBuffer	= new RingBuffer <int16_t> (16 * 32768);
	running. store (false);
        workerHandle = std::thread (&streamer::run, this);
}

	streamer::~streamer	() {
	stop ();
	delete theBuffer;
}

void	streamer::stop		() {
	if (running. load ()) {
	   running. store (false);
	   workerHandle. join ();
	}
}

bool	streamer::isRunning	() {
	return running. load ();
}

bool    streamer::restart (void) {
        return false;
}
//
//
//	amount is the number of 16 bit value, i.e. 2 values per sample
void	streamer::addBuffer	(void *buffer, int amount, int elsize) {
	(void)elsize;
	if (running. load ())
//	   fprintf (stderr, "putting data into buffer\n");
	   theBuffer	-> putDataIntoBuffer (buffer, amount);
}

int16_t lbuf [2 * 4800];
void	streamer::run		() {
int	period		= 100000;	// usec
int64_t nextStop	= (int64_t)(getMyTime ());

	running. store (true);
	while (running. load ()) {
	   int a = theBuffer -> getDataFromBuffer (lbuf, 2 * 4800);
//	   fprintf (stderr, "got data from buffer a = %d\n", a);
	   if (a < 2 * 4800)
	      memset (&lbuf [a], 0, (4800 * 2 - a) * sizeof (int16_t));
	   nextStop	= nextStop + period;
//	   fprintf (stderr, "writing data out\n");
	   fwrite (lbuf, 2 * 4800, sizeof (int16_t), stdout);
	   if (nextStop - getMyTime () > 0)
	      usleep (nextStop - getMyTime ());
	}
}

