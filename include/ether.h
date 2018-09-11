#ifndef ETHER_H
#define ETHER_H

#include <netinet/ether.h> // ether_header
#include "../include/iface.h"

void create_eth_header(packet_t *packet, iface_data_t *iface, param_t *params);

#endif // ETHER_H
