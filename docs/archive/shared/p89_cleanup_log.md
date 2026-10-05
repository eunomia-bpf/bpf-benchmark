# P89 Cleanup Log

Date: 2026-04-30

## Preconditions

- No active QEMU, virtme-ng, vng, or `runner/libs/kvm_executor.py` process was
  found before removing stale VM disk images.
- `docker ps` showed no running containers before checking
  `docs/tmp/runtime-container-tmp/run.*`.
- A Docker build/buildx process was active, so Docker BuildKit cache was not
  pruned.
- No `corpus/results` or `e2e/results` directory was removed or modified.

## Before

Command:

```bash
date -Is && df -h / /home/yunwei37/workspace/bpf-benchmark /tmp
```

Output:

```text
2026-04-30T10:34:59-07:00
Filesystem      Size  Used Avail Use% Mounted on
/dev/nvme0n1p2  915G  715G  155G  83% /
/dev/nvme0n1p2  915G  715G  155G  83% /
/dev/nvme0n1p2  915G  715G  155G  83% /
```

Matched cleanup candidates:

```text
docs/tmp/20260430/vm-tmp/bpf-benchmark-docker.img    68719476736 bytes apparent    2272 KB actual
```

No `docs/tmp/runtime-container-tmp/run.*` directories matched.
No `/tmp/codex_p*.log` files older than 7 days matched.

## Actions

- Removed stale VM docker disk image:
  `docs/tmp/20260430/vm-tmp/bpf-benchmark-docker.img`.
- Did not prune Docker BuildKit cache.
- Did not remove any benchmark result directory.

## After

Command:

```bash
date -Is && df -h / /home/yunwei37/workspace/bpf-benchmark /tmp
```

Output:

```text
2026-04-30T10:35:16-07:00
Filesystem      Size  Used Avail Use% Mounted on
/dev/nvme0n1p2  915G  715G  155G  83% /
/dev/nvme0n1p2  915G  715G  155G  83% /
/dev/nvme0n1p2  915G  715G  155G  83% /
```

Post-cleanup checks found no remaining `docs/tmp/*/vm-tmp/*.img`,
`docs/tmp/runtime-container-tmp/run.*`, or older-than-7-days
`/tmp/codex_p*.log` matches.
