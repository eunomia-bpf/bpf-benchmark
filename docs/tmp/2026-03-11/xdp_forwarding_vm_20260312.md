# XDP Forwarding E2E Results

- Generated at: `2026-03-12T04:23:30.545909+00:00`
- Mode: `xdp_forwarding`
- Status: `ok`
- XDP object: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/xdp-tools/xdp_forward.bpf.o`
- Program: `xdp_fwd_fib_full`
- Attach type: `xdp`
- Topology mode: `preexisting`
- Duration: `20` s

## PPS Comparison

- Baseline receiver PPS: `990522.6028984362`
- Post-ReJIT receiver PPS: `993209.552111002`
- Improvement: `0.27126581510642145` %

## Limitations

- This VM run used pre-provisioned virtio loop NIC pairs instead of guest-created veth pairs because the framework kernel is built without veth support (`CONFIG_VETH` is not set in `vendor/linux-framework/.config`).
