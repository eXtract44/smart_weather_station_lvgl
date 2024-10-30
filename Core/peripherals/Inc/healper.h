#ifndef INC_HEALPER_H_
#define INC_HEALPER_H_

#include "stdint.h"
#include <stdbool.h>


#define constrain(input, min, max) \
    ({ \
        __typeof__(input) _input = (input); \
        __typeof__(min) _min = (min); \
        __typeof__(max) _max = (max); \
        (_input < _min) ? _min : ((_input > _max) ? _max : _input); \
    })


#define map(in, in_min, in_max, out_min, out_max) \
    (((in) - (in_min)) * ((out_max) - (out_min)) / ((in_max) - (in_min)) + (out_min))

#endif /* INC_HEALPER_H_ */
