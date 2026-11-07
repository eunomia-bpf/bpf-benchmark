# Coordinator-authorized raw trace cleanup

On2026-11-07 the coordinator requested deletion of completed lane F
`cpu-states.bin` files under the 20261106/20261107 differential results.
The operator repeated that request during the disk-pressure response.

Deleted13 untracked raw traces:9,521,498,424 logical bytes and
9,521,668,096 allocated bytes (8.87GiB). Observed available space increased
by exactly9,521,668,096bytes. Workspace usage changed89%?85%; available
space changed30,832,104?40,130,608KiB.

Before deletion, every corresponding committed summary was verified against
its HEAD blob. Two complete `/proc/*/fd` checks found no open reference to
any candidate inode and no permission errors; the first scanned672 file
descriptors. Absolute resolved paths, inode/device/size and untracked status
were checked. Only the exact13 `cpu-states.bin` paths were unlinked.
`audit.json` lists all files, summary blob identities and disk measurements.

Committed summaries, compressed mismatch inputs, source snapshots and saved
native executables remain intact. Other lanes' files and guest images were
untouched. The shift job had already failed during build and had no active
CPU/replay reader. Subsequent reference work requires a fresh CPU trace,
using the saved executable/source and a new output directory; its states
must be identified as a new run. The former exact old trace is retired.
