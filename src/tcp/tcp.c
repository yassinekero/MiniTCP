#include "tcp.h"


int tcp_header_parse(TcpHeader* header, uint8_t* buffer, size_t size)
{
  if(size < 20)
    return -1;
 header->src_port = ((uint16_t)buffer[24] << 8 ) | (uint16_t)buffer[25];
 header->dest_port = ((uint16_t)buffer[26] << 8 ) | (uint16_t)buffer[27];
 header->seq = ((uint32_t)buffer[26] << 24 )
   | ((uint32_t)buffer[27] << 16) 
   | ((uint32_t)buffer[28] << 8)
   | (uint32_t)buffer[29];
 header->ack =  ((uint32_t)buffer[30] << 24 )
   | ((uint32_t)buffer[31] << 16)
   | ((uint32_t)buffer[32] << 8)
   | (uint32_t)buffer[33];
 header->data_offset = buffer[34] >> 4 ;
 header->flags = buffer[35] & 0x3F;
 header->window_size = ((uint16_t)buffer[36] << 8) | (uint16_t)buffer[37];
 header->chucksum = buffer[38];
 return 0;
}
