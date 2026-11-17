import io, os

os.chdir('/workspaces/repository')
m = 'vendor/bpf/Makefile'
t = io.open(m, encoding='utf-8').read()
anchor = 'CILIUM_MAX_BASE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 \\\n'
assert t.count(anchor) == 1
agent = (
 '# The switches cilium-agent itself turns on for the frozen workload, read from the node_config.h, ep_config.h,\n'
 '# netdev_config.h and filter_config.h it generates (/workspaces/kprog-raw/perf/20261113-cilium-context-runtime-retry2/\n'
 '# baseline-state/state): IPv4 with masquerade and nodeport, every packet traced (ep_config.h #undef\n'
 '# MONITOR_AGGREGATION, so lib/trace.h takes TRACE_AGGREGATE_NONE = 0), policy audit and verdict notifications.\n'
 '# Node addresses vary per run and stay runtime values; only these compile-time switches are taken.\n'
 'CILIUM_AGENT_NODE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 -DENABLE_MASQUERADE_IPV4=1 -DENABLE_NODEPORT=1 \\\n'
 '\t-DSERVICE_NO_BACKEND_RESPONSE=1 -DCT_REPORT_FLAGS=0x0007 -DMONITOR_AGGREGATION=0 \\\n'
 '\t-DPOLICY_AUDIT_MODE=1 -DPOLICY_VERDICT_NOTIFY=1\n'
 'CILIUM_AGENT_LXC_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DENABLE_ROUTING=1\n'
 'CILIUM_AGENT_HOST_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS) -DHOST_ENDPOINT=1\n'
 'CILIUM_AGENT_XDP_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DCIDR4_HMAP_ELEMS=20971520 -DCIDR4_LMAP_ELEMS=65536 \\\n'
 '\t-DCIDR4_FILTER -DCIDR4_LPM_PREFILTER -DCIDR6_FILTER -DCIDR6_LPM_PREFILTER\n'
 '# Objects the frozen workload leaves unloaded (overlay, sock, wireguard) keep these broader options.\n')
t = t.replace(anchor, agent + anchor, 1)
for old, new in [
    ('$(NATIVE_OUT)/cilium/bpf_lxc.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_LXC_OPTIONS)\n',
     '$(NATIVE_OUT)/cilium/bpf_lxc.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS)\n'),
    ('$(NATIVE_OUT)/cilium/bpf_host.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_HOST_OPTIONS)\n',
     '$(NATIVE_OUT)/cilium/bpf_host.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_HOST_OPTIONS)\n'),
    ('$(NATIVE_OUT)/cilium/bpf_xdp.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_XDP_OPTIONS)\n',
     '$(NATIVE_OUT)/cilium/bpf_xdp.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_XDP_OPTIONS)\n'),
]:
    assert t.count(old) == 1, old
    t = t.replace(old, new)
for unused in ('CILIUM_MAX_LXC_OPTIONS := ', 'CILIUM_MAX_HOST_OPTIONS := ', 'CILIUM_MAX_XDP_OPTIONS := '):
    # These variables lose their last user; remove their definitions (with continuation lines).
    i = t.index(unused)
    j = i
    while True:
        k = t.index('\n', j)
        if t[k-1] != '\\':
            break
        j = k + 1
    t = t[:i] + t[k+1:]
assert 'CILIUM_MAX_LXC_OPTIONS' not in t and 'CILIUM_MAX_HOST_OPTIONS' not in t and 'CILIUM_MAX_XDP_OPTIONS' not in t
if 'CILIUM_XDP_BASE_OPTIONS' in t and t.count('CILIUM_XDP_BASE_OPTIONS') == 1:
    i = t.index('CILIUM_XDP_BASE_OPTIONS := '); k = t.index('\n', i); t = t[:i] + t[k+1:]
io.open(m, 'w', encoding='utf-8').write(t)
print('cilium options ok')
