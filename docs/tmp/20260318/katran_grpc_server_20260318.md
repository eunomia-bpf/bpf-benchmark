# Katran gRPC Server Bring-up Notes

Date: `2026-03-18`
Repo: `/home/yunwei37/workspace/bpf-benchmark`
Requested goal: switch Katran E2E from direct `bpftool` map pinning to the official Katran userspace gRPC server path.

## Outcome

I did not switch `e2e/cases/katran/case.py` to the gRPC server path in this pass.

The immediate blocker is not the E2E Python side. It is getting a usable Katran userspace build in this environment within the requested time budget. I stopped after repeated concrete build blockers in the official userspace dependency chain.

## 1. Binary inspection

Requested checks:

```bash
find corpus/repos/katran/ -name 'katran_server*' -o -name 'simple_katran*' -o -name 'katran_grpc*' 2>/dev/null
ls corpus/repos/katran/build/ 2>/dev/null
```

Observed:

- No prebuilt `katran_server_grpc`
- No prebuilt `simple_katran_server`
- No `corpus/repos/katran/build/` directory

## 2. Source layout blocker

`corpus/repos/katran` is a sparse checkout, not a full Katran source tree.

Observed sparse paths:

```text
git -C corpus/repos/katran sparse-checkout list
katran/lib
```

That means the local corpus copy does not contain:

- `example_grpc/`
- `example/`
- full build tree needed for official example servers

To proceed, I cloned a full upstream tree to:

- `/home/yunwei37/workspace/bpf-benchmark/tmp/katran-src`

Pinned to the same commit as the corpus checkout:

- `45926bf4f0dece1fe5d29784718ecdceac8d9f88`

## 3. Build attempts

### Attempt A: official `build_katran.sh`

Command shape:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
./build_katran.sh -p .../tmp/katran-build -i .../tmp/katran-build/deps
```

Result:

- The script is not safe to drive with `BUILD_EXAMPLE_THRIFT=0`
- In the upstream script, this block is buggy:

```bash
if [ -n "$BUILD_EXAMPLE_THRIFT" ]; then
    BUILD_EXAMPLE_THRIFT=1
fi
```

- Passing `BUILD_EXAMPLE_THRIFT=0` still enables the thrift dependency chain
- That would pull in `fbthrift`, `rsocket`, `wangle`, `fizz`, and other heavy deps

I patched only the temporary cloned script under `tmp/katran-src/build_katran.sh` to make the boolean handling sane for diagnostic purposes. I did not change `corpus/repos/katran/build_katran.sh`.

### Attempt B: official deps-only flow with GCC

Command shape:

```bash
INSTALL_DEPS_ONLY=1 BUILD_EXAMPLE_GRPC=0 BUILD_EXAMPLE_THRIFT=0 ./build_katran.sh ...
```

Result:

- `folly` configure failed before build completion
- Failure mode came from the warning-probe path in `folly`

Concrete symptom from `CMakeConfigureLog.yaml`:

```text
cc1plus: error: '-Werror=unknown-warning-option': no option '-Wunknown-warning-option'
```

This came from `folly` try-compile checks that assume clang-style behavior for unknown warning probes. GCC handled those probes badly enough that the configure step became unreliable.

### Attempt C: force system `cmake`

I also forced `/usr/bin/cmake` instead of the venv `cmake`.

This removed one possible toolchain variable, but did not solve the `folly` build failure. The failing surface moved, but `folly` still did not build successfully end-to-end.

### Attempt D: force `clang/clang++`

Command shape:

```bash
CC=/usr/bin/clang CXX=/usr/bin/clang++ \
INSTALL_DEPS_ONLY=1 BUILD_EXAMPLE_GRPC=0 BUILD_EXAMPLE_THRIFT=0 \
./build_katran.sh ...
```

This got substantially farther: `folly` configured and built to about `76%`.

But it then failed with a different concrete issue: generated build flags around `FOLLY_XLOG_STRIP_PREFIXES` broke compilation.

Representative failure:

```text
<command line>:2: note: expanded from macro 'FOLLY_XLOG_STRIP_PREFIXES'
#define FOLLY_XLOG_STRIP_PREFIXES /home/yunwei37/workspace/bpf-benchmark/tmp/katran-build/deps/folly:...
```

And then:

```text
error: use of undeclared identifier 'home'
error: use of undeclared identifier 'workspace'
error: use of undeclared identifier 'bpf'
error: use of undeclared identifier 'benchmark'
```

This means the path-valued macro was effectively reaching the compiler unquoted in at least part of the generated Make-based build. Because the build root lives under `.../bpf-benchmark/...`, the macro expansion becomes invalid C++ tokens.

This is a real build blocker in the current environment, not just a missing package.

## 4. Why I stopped here

At this point the problem had moved from:

- missing binaries
- sparse source tree
- missing packages

to a sequence of upstream/userspace build compatibility issues:

1. official script boolean handling bug for thrift enablement
2. `folly` warning-probe behavior under GCC
3. `folly` build flag / path quoting failure under clang + Unix Makefiles

Continuing past this would require one or more of:

- patching upstream `folly`
- changing the build generator and re-validating the whole dependency stack
- moving the build root to a different path and repeating the full dependency build
- potentially carrying a local Katran userspace build recipe instead of relying on upstream scripts

That is beyond the requested "do not die on this if it turns into a long compile fight" threshold.

## 5. Alternative evaluation

### A. `simple_katran_server`

Status: not recommended as the next fallback.

Reason:

- It still needs the Katran userspace library stack
- It additionally requires `fbthrift`
- In this environment, the official build script bug makes the thrift path actively awkward
- Dependency weight is higher than the gRPC path, not lower

Conclusion:

- `simple_katran_server` is not the easier path here

### B. Minimal `KatranLb` C++ loader

Status: technically plausible, but still blocked by the same core userspace stack.

What it would avoid:

- `gRPC`
- `protobuf`
- generated client code

What it does not avoid:

- `folly`
- `gflags`
- `glog`
- Katran userspace library build itself

Conclusion:

- Better than thrift
- But it does not solve the actual blocker I hit, which is getting Katran userspace plus `folly` built cleanly here

### C. Keep current `bpftool` path and label it clearly

Status: currently the only viable runnable path in this repo without further upstream build work.

Recommended label:

- `standalone_direct_map_emulation`

Important caveat:

- This is not the official Katran userspace standalone mode
- It is a dataplane-only emulation using `bpftool prog loadall`, pinned maps, and direct map population

Conclusion:

- This is the correct short-term fallback if the benchmark must remain runnable immediately

## 6. Recommendation for the next attempt

If this should be retried, the most promising path is:

1. Build outside `/home/yunwei37/workspace/bpf-benchmark`
   - use a hyphen-free path like `/tmp/katranbuild`
2. Keep using full upstream source, not the sparse corpus checkout
3. Force `clang/clang++`
4. Avoid the upstream `BUILD_EXAMPLE_THRIFT` boolean bug
5. Try a Ninja-based build instead of Unix Makefiles for the `folly` stage
6. Only after a working `katran_server_grpc` exists, change `e2e/cases/katran/case.py` to:
   - start `xdproot`
   - start `katran_server_grpc`
   - configure VIP/real through gRPC
   - scan/recompile `balancer_ingress`
   - rerun the existing traffic validation path

## 7. Files touched during investigation

Investigation-only local paths:

- `/home/yunwei37/workspace/bpf-benchmark/tmp/katran-src`
- `/home/yunwei37/workspace/bpf-benchmark/tmp/katran-build`

Report output:

- `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_grpc_server_20260318.md`

## 8. Final status

Current status for the original request:

- Prebuilt Katran server binary: not found
- Official gRPC server build: blocked
- `case.py` migration to official gRPC server: not completed in this pass
- Short-term runnable fallback: keep current direct-map path and label it as non-authoritative standalone direct-map emulation
