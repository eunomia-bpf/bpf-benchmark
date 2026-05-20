/*
 * shim_netlink.h — header-only helpers for intercepting and replaying
 * AF_NETLINK / NETLINK_ROUTE RTM_SETLINK + IFLA_XDP attach messages.
 *
 * Motivation: katran (and any libbpf user pre-v0.8) attaches XDP programs by
 * sending RTM_SETLINK with an IFLA_XDP nested attribute over an rtnetlink
 * socket. The shim's other reattach paths (BPF_LINK_UPDATE, BPF_LINK_CREATE,
 * PERF_EVENT_IOC_SET_BPF) never see this attach, so an in-process ReJIT
 * reload would produce a new prog that no netdev actually dispatches to —
 * the original prog stays bound to the netdev and the workload measures
 * unchanged bytecode. This header gives the main shim two primitives:
 *
 *   1. nl_parse_setlink_xdp_attach() — inspect an outgoing rtnetlink
 *      message body to detect RTM_SETLINK+IFLA_XDP+IFLA_XDP_FD; return
 *      (ifindex, prog_fd, xdp_flags) so the shim can record the attach
 *      against the prog_entry tracked by `prog_fd`.
 *
 *   2. nl_send_setlink_xdp_replace() — synthesize and send a fresh
 *      RTM_SETLINK that swaps the bound prog on `ifindex` to a new
 *      `new_prog_fd`, preserving the original xdp_flags so the SKB/DRV/HW
 *      attach mode stays consistent. Used at reload_and_reattach time.
 *
 * Both helpers are self-contained and depend only on the Linux UAPI
 * headers; they do not touch the shim's global tables or mutexes.
 */
#ifndef SHIM_NETLINK_H
#define SHIM_NETLINK_H

#include <linux/if_link.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

/* Per-prog record of an in-flight XDP netlink attach. Stored as an array on
 * prog_entry; populated on outgoing sendmsg/sendto observation. */
struct xdp_nl_attach {
    uint32_t ifindex;    /* netdev ifindex bound by IFLA_XDP_FD */
    uint32_t xdp_flags;  /* IFLA_XDP_FLAGS (XDP_FLAGS_SKB_MODE/DRV_MODE/...) */
};

/* Parse `buf` (length `len`) as an rtnetlink message stream and locate a
 * RTM_SETLINK / RTM_NEWLINK that carries IFLA_XDP -> IFLA_XDP_FD. Stops at
 * the first matching message and returns 1, filling *ifindex_out,
 * *prog_fd_out, *flags_out. Returns 0 if no match (caller treats as plain
 * non-XDP netlink traffic). */
static int nl_parse_setlink_xdp_attach(const void *buf, size_t len,
                                       uint32_t *ifindex_out,
                                       int *prog_fd_out,
                                       uint32_t *flags_out) {
    if (!buf || len < sizeof(struct nlmsghdr)) return 0;
    const char *p = (const char *)buf;
    size_t remaining = len;
    while (remaining >= sizeof(struct nlmsghdr)) {
        const struct nlmsghdr *nh = (const struct nlmsghdr *)p;
        if (nh->nlmsg_len < sizeof(*nh) || nh->nlmsg_len > remaining) return 0;
        if (nh->nlmsg_type != RTM_SETLINK &&
            nh->nlmsg_type != RTM_NEWLINK) {
            /* advance to next message */
            size_t aligned = NLMSG_ALIGN(nh->nlmsg_len);
            if (aligned > remaining) return 0;
            p += aligned;
            remaining -= aligned;
            continue;
        }
        if (nh->nlmsg_len < NLMSG_LENGTH(sizeof(struct ifinfomsg))) return 0;
        const struct ifinfomsg *ifi =
            (const struct ifinfomsg *)NLMSG_DATA(nh);
        size_t attr_len = nh->nlmsg_len - NLMSG_LENGTH(sizeof(*ifi));
        const struct rtattr *rta = (const struct rtattr *)IFLA_RTA(ifi);
        while (RTA_OK(rta, attr_len)) {
            if (rta->rta_type == IFLA_XDP) {
                size_t nest_len = RTA_PAYLOAD(rta);
                const struct rtattr *xa =
                    (const struct rtattr *)RTA_DATA(rta);
                int found_fd = 0, found_flags = 0;
                int prog_fd_val = -1;
                uint32_t flags_val = 0;
                while (RTA_OK(xa, nest_len)) {
                    if (xa->rta_type == IFLA_XDP_FD &&
                        RTA_PAYLOAD(xa) == sizeof(int)) {
                        memcpy(&prog_fd_val, RTA_DATA(xa), sizeof(int));
                        found_fd = 1;
                    } else if (xa->rta_type == IFLA_XDP_FLAGS &&
                               RTA_PAYLOAD(xa) == sizeof(uint32_t)) {
                        memcpy(&flags_val, RTA_DATA(xa), sizeof(uint32_t));
                        found_flags = 1;
                    }
                    xa = RTA_NEXT(xa, nest_len);
                }
                if (found_fd && prog_fd_val >= 0) {
                    *ifindex_out = (uint32_t)ifi->ifi_index;
                    *prog_fd_out = prog_fd_val;
                    *flags_out = found_flags ? flags_val : 0;
                    return 1;
                }
                return 0;
            }
            rta = RTA_NEXT(rta, attr_len);
        }
        size_t aligned = NLMSG_ALIGN(nh->nlmsg_len);
        if (aligned > remaining) return 0;
        p += aligned;
        remaining -= aligned;
    }
    return 0;
}

/* Open a transient AF_NETLINK socket and send a RTM_SETLINK that replaces
 * the IFLA_XDP attach on `ifindex` with `new_prog_fd`. Preserves the
 * caller-supplied `xdp_flags` (mode bits). Returns 0 on success, -1 on any
 * error.
 *
 * The message layout is:
 *   nlmsghdr (RTM_SETLINK | NLM_F_REQUEST | NLM_F_ACK)
 *   ifinfomsg { ifi_family=AF_UNSPEC, ifi_index=<ifindex> }
 *   IFLA_XDP {
 *       IFLA_XDP_FD     = new_prog_fd
 *       IFLA_XDP_FLAGS  = xdp_flags
 *   }
 *
 * Reads + ignores the ack so the response doesn't sit in the kernel queue.
 */
static int nl_send_setlink_xdp_replace(uint32_t ifindex, int new_prog_fd,
                                       uint32_t xdp_flags) {
    int sock = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, NETLINK_ROUTE);
    if (sock < 0) return -1;

    struct {
        struct nlmsghdr nh;
        struct ifinfomsg ifi;
        char attrs[64];
    } req;
    memset(&req, 0, sizeof(req));

    req.nh.nlmsg_type = RTM_SETLINK;
    req.nh.nlmsg_flags = NLM_F_REQUEST | NLM_F_ACK;
    req.nh.nlmsg_seq = 1;
    req.ifi.ifi_family = AF_UNSPEC;
    req.ifi.ifi_index = (int)ifindex;

    /* Build the IFLA_XDP nested attribute in-place. */
    struct rtattr *xdp = (struct rtattr *)req.attrs;
    char *inner = (char *)RTA_DATA(xdp);
    struct rtattr *xfd = (struct rtattr *)inner;
    xfd->rta_type = IFLA_XDP_FD;
    xfd->rta_len = RTA_LENGTH(sizeof(int));
    memcpy(RTA_DATA(xfd), &new_prog_fd, sizeof(int));
    struct rtattr *xfl =
        (struct rtattr *)(inner + RTA_ALIGN(xfd->rta_len));
    xfl->rta_type = IFLA_XDP_FLAGS;
    xfl->rta_len = RTA_LENGTH(sizeof(uint32_t));
    memcpy(RTA_DATA(xfl), &xdp_flags, sizeof(uint32_t));

    uint16_t inner_total = (uint16_t)(RTA_ALIGN(xfd->rta_len) +
                                       RTA_ALIGN(xfl->rta_len));
    xdp->rta_type = IFLA_XDP;
    xdp->rta_len = (unsigned short)(RTA_LENGTH(0) + inner_total);

    req.nh.nlmsg_len = NLMSG_LENGTH(sizeof(req.ifi)) +
                       (uint32_t)NLMSG_ALIGN(xdp->rta_len);

    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;

    ssize_t sent = sendto(sock, &req, req.nh.nlmsg_len, 0,
                          (struct sockaddr *)&sa, sizeof(sa));
    if (sent < 0) { close(sock); return -1; }

    /* Drain the ack so the kernel doesn't keep state queued; ignore parse
     * errors — we'll surface attach failures via subsequent reload checks. */
    char resp[1024];
    (void)!recv(sock, resp, sizeof(resp), MSG_DONTWAIT);
    close(sock);
    return 0;
}

#endif /* SHIM_NETLINK_H */
