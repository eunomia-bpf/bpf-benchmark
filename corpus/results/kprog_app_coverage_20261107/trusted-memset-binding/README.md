# Trusted x86 memset relocation binding

The x86 kernel recognizes the exact exported kernel memset target when the
same immutable native submission is sealed to the currently authorized trusted
service worker. Its proof body models the full native64bit byte count as stores,
so no corresponding BPF helper call is expected. Other native targets and memcpy
keep the existing relocation checks. Applications still submit native bytes
only; public proof upload cannot acquire this capsule provenance.

The current adapter's SCHED_CLS/CGROUP_SKB shadow is not a faithful external
write representation. This recognition does not authorize those two ABI paths;
loads remain explicit failures until their context projection is repaired.
No application program is skipped and no runtime guard is inserted.

| Existing unchanged control | Outcome |
|---|---|
| Valid stack fill | kernel and generation-bound native execution pass, retval2 |
| Context fill | verifier rejected; load only |
| Stack overflow fill | verifier rejected; load only |

All three original native ELF hashes match the kernel service receipts. The
negative producer commands have no TEST_RUN arguments; no unsafe code executed.
The complete logs/requests are in the archive referenced by summary.json.
The original11:55 accepted finding remains untouched in ../trusted-service-bcc-set/intrinsic-controls/.

```
make -C kprog/tv module-check ARCH=x86 KDIR=/workspaces/repository/kprog/tv/build-kernel-x86
make -f corpus/results/kprog_app_coverage_20261107/trusted-memset-binding/Makefile kvm
```

The module was rebuilt incrementally with the existing TV kernel; no kernel,
image, simulator header or ARM artifact was rebuilt. `source-pins.json` hashes
all compiled inputs; `compiled-source.tar.gz` and module.ko.gz retain their exact
bytes. The compiled shared group header includes two preexisting blank lines
outside this change; the commit excludes those lines. The initial Makefile-path
setup failure is retained separately and is not a program rejection.

This closes the isolated intrinsic-binding control. Complete BCC application
startup, matching work and remaining SKB/general application coverage are not
established by these controls. The next run is the existing eight-tool BCC path.
