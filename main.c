#include <arpa/inet.h>
#include <errno.h>>
#include <linux/if.h>
#include <netinet/if_ether.h>
#include <netinet/ip_icmp.h>
#include <poll.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <unistd.h>

#include "arp.h"
#include "cmd.h"
#include "ether.h"
#include "icmp.h"
#include "ip.h"
#include "param.h"
#include "sock.h"

int EndFlag = 0;

int DeviceSoc;

PARAM param;

void *MyEthThread(void *arg) {
  int           nready;
  struct pollfd targets[1];
  u_int8_t      buf[2048];
  int           len;
  target[0].fd = DeviceSoc;
  targets[0].event = POLLIN | POLLERR;

  while (EndFlag == 0) {
    switch ((nready = poll(targets, 1, 1000))) {
      case -1:
        if (error != EINTR) {
          perror("poll");
        }
        break;
      case 0:
        break;
      default:
        if (targets[0].revents & (POLLIN | POLLERR) {
              if ((len = read(DeviceSoc, buf, sizeof(buf))) <= 0) {
                perror("read");
              } else {
                EtherRecv(DeviceSoc, buf, len);
              }
            })
    }
  }
  return (NULL);
}
