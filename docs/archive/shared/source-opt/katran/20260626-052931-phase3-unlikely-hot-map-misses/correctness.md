# Correctness gate

- Suite/app status: `ok`
- App error: `""`
- `post_rejit`: `null`
- `rejit_result.mode`: `skip_rejit_all`
- Baseline workload samples: 3
- Component returncodes: `0`
- Source scope: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- ABI/load-path check: no map definition, tail-call key, section name, packet ABI,
  userspace ABI, or loader path was changed.
- Semantic check: the patch only marks existing null/map-miss branches as
  unlikely with `__builtin_expect()`. The branch conditions, fallback actions,
  stats updates, destination selection, and encapsulation calls are unchanged.
