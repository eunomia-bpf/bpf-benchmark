# Docker Build Cache GC

Docker BuildKit cache is intentionally not pruned automatically by repository
targets. Runtime images are large enough that an unexpected prune can slow down
active benchmark work or remove cache needed by another local run.

Use manual GC only after confirming no image build is active:

```bash
docker buildx ls
docker ps --filter status=running
docker buildx du
docker buildx prune --keep-storage 50GB
```

`--keep-storage` should be sized for the current host. Smaller values recover
more disk but make the next runtime image build more expensive.

This policy is only for Docker builder cache. Benchmark results under
`corpus/results` and `e2e/results` are retained manually and must not be removed
by Docker GC or Makefile cleanup targets.
