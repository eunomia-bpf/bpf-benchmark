# ARM instruction matrix after production XDP context repair

The published b2b6f28d9 production header changes memory-read routing. Rebuild
the existing771-form harness incrementally, then run the existing canonical
replay with its unchanged frozen reference. This is an emulated instruction
regression; it does not validate the entry ABI or substitute a real ARM CPU
run. Original pre-repair evidence remains in arm64-current-logical.

Commands from the repository root:

```sh
taskset -c 16-19 make -C kprog/fidelity build ARCH=arm64
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical/Makefile reference OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/differential/arm64-production-context
```

The detached job builds incrementally and then performs canonical replay;
completed emulation results are recorded below. Hardware execution is pending.
No production source, shared reference cache, kernel, module, loader or guest
input is modified. The separate34-case full-system safety replay stays active.

The incremental static build and emulated CPU/C phase completed:
**771 forms x1,024 =789,504 states, zero architectural or memory mismatches**.
The complete trace has the expected record count/size. `qemu-forms.tsv` retains
every form and count; `qemu-summary.json` pins binary and archive hashes.
`compiled-inputs.tar.gz` preserves the exact compiler inputs; every archived
file was independently rehashed against `compiled-inputs.json`.

The refreshed static AArch64 binary SHA256 is
`ed8b3e7b65b7f2bf29602e204440c85f742b8559bc69732301ddc7ca6b10273f`.
The existing default hardware handoff now selects its compressed copy here.
On the coordinator's actual ARM host, from the repository root, run:

```sh
sh kprog/fidelity/run-arm64.sh
```

Hardware execution remains pending. The canonical phase is still running
against the unchanged c110b03a reference; no canonical pass is asserted yet.
The concurrent production full-system34-case safety replay remains separate.
V has independently found a dynamic-dispatch host compilation regression from
the new unmapped-XDP-read diagnostic; A owns its forward repair. This harness
uses constant decoded forms and does not establish that dynamic host path.
