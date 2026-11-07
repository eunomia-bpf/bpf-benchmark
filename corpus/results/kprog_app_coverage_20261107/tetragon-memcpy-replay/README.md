# Tetragon whole application with inline memcpy binding

The registered common service freshly generates, compiles and binds4/4
requests in actual batch x86_kvm_corpus_20261107_221545_272137. This includes
event_wake_up_new_task, whose prior native-stub load reached the memcpy target
materialization boundary. The patched T697bea module closes that failure.
All4terminal native hashes match their kernel copy and all4bound program IDs
match the application shim replacement records. Launch sources retain their
captured identities.

| Baseline load attempts | Resident BPF records | Generated | Compiled | Bound | Verifier rejections | Next startup stage |
| ---: | ---: | ---: | ---: | ---: | ---: | --- |
|311|287|4|4|4|0|execve_send manifest selector|

The baseline attempt count includes startup probes; the resident snapshot
has its own denominator. All counters and original load rows remain in the
raw app/result archive. Native startup next reaches execve_send before its
service request. The manifest selector counts its10368-byte entry body; libbpf
also links the928-byte cwd_read_v61 callback, giving the actual11296-byte
source program seen in the shim. This is an entry-selection failure before
generation; the4received requests all bind successfully. The next generic
manifest scanner repair collects reachable direct calls and function-address
callbacks, preserving the original native and workload inputs.

The existing common Make corpus recipe runs one sample/two-second workload,
12GiB/eight guest vCPUs on20-23. The private image adds the patched module and
warm-cache readonly-label linker to the canonical application image; service
and container use the same inputs. Kernel df7a9293 and native input identities
remain explicit in coverage.json and launch.tar.gz. The original canonical
image/module/release executable used by R retain their recorded bytes.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/tetragon-memcpy-replay/run.sh
```

coverage.json retains the full service/app/workload counters and terminal
outcomes. service.tar.gz preserves native inputs, fresh generated artifacts,
load diagnostics and kernel log. result.tar.gz retains the complete upstream
result and shim logs; launch.tar.gz retains source/binary/recipe inputs.
The driver exits0 and the collector records app startup error after preserving
all observations. Closed guest disk/export and the private image are retired.
Universal simulator/token/link/binding laws supply the safety argument.
