# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` exited 0 after fixing the stale cleanup jump; build log saved in `build.log` | pass |
| Load | TBD after formal `make corpus` run | pending |
| Workload | TBD after formal `make corpus` run | pending |
| Result schema | TBD after formal `make corpus` run | pending |
| ABI | `tcpconnect` event, count key/value, `capable`, and `syscount` payload/map layouts are unchanged; `tcpconnect` removes only its private temporary handoff map | pass |
| Coverage | `tcpconnect` still handles IPv4 and IPv6 connects, pid/uid/port filters, count mode, and event mode; failed connects still do not emit events | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, and run command recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 744G 125G 86% /`; no Docker cleanup needed before this attempt.
