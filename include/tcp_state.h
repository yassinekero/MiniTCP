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
  //Connection Context
  uint32_t seq_num; //Next Sequence number to send
  uint32_t ack_num; // Last Ack received 
  uint16_t  src_port; 
  uint16_t dest_port;
  uint16_t window_size;
  TcpHeader* rx_header; //Last Header Received
  TcpHeader* tx_header; //Header to send
  bool syn_sent;
  bool fin_sent;
  bool fin_received;
  //Add Other Data related to the state 
} Fsm;
typedef void (*TransitionHandler)(Fsm* fsm);
typedef struct
{
  State from_st;
  Event event;
  TransitionHandler transition_handler;
} Transition;

//Functions Definitions
void fsm_run(void);

#endif // TCP_STATE_H
