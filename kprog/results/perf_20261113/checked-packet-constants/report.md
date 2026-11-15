# Current checked packet host regression

2026-11-15T10:26:22Z. `checked-packet-host` exits0 with25 independent native
versus checked-C execution vectors: nine XDP, eight TC and eight cgroup_skb.
Return values and every byte of each4,096-byte context match. The eight-byte
qdisc prefix remains unchanged. This kernel's BTF independently gives
`sk_buff.cb=40`, `qdisc_skb_cb.data=8`, hence BPF metadata offset48.

This uses current checked compiler/context handling and the immutable width/
selector source3f27add92/c25ed3354/a7b399a9a, all LTO together. It compiles the
checked C into host native code and executes it against the original native
fixture. It does **not** execute changed B in the kernel or accept OTel.
The exact committed Make command is in `packet-final2/make-command.txt`;
execution/BTF/link/compiler metadata are under `packet-final2/packet`.
Host CPUs16–17/16GiBAS/imageSH, no guest, timing lock or base/image write.

Initial attempts failed before new execution: the root build directory already
existed (`packet-host`), then the deliberately fresh generated directory
already existed (`packet-corrected`), then a cross-filesystem rename failed
(`packet-final`). Old JSON copied by the failure recipe is not new execution
evidence. Fixes487db77c7/8a587f87d reuse the canonical test directories;
90a0c6784/64c4643c4 preserve prior metadata/logs across filesystems and replace
only this test's known compiled products before fresh generation. Production
`specialize()` keeps its fresh-directory requirement, so stale bitcode cannot
be silently reused after a mode/input change.

The successful rebuild replaced45 build files (10,501,104bytes), recording
each path/size/SHA256/action/completion. All21 prior raw metadata/log files
(27,931bytes) were moved to persistent storage, not deleted. The earlier
failed manifest has all actions incomplete and removed nothing. Complete
manifests and preserved metadata are under `rebuild`; original persistent
records remain `/workspaces/kprog-raw/perf/checked-packet-rebuild`.
All attempted run logs remain under
`/workspaces/kprog-raw/perf/20261115-width-constants/packet-*`.
No compiled product is archived in this result directory.
