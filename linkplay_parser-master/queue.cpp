/*-------------------------------------------------------------------------------------------------
 *
 *  utils.c
 *
 *  Misc utility functions.
 * 
 ** -----------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------
//	Include Files
//-------------------------------------------------------------------------------------------------
#include "queue.h"

//-------------------------------------------------------------------------------------------------
// Local defines
//-------------------------------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////
// Queue functions
//
void _qInit(volatile QUEUE* q, uint16_t q_size, uint8_t elem_size)
{
    // If q->array is already allocated, then this queue has already been initialized.
    if (q->array != NULL)
        return;
    
    q->head = 0;
    q->tail = 0;
    q->q_size = q_size;
    q->element_size = elem_size;
    q->array = malloc(q_size*elem_size);

    if (elem_size == 1)
        q->q_type = DTYPE_BYTE;
    else if (elem_size == 2)
        q->q_type = DTYPE_WORD;
    else if (elem_size == 4)
        q->q_type = DTYPE_DWORD;
    else
        q->q_type = DTYPE_ARRAY;
}


void qClear(volatile QUEUE* q)
{
    void* data;
    
    // Pop all elements off the queue
    while (qPop(q, data))
        ;
}


bool qIsEmpty(volatile QUEUE* q)
{
    return (q->head == q->tail);
}


bool qGet(volatile QUEUE* q, volatile void* data)
{
    // if q.head == q.tail, then the queue is empty
    // Return false, data is undefined
    if (q->head == q->tail)
        return false;

    // Get value from the head of the queue
    switch (q->q_type)
    {
        case DTYPE_BYTE: 
            {
                uint8_t *pTmp = (uint8_t *) q->array; 
                *((uint8_t *) data) = pTmp[q->head]; 
            }   
            break;

        case DTYPE_WORD:
            {
                uint16_t *pTmp = (uint16_t*) q->array;
                *((uint16_t *) data) = pTmp[q->head];
            }
            break;
            
        case DTYPE_DWORD:
            {
                uint32_t *pTmp = (uint32_t*) q->array;
                *((uint32_t *) data) = pTmp[q->head];
            }
        break;
            
        case DTYPE_ARRAY:
            {
                uint8_t*  pTmp;
                int    i;

                pTmp = (uint8_t *) (q->array + q->head * q->element_size);
                for (i = 0; i < q->element_size; i++)
                    *((uint8_t *) (data + i)) = pTmp[i];
            }
            break;
            
        default:
            break;
    }
    
    return true;
}

bool qPop(volatile QUEUE* q, volatile void* data)
{
    // Get the data from the head of the queue. This will return false if the buffer is empty. 
    if (qGet(q, data) == false)
        return false;
    
    // Remove the head of the queue
    q->head++;
    if (q->head >= q->q_size)        
        q->head = 0;

    return true;
}

void qPush(volatile QUEUE* q, volatile void* data)
{
    // Handle cases were the data size for the queue is 1, 2 or 4 bytes
    switch (q->q_type)
    {
        case (DTYPE_BYTE):
            {
                uint8_t*pTmp = (uint8_t*) q->array;
                pTmp[q->tail] = *((uint8_t*) data);
            }
            break;

        case (DTYPE_WORD):
            {
                uint16_t *pTmp = (uint16_t *) q->array;
                pTmp[q->tail] = *((uint16_t *) data);
            }
            break;
            
        case (DTYPE_DWORD):
            {
                uint32_t *pTmp = (uint32_t *) q->array;
                pTmp[q->tail] = *((uint32_t *) data);
            }
            break;
            
        case (DTYPE_ARRAY):
            {
                uint8_t* pTmp;
                int   i;

                pTmp = (uint8_t*) (q->array + q->tail * q->element_size);
                for (i = 0; i < q->element_size; i++)
                    pTmp[i] = *((uint8_t*) (data + i));
            }
            break;
            
        default:
            break;
    }
        
    q->tail++;
    if (q->tail >= q->q_size)
        q->tail = 0;
    
    // Normally, if q.tail == q.head, then the queue is empty. But if this happens right after incrementing
    // the tail, it means the queue is now full. If the queue is full, we drop the oldest element.
    if (q->tail == q->head)
    {
        q->head++;
        if (q->head >= q->q_size)        
            q->head = 0;
    }
}

uint16_t qSize(volatile QUEUE* q)
{
    uint16_t size;
    
    if (q->head == q->tail)
        size = 0;
    else if (q->tail > q->head)
        size = q->tail - q->head;
    else if (q->tail < q->head)
        size = q->q_size - q->head + q->tail;
    
    return size;
}

