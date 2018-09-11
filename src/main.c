#include <linux/if_packet.h> // sockaddr_ll

#include "../include/tools.h"
#include "../include/iface.h"
#include "../include/ether.h"
#include "../include/ip.h"

int main()
{
    int sockfd;
    iface_data_t iface = { 0 };
    packet_t packet = { 0 };
    param_t params = { 0 };
    struct sockaddr_ll socket_address = { 0 };

    /* Parse param here */
    memcpy(params.if_name, "enp0s31f6", IFNAMSIZ - 1);

    unsigned char *mac_str = "00:11:22:33:44:55";
    unsigned char *ip_str = "172.24.201.33";

    params.mac_dest = atomac(mac_str);
    params.ip_dest = atoip(ip_str);

    /* Open socket */
    if ((sockfd = open_socket(AF_PACKET, SOCK_RAW, IPPROTO_ICMP)) == -1)
        return -1;

    /* Get iface data */
    get_iface_data(sockfd, &iface, &params);
    /* Ethernet header */
    create_eth_header(&packet, &iface, &params);
    /*IPv4 packet*/
    create_ipv4_header(sockfd, &packet, &iface, &params);

    /* Index of the network device */
    socket_address.sll_ifindex = iface.if_idx;
    /* Address length */
    socket_address.sll_halen = ETH_ALEN;
    /* Destination MAC */
    memcpy(socket_address.sll_addr, params.mac_dest->mac, ETH_ALEN);

    /* Send packet */
    if (sendto(sockfd, packet.packet, packet.pos, 0, (struct sockaddr*) &socket_address, sizeof(struct sockaddr_ll)) < 0)
    {
        perror("Sendto ");
        return -1;
    }

    printf("Frame has send!\n");

    return 0;
}
