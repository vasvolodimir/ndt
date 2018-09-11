#include "../include/ip.h"

// XXX: Set correct params
void create_ipv4_header(int fd, packet_t *packet,
                        iface_data_t *iface, param_t *params)
{
    struct iphdr *ipv4 = (struct iphdr*) (packet->packet +
                                          sizeof(struct ether_header));

    if (ioctl(fd, SIOCGIFADDR, &iface->handler) < 0)
        perror("SIOCGIFADDR");

    memcpy(&iface->saddr, &iface->handler.ifr_addr, sizeof(struct sockaddr));

    ipv4->version = 4; // IPv4
    ipv4->ihl = 5; // header length: 20 bytes
    ipv4->tos = 0;
    ipv4->tot_len = htons(sizeof(struct iphdr));
    ipv4->id = 0;
    ipv4->frag_off = htons(0x4000);
    ipv4->ttl = 64;
    ipv4->protocol = 0x01; // ICMP
    ipv4->check = htons(0xaddc); // No validation
    ipv4->saddr = ((struct sockaddr_in*) &iface->saddr)->sin_addr.s_addr;
    ipv4->daddr = htonl(params->ip_dest);

    packet->pos += sizeof(struct iphdr);
}
