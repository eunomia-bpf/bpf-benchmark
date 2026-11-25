# Verified-path coverage, recounted by simulator failure (2026-11-25T00:2xZ, coordinator)

Capture: /workspaces/kprog-raw/omp/classfg-20261124T070800Z/{tetragon,tracee}/service.tar.gz (OMP, 11-24, current
tree with the 11-23 B fixes and 439b53c92). Each request archive (service/requests/N.success.tar.gz) is opened; a
request with simulator-failure.json fell back to direct-native, one without it installed checked-sim-c. The
service's status 0 covers both, so "81 of 85" and "169 of 169" (2dc7f4fbb, COORDINATION 11:30Z and 18:42Z) count
the fallback too; the coordinator relayed them in the 11-24 reports, and this file corrects them.

| App | Requests | Verified path (checked-sim-c) | Fallback to direct-native | Fallback stage |
|---|---|---|---|---|
| Tetragon | 85 | **16** | 69 | verification 68, generation 1 |
| Tracee | 169 | **49** | 120 | verification 115, verification-preparation 5 |

Tetragon's 68 verifier rejections (native-link-refusals README in the coordinator's analysis directory): 35 invalid
write to stack R10 (class F, B frame past 512 bytes), 20 invalid mem access 'scalar' (class G), 12 E2BIG (over 1M
instructions), 1 too complex.

Script: count.py in this directory (one pass over the outer archive, each request archive opened in memory).

## Recheck on the current tree (2026-11-25T01:3xZ, coordinator)

Capture: /workspaces/kprog-raw/verified/checked-corpus-20261125-recheck (`make -C kprog/libnativeloader
checked-corpus-all`, started 00:16Z with HEAD 77644d009 plus the shared tree's uncommitted changes, before
c39250e88 landed at 01:01Z; make exit 1). Counted the same way, per request:
checked-sim-c when the archive has no simulator-failure.json and is a success archive.

| App | Requests | Verified path (checked-sim-c) | Fallback to direct-native | Failed outright |
|---|---|---|---|---|
| BCC | 25 | **14** | 11 (generation) | 0 |
| Cilium | 64 | **16** | 43 (generation 31, verification 12) | 5 |
| Katran | 1 | **0** | 1 (generation) | 0 |
| OTel | 14 | **9** | 4 (generation) | 1 |

- Cilium's 5 failures (cil_from_host ×3, cil_to_container ×2) stop in the context-lower step after B passed the
  verifier; the tool kept no stderr. These programs did not load at all.
- OTel request 14 (custom__generic): generation fell back and the direct-native load was rejected ("Invalid
  argument", 4 instructions processed).
- OTel request 13 (native_tracer_entry, direct-native after a generation refusal, "unsupported unresolved call
  target") then crashed the guest kernel: RIP native_tracer_entry+0x1e2, `mov rax,[rbx]; mov rax,[rax]; cmp qword
  [rax+0xa0],0x2b`, RAX 0x26, CR2 0xc6. This is a user_mode(regs) test whose regs pointer read 0x26 from the ctx.
  The fault is on the direct-native fallback, not on the verified path. Handed to OMP (COORDINATION 01:27Z).
- An earlier count of Cilium as 21/64 counted the 5 failure archives as verified; corrected here and in
  COORDINATION 01:3xZ.

Script: count-recheck.py in this directory.
