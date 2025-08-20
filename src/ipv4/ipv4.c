#include "ipv4.h"

void get_ipv4_header(ipv4_header* ipv4_header, uint8_t* buffer)
{
  ipv4_header->version = buffer[4] >> 4 ;
  ipv4_header->total_length = buffer[6];
  ipv4_header->id = buffer[7];
  ipv4_header->id = ((uint16_t)buffer[5] << 8 | buffer[6]);
  ipv4_header->protocol = buffer[10];
  ipv4_header->source_ip = ((uint32_t) buffer[13] << 24 | (uint32_t)buffer[14] << 16 | (uint32_t)buffer[15] << 8 | (uint32_t) buffer[16]);
  ipv4_header->dest_ip = ((uint32_t) buffer[17] << 24 | (uint32_t)buffer[18] << 16 | (uint32_t)buffer[19] << 8 | (uint32_t) buffer[20]);

}
