# Standard Make trusted service: normal compiler PATH

Actual VM/container run `x86_kvm_micro_20261107_184208_013488` validates Makefile fix 07bb03f75. The guest launcher deliberately starts Make with ordinary `PATH=/usr/sbin:/usr/bin:/sbin:/bin`, without an LLVM path. The standard `__runtime-vm-micro` recipe supplies `/usr/lib/llvm-18/bin` to its external registered service. The application submits only the original native ELF; the service freshly generates and compiles the proof, and the kernel accepts/binds the native program. No image rebuild, application proof exemption or loader gate change.

| Programs | Generated | Compiled | Verifier accepted/bound | Correct JIT/native samples | Failures |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 1 | 1 | 1 | 2 | 0 |

Both samples return 12345678/action 2. Driver and collector exit zero. Complete terminal service archive, matching kernel-owned P SHA and bound receipt are preserved; no launch source drift. This validates the ordinary compiler bootstrap and one-case native-only binding; the separate full 29-case run still has the two failures recorded in `../../micro-cmp-12g`.

Host CPUs20-23, two vCPUs, 4 GiB, one sample, zero warmups, one repeat. This control starts only after the prior 12 GiB VM closes. Exact VM command, outer PATH and guest invocation are `driver/run.sh` in `runtime-raw.tar.gz`:

```sh
PATH=/usr/sbin:/usr/bin:/sbin:/bin make __runtime-vm-micro PLATFORM=kvm ARCH=x86 \
  HOST_KINSN_DIR_X86=/workspaces/repository/kprog/tv/build-x86/corpus-modules \
  RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-micro-trusted:c-20261107 \
  RUNTIME_IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/micro-compiler-path/normal/runtime.image.tar \
  RUN_TOKEN=c-compiler-standard-20261107 RUNTIMES="kernel native_proof" \
  BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
```

`runtime.json` contains complete raw samples, request identities and image/worker/kernel/module pins. `runtime-service.tar.gz` wraps the original complete service archive (source, object, compiler commands, load stdout/stderr and kernel-owned input). `runtime-raw.tar.gz` holds the original result, runner binary/image inputs, driver, collector and full kernel/meminfo snapshots; `runtime-driver.log.gz` retains standard Make stdout. Closed own guest disk/export image tar have been deleted. Original 29-request missing-clang evidence and same-P host before/after controls remain in the parent directory and T's published audit.
