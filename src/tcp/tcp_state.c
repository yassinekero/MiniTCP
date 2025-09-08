#include <stdint.h>
#include "tcp_state.h"

static void on_closed(Fsm* fsm){
  fsm->state = CLOSED;
}
static void listen_packetrecv(Fsm* fsm){
  //Check if SYN bit is set
  if(!(fsm->rx_header->flags & SYN_BIT))
  {
    //expected syn packet only
    fsm->state = CLOSED;
  }
  //Establish a connection otherwise
  //Build the TX tcp header
  fsm->tx_header->src_port = fsm->rx_header->dest_port;
  fsm->tx_header->dest_port = fsm->rx_header->src_port;
  //Set syn and ack
  fsm->tx_header->flags |= (ACK_BIT | SYN_BIT);
    
  
}
static const Transition state_transitions[] = {
  {CLOSED, EV_PACKET_RECV, &on_closed},
  {LISTEN, EV_PACKET_RECV, &listen_packetrecv},
  //Add more transitions
};
static inline void process_event(Fsm* fsm, Event event){
  for (uint16_t i = 0; sizeof(state_transitions); i++)
  {
    if (fsm->state== state_transitions[i].from_st && event == state_transitions[i].event){
      state_transitions[i].transition_handler(fsm);
      return;
    }
  }
  assert(0);
}

static inline void fsm_init(Fsm* fsm)
{
  fsm->state = CLOSED;
  //Init the Data
}
void fsm_run(void)
{

  Fsm fsm;
  fsm_init(&fsm);
  while(1){
  // TODO None Event  
  process_event(&fsm, CLOSED);
  }

}
