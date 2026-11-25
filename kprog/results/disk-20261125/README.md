# /workspaces at 97%: packing rebuildable and stopped-lane data (coordinator, 2026-11-25)

- 19:2xZ: arm64 stage-1 .bc intermediates packed per app (/workspaces/kprog-raw/omp/arm64-coverage-20261125/intermediate-bc-<app>.tar.zst, 1.4 GB -> about 550 MB; .o kept).
- 22:2xZ: the CL lane's raw scratch (/workspaces/kprog-raw/var-tmp/CL, 13 GB, 8.1 GB of it preprocessed .i; lane stopped since 2026-11-11) packed into var-tmp/CL.tar.zst by pack-var-tmp-CL.sh; the originals go only when a full listing of the archive matches the file count.
- Expanding the volume stays with the operator's word (every earlier Workspace expansion carried it, and it leaves a Longhorn snapshot on lab's disk).
