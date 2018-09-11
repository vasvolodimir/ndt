#include "../include/ether.h"

void create_eth_header(packet_t *packet, iface_data_t *iface, param_t *params)
{
    struct ether_header *eth = (struct ether_header *) packet->packet;

    /* Write src MAC */
    for(int i=0; i<6; i++)
        eth->ether_shost[i] = ((uint8_t *)iface->handler.ifr_hwaddr.sa_data)[i];

    /*Write dest MAC*/
    memcpy(eth->ether_dhost, params->mac_dest->mac, ETH_ALEN);

    /* Protocol type */
    eth->ether_type = htons(ETH_P_IP);
    packet->pos += sizeof(struct ether_header);
}
