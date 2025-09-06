#ifndef FORMATTER_H
#define FORMATTER_H
#include <stdint.h>
#include <stdio.h>
#include "ipv4.h"
#include "tcp.h"

void ipv4_print_packet(Ipv4Header* header);
void ipv4_addr_notation(char* ip_str, size_t size, uint32_t ip_addr);
void tcp_print_segment(TcpHeader* header);


#endif // FORMATTER_H
