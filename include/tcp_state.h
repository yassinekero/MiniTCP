#ifndef TCP_STATE_H
#define TCP_STATE_H
#include <stdint.h>
#include <assert.h>
#include "tcp.h"
typedef enum 
{
  CLOSED,
  LISTEN,
  SYNRCVD,
  ESTAB,
} State;
typedef enum 
{
  EV_PACKET_RECV,
} Event;


typedef struct 
{
  State state;
  TcpHeader* tcp_header; 
  //Add Other Data related to the state 
} Fsm;
typedef struct
{
  State from_st;
  Event event;
  State (*fptr)(void);
} Transition;

//Functions Definitions
static void fsm_init(Fsm* fsm);
void fsm_run(void);

#endif // TCP_STATE_H
