#include "Arduino.h"
/* 
 * File:   utils.h
 * Author: Barry Solway
 *
 * Created on May 15, 2018, 5:42 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

////////////////////////////////////////////////////////////////////////////////
// Included Files
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Defines, typedefs, etc...
////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    DTYPE_BYTE,
    DTYPE_WORD,
    DTYPE_DWORD,
    DTYPE_ARRAY
} e_queuetype;

typedef struct
{
    uint16_t    head;
    uint16_t    tail;
    e_queuetype q_type;
    uint16_t    q_size;
    uint8_t     element_size;
    void*       array;
} QUEUE;

////////////////////////////////////////////////////////////////////////////////
// Function prototypes
////////////////////////////////////////////////////////////////////////////////
#define qInit(q, size, type)  _qInit(q, size, sizeof(type))
void    _qInit(volatile QUEUE* q, uint16_t q_size, uint8_t elem_size);

void     qClear(volatile QUEUE* q);
bool     qIsEmpty(volatile QUEUE* q);
bool     qGet(volatile QUEUE* q, volatile void* data);
void     qPush(volatile QUEUE* q, volatile void* data);
bool     qPop(volatile QUEUE* q, volatile void* data);
uint16_t qSize(volatile QUEUE* q);


#endif	/* QUEUE_H */
