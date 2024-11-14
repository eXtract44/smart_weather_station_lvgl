/*
 * median.h
 *
 *  Created on: 05.11.2013
 *      Author: Jens Riebold, Kößweg 13, 91056 Erlangen
 *
 *  Jens Riebold AT web PUNKT de
 */
 
#ifndef MEDIAN_H_
#define MEDIAN_H_

#include <stdint.h>

typedef struct sMedianNode
{
    int value;                      //sample value
    struct sMedianNode *nextAge;    //pointer to next oldest value
    struct sMedianNode *nextValue;  //pointer to next smallest value
    struct sMedianNode *prevValue;  //pointer to previous smallest value
}sMedianNode_t;

typedef struct
{
    unsigned int numNodes;          //median node buffer length
    sMedianNode_t *medianBuffer;    //median node buffer
    sMedianNode_t *ageHead;         //pointer to oldest value
    sMedianNode_t *valueHead;       //pointer to smallest value
    sMedianNode_t *medianHead;      //pointer to median value
}sMedianFilter_t;

int MEDIANFILTER_Init(sMedianFilter_t *medianFilter);
int MEDIANFILTER_Insert(sMedianFilter_t *medianFilter, int sample);

#endif /* MEDIAN_H_ */
