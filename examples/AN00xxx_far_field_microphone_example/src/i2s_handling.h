#ifndef _i2s_handling_h_
#define _i2s_handling_h_

#include "i2s.h"
#include "i2c.h"

extern void i2s_main(chanend c_agc_to_i2s, chanend c_i2s_to_far_end,
                     streaming chanend fake_far_end_signal);

#endif
