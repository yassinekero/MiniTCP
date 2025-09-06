#include "ipv4.h"

int ipv4_header_parse(Ipv4Header* header, uint8_t* buffer, size_t size)
{
  if(size < 20)
    return -1;
  header->version = buffer[4] >> 4 ;
  header->header_length = buffer[4] & 0x0F;
  header->tos = buffer[5];
  header->total_length = ((uint16_t)buffer[6] << 8 | (uint16_t)buffer[7]);
  header->id = ((uint16_t)buffer[8] << 8 | (uint16_t) buffer[9]);
  header->flags = buffer[10] >> 5;
  header->flags = ((uint16_t)(buffer[10] & 0x1F)<< 8 | (uint16_t)buffer[11]);
  header->ttl = buffer[12];
  header->protocol = buffer[13];
  header->header_checksum = ((uint16_t)buffer[14] << 8 | (uint16_t)buffer[15]);
  header->source_ip = ((uint32_t) buffer[16] << 24 
      | (uint32_t)buffer[17] << 16 
      | (uint32_t)buffer[18] << 8 
      | (uint32_t) buffer[19]);
  header->dest_ip = ((uint32_t) buffer[20] << 24 
      | (uint32_t)buffer[21] << 16 
      | (uint32_t)buffer[22] << 8 
      | (uint32_t) buffer[23]);
  return 0;
}


