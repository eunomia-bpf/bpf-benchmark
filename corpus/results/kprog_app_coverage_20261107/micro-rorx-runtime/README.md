# SipHash standard native-only runtime after RORX repair

Standard VM/container run `x86_kvm_micro_20261107_185712_174405` passes JIT and generation-bound native execution for the original SipHash program. Both samples return 2666935177028490406/action 2. The application submits only P; the external registered service generates 116 direct RORX calls, compiles the proof with unchanged flags, and the kernel verifies/binds the program. One request, one complete terminal success archive, zero failures, driver/collector exits zero.

This closes the actual standard-path SipHash compiler failure recorded in `../micro-cmp-12g`. The canonical handler/table pins match source repair 2b1ab2c29 (`../rorx-direct-dispatch`). The launch worktree contained that exact source before its subsequent commit; the recorded launch HEAD is not relabeled as the source commit. Existing image/kernel/modules/native P are reused. The kernel-owned original P SHA remains `6b6bcfc6519f3474f4dc2a7e886f3469081e1fa09d019ee4e204d0f84e47d695`. This one-case run is not an all-29 rerun or timing study; Socket LB remains open.

## Command and raw records

Host CPUs20-23, four vCPUs, 8 GiB, one sample, zero warmups, one repeat. The ordinary outer guest PATH has no LLVM prefix; standard Make supplies the external service compiler PATH:

```sh
PATH=/usr/sbin:/usr/bin:/sbin:/bin make __runtime-vm-micro PLATFORM=kvm ARCH=x86 \
  HOST_KINSN_DIR_X86=/workspaces/repository/kprog/tv/build-x86/corpus-modules \
  RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-micro-trusted:c-20261107 \
  RUNTIME_IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/micro-rorx-runtime/runtime.image.tar \
  RUN_TOKEN=c-rorx-standard-20261107 RUNTIMES="kernel native_proof" \
  BENCH=siphash_rotate64_mixer SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
```

`runtime.json` preserves full raw samples, request receipt and source/image/binary pins. `runtime-service.tar.gz` holds the original service archive; `runtime-raw.tar.gz` holds original results, VM/Make commands, collector, full kernel/meminfo snapshots and frozen runner/image inputs. `runtime-driver.log.gz` retains standard Make output.

The initial detached launcher combined `setsid` with Python `start_new_session`, so setsid forked: the first collector observed launcher exit before the guest. The existing actual driver PID was identified by exact `/proc` argv (3310323), and a collector waited on that PID. No guest restart or repeated benchmark. `collection-evidence.tar.gz` retains the initial collector failure and corrected collection, and the launch record distinguishes the launcher PID from the actual driver. All launch source pins stayed unchanged; closed own guest disk/exported image tar were removed.
