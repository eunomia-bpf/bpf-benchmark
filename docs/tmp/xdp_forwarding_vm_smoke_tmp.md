# XDP Forwarding E2E Results

- Generated at: `2026-03-12T04:21:32.454920+00:00`
- Mode: `xdp_forwarding`
- Status: `ok`
- XDP object: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/xdp-tools/xdp_forward.bpf.o`
- Program: `xdp_fwd_fib_full`
- Attach type: `xdp`
- Topology mode: `preexisting`
- Duration: `5` s

## PPS Comparison

- Baseline receiver PPS: `999875.4635633973`
- Post-ReJIT receiver PPS: `983665.3161872824`
- Improvement: `-1.6212166381545619` %

## Limitations

- This VM run used pre-provisioned virtio loop NIC pairs instead of guest-created veth pairs because the framework kernel is built without veth support (`CONFIG_VETH` is not set in `vendor/linux-framework/.config`).
