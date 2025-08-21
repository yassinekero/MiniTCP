#include "ipv4.h"

void get_ipv4_header(ipv4_header* ipv4_header, uint8_t* buffer)
{
  ipv4_header->version = buffer[4] >> 4 ;
  ipv4_header->total_length = buffer[6];
  ipv4_header->id = ((uint16_t)buffer[8] << 8 | (uint16_t) buffer[9]);
  ipv4_header->ttl = buffer[12];
  ipv4_header->protocol = buffer[13];
  ipv4_header->source_ip = ((uint32_t) buffer[16] << 24 
      | (uint32_t)buffer[17] << 16 
      | (uint32_t)buffer[18] << 8 
      | (uint32_t) buffer[19]);
  ipv4_header->dest_ip = ((uint32_t) buffer[20] << 24 
      | (uint32_t)buffer[21] << 16 
      | (uint32_t)buffer[22] << 8 
      | (uint32_t) buffer[23]);

}
