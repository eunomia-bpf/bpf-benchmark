# Cilium: same-source native build, and the divergences the audit listed

Lane C took Cilium's same-source build over from lane PERF on 2026-11-14T10:02:41Z
(COORDINATION, split by code). This file records the build, the source
divergences the audit classified (D01, D02, D08, D09, D10) and what each now
looks like, with the byte evidence for every claim.

## The build

```sh
cd vendor/bpf
export KERNEL_RELEASE=$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
make VMLINUX_BTF=/workspaces/.agent-state/kprog-ck/build-x86/vmlinux cilium        # the eBPF arm
make VMLINUX_BTF=/workspaces/.agent-state/kprog-ck/build-x86/vmlinux native-cilium # the native arm
```

`native-cilium` compiles `vendor/bpf/cilium/bpf/*.c` with `-include native_compat.h
-DMICRO_NATIVE` (vendor/bpf/Makefile:290). Seven objects: `bpf_lxc`, `bpf_overlay`,
`bpf_sock`, `bpf_host`, `bpf_wireguard`, `bpf_xdp`, `bpf_alignchecker`; the manifest
covers 85 entries. Both arms build rc=0 after the changes below.

`VMLINUX_BTF` must name the sole kernel's BTF (`build-x86/vmlinux`). The default
is the host's, which silently swaps the tracked headers.

## The divergences

| | what the audit found | state |
|---|---|---|
| D01 | native dereferences public `bpf_sock_addr`/`bpf_sock` layouts; the real entry contexts are `bpf_sock_addr_kern`/`sock` | **already correct in the image's own build**: `bpf_sock.native.o` produced by `native-cilium` is byte-identical to the image's, section by section, so this is not a remaining divergence in the recipe. `kprog/build`'s `upstream-socket-native` target performs the lowering in IR (55 accesses) as the alternative route. |
| D02 | native `cb[0]` at skb+40, eBPF at skb+48 | in the native `__sk_buff` model (`include/linux/bpf.h`, `-DMICRO_NATIVE` block) plus `packet-context-check`, which passes: "TC qdisc metadata/classid/wire_len, full-width packet pointers, XDP nested interfaces PASS" |
| D08 | `ingress_ifindex` read as a public word at +12, inside the real `data_end` pointer | **fixed**, commit `67802556c` |
| D09 | hybrid-routing subnet lookups removed, `same_subnet_id` left false | **the guard is correct**; the removal fails to load. Commit `85c7f9af2` restores it with the reason. |
| D10 | `wire_len` returns `skb.len`; tc_classid clear skipped | in the native model and `packet-context-check`, as D02 |

### D09, and why the guard has to stay

`bpf_lxc.c` puts both hybrid-routing blocks behind `#ifndef MICRO_NATIVE`, which
leaves `same_subnet_id` false and changes `skip_tunnel` — so it looked like a
behavioural divergence, and removing the guards looked like the fix. It is not.

Removing them makes `bpf_lxc.native.o` name `cilium_subnet_map`, and the program
stops loading. In run `x86_kvm_corpus_20261114_154232_483911` all 38 loads of
`tail_handle_ipv4_cont` failed with

```
Error: GOT-relative reloc against unknown symbol cilium_subnet_map; add it to
link-plan helpers or maps
```

while the rest of the object linked normally.

The cause is Cilium's loader, not the recipe. `CONFIG()` must go through the
macro "to ensure the loader's dead code elimination can recognize" it
(`lib/static_data.h:60-62`), and the loader does exactly that at load time: the
object's `tail_handle_ipv4_cont` is 28 072 B / 3509 insns, the loaded program is
2022 insns with hybrid routing off, and **no `cilium_subnet_map` is created at
all** — that run creates 182 maps, none of them this one. A config branch and the
maps it references leave the loaded program together, so a native object that
names the map statically has nothing to bind to.

This also explains the image's own object: it declares
`__config_hybrid_routing_enabled` and never reads it, because under this
deployment's config the branch is gone. The native object matches the program it
is loaded for.

Doing better is a linker capability — drop a config branch together with its map
references from the native object when the captured value folds the branch away —
which is lane PERF's code (`kprog/x86/native_lab/native_link`), not this recipe.

State after `85c7f9af2`: `bpf_lxc.native.o` back to 0 subnet references and
`tc/tail` back to 73 580 B, identical to the image; both arms rc=0.

### D08, and the chain

`xdp_md.ingress_ifindex` is not a field of the entry context. The kernel lowers
a read of it to `xdp_buff.rxq->dev->ifindex` (`net/core/filter.c`), so the native
C has to walk the same chain or it reads the high half of the `data_end`
pointer — for `bpf_xdp` that is every device comparison and redirect decision.

`micro_native_xdp_ingress_ifindex()` (`include/bpf/ctx/xdp.h`) walks `+32`
(`xdp_buff.rxq`) → `+0` (`xdp_rxq_info.dev`) → `+224` (`net_device.ifindex`),
guarding each hop; `ctx_get_ifindex`, `ctx_get_ingress_ifindex`, `ctx_redirect`'s
own comparison and `l2_responder`'s two map-key reads go through it. Native
`bpf_xdp.native.o` drops from 42 to 34 reads of `ctx+12` and gains 12 loads of
`+0xe0` behind the guard; `xdp/tail` grows 250 B (23 017 -> 23 267).

Both accessors had to move above `ctx_redirect`, which now calls them.

### Equivalence of the eBPF arm

The lookup substitutions touch code both arms compile, so the eBPF arm was
checked byte for byte: `bpf_xdp.o` and `bpf_lxc.o` built from the pristine
source and from the changed source have **identical `.text`** (`llvm-objcopy
--only-section=.text`, `cmp`). The eBPF arm is unchanged; only the native arm
gains the lowered accesses.

That check needs the right section: Cilium's objects put code in named sections
(`tc/tail`, `tc/entry`, `xdp/tail`, `cgroup/connect4`, ...), and `.text` holds a
27-43 byte stub. Comparing `.text` alone therefore "passes" for any Cilium pair;
section-by-section comparison is the one that means something here.

## What is still open

D01's route (b) — lowering public context accesses per program/attach type
before native optimization — is implemented in `kprog/build`'s
`upstream-socket-native`, which lowers 55 socket accesses in IR. The `vendor/bpf`
recipe does not use it, and does not need to for `bpf_sock`: its object already
matches the image's. Whether the same holds for the `cilium/agent` attach types
Cilium's own loader uses on cgroup hooks is not established here.

No timing for Cilium is claimed from this file. The next step is a both-arm run
(`cilium/agent`) with the D08 objects, comparing judgements and relay logs
between arms before any per-invocation number is quoted.