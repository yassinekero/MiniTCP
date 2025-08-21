#ifndef IPV4_H
#define IPV4_H
#include <stdint.h>
typedef struct
{
  uint32_t source_ip;
  uint32_t dest_ip;
  uint16_t version : 4;
  uint16_t header_length: 4;
  uint16_t tos : 8;
  uint16_t total_length;
  uint16_t id;
  uint16_t flags : 3;
  uint16_t frag_offset: 13;
  uint16_t header_checksum;
  uint8_t ttl;
  uint8_t protocol;
} ipv4_header;


void get_ipv4_header(ipv4_header* ipv4_header, uint8_t* buffer);


#endif // IPV4_H
