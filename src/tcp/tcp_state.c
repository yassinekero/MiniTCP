#include <stdint.h>
#include "tcp_state.h"


static State on_closed(void){
  return CLOSED;
}
static State listen_ev_packetrecv(void){
 return CLOSED;  
}
static const Transition state_transitions[] = {
  {CLOSED, EV_PACKET_RECV, &on_closed},
  {LISTEN, EV_PACKET_RECV, &listen_ev_packetrecv},
  //Add more transitions
};
static inline void process_event(Fsm* current_state, Event event){
  for (uint16_t i = 0; sizeof(state_transitions); i++)
  {
    if (current_state->state== state_transitions[i].from_st && event == state_transitions[i].event){
      current_state->state = state_transitions[i].fptr();
      return;
    }
  }
  assert(0);
}

static void fsm_init(Fsm* fsm)
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
