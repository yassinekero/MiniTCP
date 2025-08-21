#include "ipv4.h"

int parse_ipv4_header(Ipv4Header* header, uint8_t* buffer, size_t size)
{
  if(size < 20)
    return -1;
  header->version = buffer[4] >> 4 ;
  header->total_length = buffer[6];
  header->id = ((uint16_t)buffer[8] << 8 | (uint16_t) buffer[9]);
  header->ttl = buffer[12];
  header->protocol = buffer[13];
  header->source_ip = ((uint32_t) buffer[16] << 24 
      | (uint32_t)buffer[17] << 16 
      | (uint32_t)buffer[18] << 8 
      | (uint32_t) buffer[19]);
  header->dest_ip = ((uint32_t) buffer[20] << 24 
      | (uint32_t)buffer[21] << 16 
      | (uint32_t)buffer[22] << 8 
      | (uint32_t) buffer[23]);
  return 1;
}

