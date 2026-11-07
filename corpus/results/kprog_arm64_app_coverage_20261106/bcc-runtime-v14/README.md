# Actual BCC v14: fixed context access admitted

The previously rejected capable/kprobe__cap_capable_entry now passes the
verifier and is replaced by the prebuilt generation-bound native program
(original90 -> native160). The fresh proof emits direct32bit context loads
at16 and24, preserving the native load widths and values without modifying
the context base pointer. fixed-context-load.json and the raw shim log retain
the exact admission record.

All23 actual BCC proofs regenerate and compile. Manifest32 retains all9 other
startup selectors. Startup replacements improve6 ->7; logged rejections drop
4 ->3. The application still exits when opensnoop fails: vfsstat has an
unbounded exclusive retry loop, tcplife stack-520, opensnoop stack-808. No
native workload runs and sys_exit admission is still not observed.

The raw run and image/pin/QEMU/Spark-build logs are retained, along with all
fresh native/source/simulator inputs, compiled objects, compiler results and
manifests in fresh-artifacts.tar.gz. The private runtimev14 uses the same
matched kernel/library/shim as v12,4GiB QEMU CPUs8-11 and unchanged two-start
BCC command. This is a functional run, with no hardware performance claim.
