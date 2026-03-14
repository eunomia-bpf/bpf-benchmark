# XDP Forwarding Live VM Report

- Date: `2026-03-12`
- Kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- Entry point: `python3 e2e/run.py xdp_forwarding --vm --kernel vendor/linux-framework/arch/x86/boot/bzImage --duration 20`
- Result JSON: `e2e/results/xdp_forwarding_vm_20260312.json`

## Summary

- The authoritative framework-kernel VM run completed successfully.
- Stock receiver PPS: `990522.6028984362`
- Recompile receiver PPS: `993209.552111002`
- Speedup ratio (`recompile / stock`): `1.0027126581510641x`
- Receiver PPS delta: `+0.27126581510642145%`
- Stock receiver throughput: `232255280.7586717` bps
- Recompile receiver throughput: `248476634.6790829` bps
- Receiver throughput ratio (`recompile / stock`): `1.069842777599818x`

## Scanner And Recompile

- Live scanner census: `3` total sites
- Family breakdown: `cmov=1`, `endian=2`, `wide=0`, `rotate=0`, `lea=0`, `extract=0`, `zeroext=0`, `branch_flip=0`
- Recompile status: `applied=true`
- Recompile accepted sites: `2`
- Applied families: `endian=2`
- Skipped policy rule: `1` stale `cmov` site
- Recompile warning: policy program name was `xdp_fwd_fib_full`, while the live kernel name was truncated to `xdp_fwd_fib_ful`

## Environment Notes

- The original in-guest `veth` topology could not run on this framework kernel because `vendor/linux-framework/.config` contains `# CONFIG_VETH is not set`.
- The initial live attempt failed with `ip link add ... type veth` -> `Error: Unknown device type.`
- To keep the experiment inside the framework-kernel VM, `e2e/run.py xdp_forwarding --vm` was adapted to launch the guest with two `vng --network loop` pairs and run the case in `preexisting` topology mode:
  - `eth0` router-left
  - `eth1` source namespace peer
  - `eth2` router-right
  - `eth3` sink namespace peer
- This preserves isolated in-VM forwarding, but the authoritative measurement is on virtio loop NIC pairs, not guest-created `veth` pairs.

## Measurement Notes

- Attach mode was `xdp` (not `xdpgeneric`).
- The workload used `iperf3` UDP with `64`-byte packets, `4` parallel streams, and `20` seconds per phase.
- The datapath was saturated in both phases:
  - Stock receiver loss: `54.2036099020455%`
  - Recompile receiver loss: `51.13760977468474%`
- BPF runtime counters moved slightly in the expected direction:
  - Stock avg ns/run: `84.79231144541593`
  - Recompile avg ns/run: `83.7007449841734`
  - JIT image bytes: `694 -> 688`
