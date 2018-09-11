#ifndef IP_H
#define IP_H

#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/ether.h>

#include "../include/iface.h"

void create_ipv4_header(int fd, packet_t *packet,
                        iface_data_t *iface, param_t *params);

#endif // IP_H
