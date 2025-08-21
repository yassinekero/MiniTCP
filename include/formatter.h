#ifndef FORMATTER_H
#define FORMATTER_H
#include <stdint.h>
#include <stdio.h>
#include "ipv4.h"


void print_ipv4_packet(Ipv4Header* header);
void ipv4_addr_notation(char* ip_str, size_t size, uint32_t ip_addr);


#endif // FORMATTER_H
