# Cleanup log

- 2026-11-13 VERIFIED preflight correction: terminating the second owned recursive kernel preflight also ran its cleanup trap and removed the canonical `build-x86/vmlinux`; the boot `bzImage` remains unchanged. The exclusive refresh restores the matching stripped ELF/BTF using `scripts/extract-vmlinux` on that exact existing image, with SHA records in the refresh raw directory. This restores the sole artifact; it creates no second kernel build or source copy. Full DWARF is not recovered by this extraction. Source/kernel version remains74d1097af561.

- 2026-11-13 VERIFIED refresh preflight: recursive kernel make commands marked for execution ran despite `make -n`, replacing some same-version module/temp build outputs in `/workspaces/.agent-state/kprog-ck/build-x86`; `bzImage` and `vmlinux` retained their 2026-11-12 timestamps. Second owned preflight process tree was terminated by exact PIDs after inspecting ancestry. No raw data or source tree removed. Full command logs retained under `/workspaces/kprog-raw/verified/20261113-shared-image-dry-run{,2,3}.log`; corrected preflight uses only the sole canonical kernel artifact and skips grouped kernel file targets.

Operator, 2026-11-11: "确保需要的功能 merge 到一起之后, 删掉所有别的内核版本. 任何时候只允许一个镜像和一个底座. 所有原始数据不允许删掉, 不允许建立任何新的 worktree. 明确记录." "kinsn RFC 那个也可以清理掉?" "停掉所有的, 然后确保重新开始"

Every kernel function stays in pushed commits on eunomia-bpf/linux: stock base c23719abc330; 2026-05-29 kernel 8e116c79d (kinsn-only, kop-only); master's 7d6b7d663680 (kprog-no-kinsn); 9c50491de2a5 (kinsn-only); a3cb8790e (archive/linux-framework-checkout-20261111); kinsn RFC trees bpf-next-rfc 9028b2244bcb and kfunc-copy-v2 b2cf461319ad (archive/bpf-next-rfc, archive/kfunc-copy-v2). Removed below: rebuildable outputs (kernel builds, kernel images, module trees, image tars, docker data disks, docker images) and the three extra worktrees. Raw data moved to /workspaces/kprog-raw (MOVED lines). The one base /workspaces/.agent-state/kprog-ck stays and is rebuilt in place from the new kernel series.

```
# cleanup 2026-11-11T08:08:12Z
worktree /workspaces/.agent-state/bpf-benchmark-supervisor/bpf-next-rfc HEAD 9028b2244bcb on origin/archive/bpf-next-rfc 
KEPT untracked of /workspaces/.agent-state/bpf-benchmark-supervisor/bpf-next-rfc -> /workspaces/kprog-raw/kinsn-rfc/bpf-next-rfc-untracked (12724K)
REMOVED 1865904K worktree /workspaces/.agent-state/bpf-benchmark-supervisor/bpf-next-rfc
worktree /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2 HEAD b2cf461319ad on origin/archive/kfunc-copy-v2 
KEPT untracked of /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2 -> /workspaces/kprog-raw/kinsn-rfc/kfunc-copy-v2-untracked (1630456K)
REMOVED 3518528K worktree /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2
Deleted branch kfunc-copy-v2 (was b2cf461319ad).
KEPT untracked of /workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree -> /workspaces/kprog-raw/paper-tree-untracked (211648K)
REMOVED 2200912K worktree /workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree (9f3855f6f)
REMOVED 3348676K /var/tmp/kprog-tmp/C-omp/k529/out2
REMOVED 9350924K /var/tmp/kprog-tmp/C-omp/k529/out3
REMOVED 9281396K /var/tmp/kprog-tmp/C-omp/kbase/out
REMOVED 20720K /workspaces/.agent-state/bpf-benchmark-supervisor/cfg-i386
REMOVED 16172K /workspaces/.agent-state/bpf-benchmark-supervisor/cfg-riscv
REMOVED 53260K /workspaces/.agent-state/bpf-benchmark-supervisor/cfg-s390
REMOVED 32652K /workspaces/.agent-state/bpf-benchmark-supervisor/cfg-x86-jit
REMOVED 67828K /workspaces/.agent-state/bpf-benchmark-supervisor/cfg-x86-nojit
REMOVED 25332K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-allmod-arm64
REMOVED 33024K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-allmod-x86
REMOVED 1886228K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-bisect-arm64
REMOVED 887468K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-bisect-x86
REMOVED 6494728K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-build
REMOVED 4031252K /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-copy-v2-build-arm64
REMOVED 9277820K /workspaces/repository/kprog/tv/build-kernel-x86
REMOVED 8378412K /workspaces/repository/vendor/build/arm64/linux
REMOVED 14884K /var/tmp/kprog-tmp/CL/census-inputs/inputs/bzImage
REMOVED 808852K /var/tmp/kprog-tmp/C-omp/runnow2/var-tmp/runtime.image.tar
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/rtstock/census-inputs/inputs/bzImage
REMOVED 808852K /var/tmp/kprog-tmp/C-omp/runnow/var-tmp/runtime.image.tar
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/art-r/bzImage
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/art-kinsn/bzImage
REMOVED 774436K /var/tmp/kprog-tmp/C-omp/img/runtime.image.tar
REMOVED 806640K /var/tmp/kprog-tmp/C-omp/img/var-tmp/runtime.image.tar
REMOVED 802100K /var/tmp/kprog-tmp/C-omp/runr/var-tmp/runtime.image.tar
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/art-stock/bzImage
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/art/bzImage
REMOVED 808852K /var/tmp/kprog-tmp/C-omp/imgnow/var-tmp/runtime.image.tar
REMOVED 7565092K /var/tmp/kprog-tmp/C-omp/runstock/var-tmp/bpf-benchmark-docker.img
REMOVED 802056K /var/tmp/kprog-tmp/C-omp/runstock/var-tmp/runtime.image.tar
REMOVED 806640K /var/tmp/kprog-tmp/C-omp/run/var-tmp/runtime.image.tar
REMOVED 802100K /var/tmp/kprog-tmp/C-omp/imgr/var-tmp/runtime.image.tar
REMOVED 808888K /var/tmp/kprog-tmp/C-omp/runk/var-tmp/runtime.image.tar
REMOVED 808888K /var/tmp/kprog-tmp/C-omp/imgk/var-tmp/runtime.image.tar
REMOVED 1608140K /var/tmp/kprog-tmp/C-omp/dnstate/runtime.image.tar
REMOVED 15679372K /var/tmp/kprog-tmp/C-omp/dnstate/var-tmp/bpf-benchmark-docker.img
REMOVED 1608820K /var/tmp/kprog-tmp/C-omp/dnstate/var-tmp/runtime.image.tar
REMOVED 808852K /var/tmp/kprog-tmp/C-omp/imgnow2/var-tmp/runtime.image.tar
REMOVED 683640K /var/tmp/kprog-tmp/C-omp/runner-runtime.image.tar
REMOVED 802056K /var/tmp/kprog-tmp/C-omp/imgstock/var-tmp/runtime.image.tar
REMOVED 14884K /var/tmp/kprog-tmp/C-omp/art-now/bzImage
REMOVED 14888K /workspaces/.agent-state/kprog-r-art/art2/bzImage
REMOVED 1248952K /workspaces/.agent-state/kprog-r-art/state-now/var-tmp/runtime.image.tar
REMOVED 1245200K /workspaces/.agent-state/kprog-r-art/state2/var-tmp/runtime.image.tar
REMOVED 1244980K /workspaces/.agent-state/kprog-r-art/state/var-tmp/runtime.image.tar
REMOVED 14888K /workspaces/.agent-state/kprog-r-art/art-now/bzImage
REMOVED 1249384K /workspaces/.agent-state/kprog-r-art/images/kprog-now.image.tar
REMOVED 1607144K /workspaces/.agent-state/kprog-r-art/images/direct-native.image.tar
REMOVED 698256K /workspaces/.agent-state/kprog-r-art/images/x86_64-runner-runtime.image.tar
REMOVED 1244684K /workspaces/.agent-state/kprog-r-art/images/may29-six.image.tar
REMOVED 1605828K /workspaces/.agent-state/kprog-r-art/images/r-restored.image.tar
REMOVED 14884K /workspaces/.agent-state/kprog-r-art/art/bzImage
REMOVED 1607436K /workspaces/.agent-state/kprog-r-art/dn-state/var-tmp/runtime.image.tar
REMOVED 16748132K /workspaces/.agent-state/kprog-r-art/dn-state/var-tmp/bpf-benchmark-docker.img
REMOVED 14884K /root/kt2/bzImage
REMOVED 446916K /workspaces/repository/kprog/arm64/build/design-only/vmlinux
REMOVED 120212K /var/tmp/kprog-tmp/C-omp/art/modules
REMOVED 120208K /var/tmp/kprog-tmp/C-omp/art-kinsn/modules
REMOVED 120208K /var/tmp/kprog-tmp/C-omp/art-now/modules
REMOVED 120212K /var/tmp/kprog-tmp/C-omp/art-r/modules
REMOVED 120212K /var/tmp/kprog-tmp/C-omp/art-stock/modules
REMOVED 1525020K /workspaces/.agent-state/kprog-r-art/art/modules
REMOVED 1528468K /workspaces/.agent-state/kprog-r-art/art-now/modules
REMOVED 1528176K /workspaces/.agent-state/kprog-r-art/art2/modules
REMOVED 1525020K /root/kt2/modules
REMOVED image bpf-benchmark/kprog-dn-stock:c-omp
REMOVED image bpf-benchmark/kprog-dn-kthunk:r
REMOVED image bpf-benchmark/kprog-blob:c-omp
REMOVED image bpf-benchmark/kprog-dn-tracee:r
REMOVED image bpf-benchmark/kprog-dn-otel:r
REMOVED image bpf-benchmark/kprog-now:r
REMOVED image bpf-benchmark/kprog-direct-native:r-restored
REMOVED image bpf-benchmark/kprog-dn-k29:r
REMOVED image bpf-benchmark/kprog-five-step-tracee:r-restored
REMOVED image bpf-benchmark/kprog-stock:c-omp
REMOVED image bpf-benchmark/kprog-may29-cur:r
REMOVED image bpf-benchmark/kprog-r-pair:c-omp
REMOVED image bpf-benchmark/kprog-may29-six:main
REMOVED image bpf-benchmark/kprog-kinsn:c-omp
REMOVED image bpf-benchmark/kprog-now:c-omp
REMOVED image bpf-benchmark/kprog-may29-best:c-omp
REMOVED image bpf-benchmark/runner-runtime:x86_64
Total reclaimed space: 0B
MOVED /var/tmp/kprog-tmp/C-omp -> /workspaces/kprog-raw/var-tmp/C-omp
MOVED /var/tmp/kprog-tmp/CL -> /workspaces/kprog-raw/var-tmp/CL
MOVED /var/tmp/kprog-tmp/R -> /workspaces/kprog-raw/var-tmp/R
MOVED /var/tmp/kprog-tmp/chk -> /workspaces/kprog-raw/var-tmp/chk
MOVED /var/tmp/kprog-tmp/direct-native -> /workspaces/kprog-raw/var-tmp/direct-native
MOVED /var/tmp/kprog-tmp/k29 -> /workspaces/kprog-raw/var-tmp/k29
MOVED /var/tmp/kprog-tmp/k29.tar.gz -> /workspaces/kprog-raw/var-tmp/k29.tar.gz
MOVED /var/tmp/kprog-tmp/kthunk -> /workspaces/kprog-raw/var-tmp/kthunk
MOVED /var/tmp/kprog-tmp/kthunk.tar.gz -> /workspaces/kprog-raw/var-tmp/kthunk.tar.gz
MOVED /var/tmp/kprog-tmp/on-otel -> /workspaces/kprog-raw/var-tmp/on-otel
MOVED /var/tmp/kprog-tmp/on-otel.tar.gz -> /workspaces/kprog-raw/var-tmp/on-otel.tar.gz
MOVED /var/tmp/kprog-tmp/on-tra -> /workspaces/kprog-raw/var-tmp/on-tra
MOVED /var/tmp/kprog-tmp/on-tra.tar.gz -> /workspaces/kprog-raw/var-tmp/on-tra.tar.gz
MOVED /var/tmp/kprog-tmp/otel-dn -> /workspaces/kprog-raw/var-tmp/otel-dn
MOVED /var/tmp/kprog-tmp/otel-dn.tar.gz -> /workspaces/kprog-raw/var-tmp/otel-dn.tar.gz
MOVED /var/tmp/kprog-tmp/otelpay -> /workspaces/kprog-raw/var-tmp/otelpay
MOVED /root/kt2 -> /workspaces/kprog-raw/root-kt2
MOVED /workspaces/.agent-state/kprog-r-art -> /workspaces/kprog-raw/kprog-r-art
REMOVED 14884K /workspaces/.agent-state/kprog-lanes/R/native-only-runtime/package/kernel/bzImage
REMOVED 14884K /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-extent/package-runtime/bzImage
REMOVED 14888K /workspaces/.agent-state/kprog-lanes/C/cilium-update-identity/bzImage
REMOVED 121540K /workspaces/.agent-state/kprog-lanes/C/cilium-update-identity/modules
REMOVED 14888K /workspaces/.agent-state/kprog-lanes/C/native-only-runtime/package/kernel/bzImage
```

```
# verified safety fixture alignment 2026-11-12T08:15:32Z
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_call.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_call.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_call.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_call.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_call.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_call.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_helper_output.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_helper_output.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_helper_output.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_helper_output.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_helper_output.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_helper_output.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memcpy_output.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memcpy_output.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memcpy_output.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memcpy_output.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memcpy_output.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memcpy_output.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memset_output.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memset_output.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memset_output.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memset_output.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/below_sp_memset_output.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/below_sp_memset_output.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_frame_pointer_map.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_frame_pointer_map.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_frame_pointer_map.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_frame_pointer_map.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_frame_pointer_map.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_frame_pointer_map.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_r12.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_r12.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_r12.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_r12.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_r12.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_r12.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_stack_pointer.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_stack_pointer.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_stack_pointer.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_stack_pointer.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/exit_stack_pointer.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/exit_stack_pointer.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/immediate_push_branch_scalar_store.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/immediate_push_branch_scalar_store.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/immediate_push_branch_scalar_store.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/immediate_push_branch_scalar_store.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/immediate_push_branch_scalar_store.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/immediate_push_branch_scalar_store.manifest.json
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/stack_base_flags_scalar_store.S -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/stack_base_flags_scalar_store.S
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/stack_base_flags_scalar_store.native.o -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/stack_base_flags_scalar_store.native.o
MOVED /workspaces/.agent-state/kprog-ck/verified-safety/stack_base_flags_scalar_store.manifest.json -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-only-inputs/stack_base_flags_scalar_store.manifest.json
KEPT full expanded47 generated fixture build -> /workspaces/kprog-raw/verified/20261112-safety-inputs/expanded-47-inputs.tar.gz
```

```
# verified module identity replacement 2026-11-12T08:35:29Z
REMOVED 251B /workspaces/.agent-state/kprog-ck/verified-module/.bpf_kprog_stock.ko.cmd
REMOVED 121B /workspaces/.agent-state/kprog-ck/verified-module/.bpf_kprog_stock.mod.cmd
REMOVED 73535B /workspaces/.agent-state/kprog-ck/verified-module/.bpf_kprog_stock.mod.o.cmd
REMOVED 450B /workspaces/.agent-state/kprog-ck/verified-module/.bpf_kprog_stock.o.cmd
REMOVED 669464B /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.ko
REMOVED 16B /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.mod
REMOVED 2161B /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.mod.c
REMOVED 156448B /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.mod.o
REMOVED 499976B /workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.o
KEPT incremental kprog_stock.o and source; raw run archives and logs retained.
```

- VERIFIED 2026-11-12T12:51:40Z: removed rebuildable stale native target header `/workspaces/repository/vendor/bpf/targets/x86/7.0.0-rc2+/vmlinux.h` (2885599 bytes) under coordinator12:33 instruction; regenerated in place from sole kernel74d1097af561 BTF. Raw build/run data retained.

- VERIFIED 2026-11-12T12:56:26Z: removed rebuildable stopped-guest Docker cache `/var/tmp/kprog-tmp/verified/corpus-state/bpf-benchmark-docker.img` (68719476736 bytes) after full writable-container data and runtime/stdout were archived under `/workspaces/kprog-raw/verified/20261112-image-otel-initial/` and `kprog/results/verified_20261112/image-otel-writable-recovery.tar.gz`; recovery mount unmounted first. Raw request/build/run data retained.
- VERIFIED 2026-11-12T12:56:26Z: scheduled existing image recipe replacement of rebuildable `/workspaces/repository/kinsn/module/x86/build/`; pre-replacement file inventory `/workspaces/kprog-raw/verified/20261112-handoff-rebuild/direct-module-replacement-inputs.json`. The existing recipe also replaces/removes `/workspaces/repository/vendor/repos/tetragon/bpf/objs/` and `deps/` after installing generated BPF objects; raw data retained. Obsolete negative-test binaries remain cached; `-o negative` avoids the recipe's historical source exports into `/tmp/one-image-negative`.
- VERIFIED 2026-11-12T13:00:22Z: removed previous runtime Docker image `sha256:f3b6cf448edaff385909824ef26b15a983916353f5dd5651f702088c6b237798` by exact image ID using `docker image rm --no-prune` while the replacement build runs; parent build caches retained. Full output `/workspaces/kprog-raw/verified/20261112-handoff-rebuild/previous-image-removal.log`. The existing image recipe creates the sole replacement tag `bpf-benchmark/kprog:current`; raw run data retained.

- VERIFIED 2026-11-12T13:14:40.859191+00:00: image Make target completed13:04:50 with rc0; scheduled direct-module output replacement completed. Rebuilt `/workspaces/repository/kinsn/module/x86/build/bpf_x86_native_lab.ko` is 664520 bytes. Existing recipe removed Tetragon `objs/` and `deps/` after base-object installation; full commands retained in `native-handoff-image-build.tar.gz`. Reused frozen negative binaries retained.

- 2026-11-12 verified: completed BCC guest Docker cache at `/var/tmp/kprog-tmp/verified/corpus-state/bpf-benchmark-docker.img` inspected through a read-only noload mount and unmounted. Remaining daemon/container/runtime raw retained in `kprog/results/verified_20261112/handoff-bcc-guest-runtime*` and the persistent BCC raw directory. Existing guest initialization may reuse this rebuildable cache for Katran; future original bytecode captures go to the persistent corpus result mount through the verified wrapper.

- 2026-11-12 verified: completed Katran guest Docker cache `/var/tmp/kprog-tmp/verified/corpus-state/bpf-benchmark-docker.img` inspected through a read-only noload mount and unmounted. Remaining daemon/container/runtime logs retained in `kprog/results/verified_20261112/handoff-katran-guest-runtime*`; complete service/corpus/original bytecode captures stay in97128065a. Existing cache is available for the next guest initialization.

- 2026-11-12 verified: completed Tetragon probe-read replay guest cache inspected through a read-only noload mount and unmounted. Remaining daemon/container/runtime raw retained under `/workspaces/kprog-raw/verified/20261112-tetragon-probe-replay/guest-runtime-recovery*` and `narrow-stack-host.tar.gz`; service/corpus/captures remain in7d4817c81. Existing cache is available for the next replay.

- 2026-11-12 verified: completed typed-stack Tetragon guest cache inspected through read-only noload mount and unmounted; remaining daemon/container/runtime logs retained as `kprog/results/verified_20261112/tetragon-narrow-guest-runtime*` and persistent raw. Full service/corpus/captures stay in01f0c16de. Existing cache is available for the next whole-application replay.

- 2026-11-12 verified: completed Tracee guest cache inspected through a read-only noload mount and unmounted. Remaining daemon/container/runtime logs retained under `/workspaces/kprog-raw/verified/20261112-handoff-tracee/guest-runtime-recovery*` and `tracee-core-reg-build.tar.gz`; full service/corpus/captures remain in f125e00fc. Existing cache is available for the CORE-register replay.
- 2026-11-13T09:27:56Z VERIFIED shared refresh: superseded runtime image sha256:d756bf5919e9eb35cc8628a38af95ca2cec2751e86f4c23f7c6e3f7bd07494a1 already-absent; current sha256:3c30779bd71612cf616821229c4af9ab673d34f0ded3a2ee3591064b8c41ece2; raw retained in /workspaces/kprog-raw/verified/20261113-shared-refresh/run.
- 2026-11-13T09:55:33Z VERIFIED module packaging repair: completed module outputs and replaced incomplete modules-install in the sole build (INSTALL_MOD_STRIP=1); core ELF/boot retained, no source/version change; file inventories and raw logs retained in /workspaces/kprog-raw/verified/20261113-modules-repair-retry2/run.
- 2026-11-13T09:56:29Z VERIFIED shared refresh: superseded runtime image sha256:3c30779bd71612cf616821229c4af9ab673d34f0ded3a2ee3591064b8c41ece2 already-absent; current sha256:7f915aea1f2276fb9509027cb7e4fc2dd6e4182740312e002ebcc14dbc81c923; raw retained in /workspaces/kprog-raw/verified/20261113-modules-repair-retry2/run.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/cilium-same-source-runtime/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/cilium-live-config/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/cpu/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/cilium-probe-config/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/cilium-context-runtime/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:03:08Z PERF: removed superseded runtime image cache hardlink /var/tmp/kprog-tmp/perf/timing/var-tmp/runtime.image.tar from completed own guest state; raw logs/results/compiled evidence retained. Config/inode inventory: kprog/results/perf_20261113/image-cache-retirement.json.
- 2026-11-13T10:20:50Z PERF: retired completed retry1 image cache hardlink /var/tmp/kprog-tmp/perf/cilium-context-runtime-retry1/var-tmp/runtime.image.tar (Config83f01ed24eb0); canonical current image7f915aea remains, complete raw run evidence retained in cilium-context-retry1-runtime.tar.gz.
- 2026-11-13T10:35:59Z VERIFIED shared refresh: superseded runtime image sha256:7f915aea1f2276fb9509027cb7e4fc2dd6e4182740312e002ebcc14dbc81c923 already-absent; current sha256:73985a057359241030b7f1181a64e6253fe81e567813e90e78a19e208d26d9a2; raw retained in /workspaces/kprog-raw/verified/20261113-loader-refresh/run.
- 2026-11-13T22:57:55+00:00 VERIFIED: replaced C-restored sole build-x86/vmlinux cbf23dfe6c1f with ELF f3743c05960f extracted directly from unchanged sole boot2667103e0fbb under exclusive image/base lock; .text/.BTF discrepancy and before/after hashes retained under /workspaces/kprog-raw/verified/20261113-kfunc/restart1. No second kernel file/build/source, raw deletion, or image rebuild.
- 2026-11-13T23:01:27Z PERF: retired incomplete unreferenced Git refetch cache `/workspaces/repository/.git/objects/pack/tmp_pack_4kvOpp` (8820293643 bytes) after stopping only own fetch38892 and children38894/38895/39100; coordinator independently restored published HEAD. All 975 empty loose objects and recovery receipts preserved in `/workspaces/kprog-raw/perf/20261113-git-object-recovery`; no refs/history/source/raw deletion.
- 2026-11-14T00:18:13Z VERIFIED shared refresh: superseded runtime image sha256:73985a057359241030b7f1181a64e6253fe81e567813e90e78a19e208d26d9a2 already-absent; current sha256:0bb7d4be1f0a9c4bb015ee20d14fb9ba26e56da9f84310a501257ae5376e084c; raw retained in /workspaces/kprog-raw/verified/20261114-kfunc-refresh/run.
- 2026-11-14T02:21:22Z PERF: profile job125333 schedules the existing profiler cleanup of its timestamped staging directory under `/var/tmp/kprog-tmp/perf/phase-profile/` after completion (identical current image/module/perf copies and generated guest launcher). Its `out` is now a symlink to persistent `/workspaces/kprog-raw/perf/20261114-otel-profile/run`; the cleanup removes the symlink, never its raw target. All logs, perf data and kallsyms stay on `/workspaces`; exact completion/staging path will be checked next turn. No cleanup outcome is asserted here.
- 2026-11-14T02:29:09Z PERF: profile125333 completed 02:23:41Z and its existing cleanup removed `/var/tmp/kprog-tmp/perf/phase-profile/20261114T021913Z` (checked absent). Persistent `/workspaces/kprog-raw/perf/20261114-otel-profile/run` retains both perf recordings, both kallsyms, command and guest logs. Original Make2 was a later host-report missing-tool error, repaired without a VM rerun. No raw deletion.
- 2026-11-14T02:34:32Z PERF: PMU profile130037 schedules existing profiler cleanup of its generated staging under `/var/tmp/kprog-tmp/perf/phase-profile/` (same sole image/module/perf copies). Persistent raw output `/workspaces/kprog-raw/perf/20261114-otel-pmu-profile/run` remains through its `out` symlink. Exact staging/completion is not polled this turn; collect next turn. No raw deletion.
- 2026-11-14T02:38:50Z PERF: collected PMU130037 Make2 at02:33:47Z before application startup (unsupported cycles:k). Existing cleanup removed timestamped generated staging `/var/tmp/kprog-tmp/perf/phase-profile/20261114T023343Z`, checked absent. Persistent raw run/command/preflight/error evidence retained under `/workspaces/kprog-raw/perf/20261114-otel-pmu-profile`; no raw deletion.
- 2026-11-14T02:44:08Z PERF: host-profile133271 schedules existing phase-profiler cleanup of its timestamped generated staging under `/var/tmp/kprog-tmp/perf/phase-profile/` (same sole image/module/perf copies and launcher). Its `out` symlink points to `/workspaces/kprog-raw/perf/20261114-otel-host-profile/run`; host.data is written there directly. Raw targets remain. Exact completion/staging checked next turn only; no cleanup outcome asserted.
- 2026-11-14T03:15:03Z PERF: host-profile133271 completed guest/app02:47:57Z; perf-kvm then aborted in cleanup02:48:29Z (Make2), with host.data and all clocks/symbols intact. Existing phase-profiler cleanup removed generated staging `/var/tmp/kprog-tmp/perf/phase-profile/20261114T024333Z`, checked absent. Raw `/workspaces/kprog-raw/perf/20261114-otel-host-profile` retained and decoded successfully, no raw deletion.
- 2026-11-14T03:22:33Z PERF: array timing144039 and following hash timing schedule the EXISTING one-image corpus cleanup of generated Docker build disks `/var/tmp/kprog-tmp/perf/known-map-otel-timing/var-tmp/bpf-benchmark-docker.img` and `/var/tmp/kprog-tmp/perf/known-hash-otel-timing/var-tmp/bpf-benchmark-docker.img` after each respective guest exits. They are rebuildable guest image staging, not raw measurements. Persistent run/counter/log directories stay under `/workspaces`; actual cleanup outcomes not yet asserted.
- 2026-11-14T03:35:42Z PERF: completed array timing144039 at03:27:19Z; existing corpus recipe removed generated staging disk `/var/tmp/kprog-tmp/perf/known-map-otel-timing/var-tmp/bpf-benchmark-docker.img`, checked absent. Full raw run030302_441920, counter snapshots and logs stay under/workspaces and are archived; no raw deletion.
- 2026-11-14T03:58:57Z PERF: following link-audit diagnostic schedules EXISTING one-image cleanup of generated staging disk `/var/tmp/kprog-tmp/perf/link-audit-otel/var-tmp/bpf-benchmark-docker.img` after guest exit; raw CLI capture groups stay under persistent mounted `corpus/results/perf-link-audit-20261114/audit`, independent of staging. No cleanup outcome asserted. Earlier unpublished preliminary host archive/receipt preserved as `/workspaces/kprog-raw/perf/20261114-link-audit-host-prior.{tar.gz,json}` before final host publication; no raw loss.
- 2026-11-14T04:12:05Z PERF: hash timing153431 completed03:56:21Z; existing recipe removed generated Docker staging disk `/var/tmp/kprog-tmp/perf/known-hash-otel-timing/var-tmp/bpf-benchmark-docker.img`, checked absent. Persistent raw app033202_840307, snapshots (including stopped-container query128), logs and errors retained/archived; no raw deletion.
- 2026-11-14T04:30:06Z VERIFIED shared refresh: replaced the sole rebuildable vmlinux ELF with the matching ELF extracted from the unchanged sole boot image; no kernel build/version change; before/after hashes in /workspaces/kprog-raw/verified/20261114-shared-integration/refresh.
- 2026-11-14T04:31:33Z VERIFIED shared refresh: superseded runtime image sha256:0bb7d4be1f0a9c4bb015ee20d14fb9ba26e56da9f84310a501257ae5376e084c already-absent; current sha256:66e9e88f197f975fd98f78f08be2eac3b7c313937e39a4cb2a45639d0615f2b8; raw retained in /workspaces/kprog-raw/verified/20261114-shared-integration/refresh.

- 2026-11-14T04:42:49Z PERF: collected audit164729 complete04:01:33Z; existing one-image corpus cleanup removed generated staging disk `/var/tmp/kprog-tmp/perf/link-audit-otel/var-tmp/bpf-benchmark-docker.img`, checked absent. Actual CLI/proof/kernel plans and outputs, replay, counters and full application raw persist under `/workspaces/kprog-raw/perf/20261114-link-audit-otel` and published archive; no raw deletion.

- 2026-11-14T05:05:23Z PERF: launched runtime-array diagnostic188582; EXISTING one-image corpus cleanup schedules generated Docker staging disk `/var/tmp/kprog-tmp/perf/runtime-array-otel/var-tmp/bpf-benchmark-docker.img` removal after guest. Persistent job/counters/results stay under `/workspaces`; cleanup outcome not polled or asserted. Earlier preliminary host archive/receipt moved intact to `/workspaces/kprog-raw/perf/20261114-runtime-array-preliminary.{tar.gz,json}`; final archive also retains earlier build/replay evidence. No raw deletion.

- 2026-11-14T05:14:39Z PERF: collected runtime-array diagnostic188582 complete05:06:44Z Make0; existing one-image corpus recipe removed generated `/var/tmp/kprog-tmp/perf/runtime-array-otel/var-tmp/bpf-benchmark-docker.img`, checked absent. Persistent full run050542_885568, raw counters, analysis/errors/logs retained and archived; no raw deletion.
- 2026-11-14T05:23:44Z VERIFIED: replaced sole generated target vmlinux.h from unchanged boot-matched ELF BTF, rebuilt packet physical-layout in place and restaged same-base compiler tools; raw before/after hashes/layouts /workspaces/kprog-raw/verified/20261114-boot-packet-layout/refresh. No kernel/app/image rebuild or raw deletion.

- 2026-11-14T05:40:57Z PERF: instruction profile204811 schedules existing phase-profile cleanup of generated timestamped staging under `/var/tmp/kprog-tmp/perf/phase-profile/` (same-image tar/perf/module/generated launcher only). `--persist-output` keeps host.data, clocks, guest/profile logs directly in `/workspaces/kprog-raw/perf/20261114-known-hash-instruction-profile/run`; observer captures persist separately. No staging/result outcome checked this launch turn; no raw deletion.

- 2026-11-14 PERF, collected instruction profile 204811: the existing phase-profile cleanup removed generated staging `/var/tmp/kprog-tmp/perf/phase-profile/20261114T053947Z` after guest completion (checked absent at 05:57Z). No additional deletion was issued. Raw `/workspaces/kprog-raw/perf/20261114-known-hash-instruction-profile`, all actual JIT/counter capture and app run remain persistent and archived in `known-hash-instruction-profile-results.tar.gz`; full byte comparison covers 956 files.
