# Cleanup log

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
