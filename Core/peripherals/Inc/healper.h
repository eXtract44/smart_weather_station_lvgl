#ifndef INC_HEALPER_H_
#define INC_HEALPER_H_




#define constrain(input, min, max) \
    ({ \
        __typeof__(input) _input = (input); \
        __typeof__(min) _min = (min); \
        __typeof__(max) _max = (max); \
        (_input < _min) ? _min : ((_input > _max) ? _max : _input); \
    })




#endif /* INC_HEALPER_H_ */
