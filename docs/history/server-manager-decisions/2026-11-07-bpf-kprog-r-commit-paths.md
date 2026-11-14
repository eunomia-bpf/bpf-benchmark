# kprog: lane R commits named paths, not the shared index

- Date: 2026-11-07 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R) in Workspace `yunwei356/bpf-benchmark-dev`
- Status: deployed

## User request and approval

> “自己持续推进”

The operator asked the coordinator to decide and push the kprog work without
waiting. This record changes how R commits. It does not change what R
measures.

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-25 | How R commits | `git add <file> && git commit` against the shared index | `git commit -F <msg> -- <paths>`, with `git add -- <paths>` first only for new files; R checks `git show --stat HEAD` before pushing | The shared index holds an older tree, so each bare commit reverted other lanes' newer work |

## Evidence and implementation

- **The reverting commits.** Four R commits were made from the stale shared
  index: 3e9a9f7c5, 9867777e1, 0ce631f6f and 1508a2e58.
  - 0ce631f6f was meant to update the reproduction README and the otel
    results. It deleted 222 files other lanes had published and moved 26
    more back to older versions.
  - 1508a2e58, made 14 seconds after T restored its paths, reverted T's 37
    paths again.
- **Repairs.** Each lane restored its own paths after the earlier commits.
  The coordinator restored the remaining 248 paths from 0ce631f6f in
  5e48caca8, each set back to its 0ce631f6f^ content. That commit includes
  only paths no commit had touched since, and was made from a private index
  with a compare-and-swap ref update.
- **Why this works.** With paths on the command line, `git commit` builds
  the commit from HEAD plus those paths and ignores the rest of the index.
- **Rollout.** A COORDINATION notice told R the same thing right away. This
  prompt change makes it last across R's Jobs. The admission annotations
  point at this record.

## Validation and rollback

Validation:
- The CronJob shows the new sentence.
- The next R Job's argv carries it.
- R's later commits list only R's paths in `git show --stat`.
- The hourly `check.sh` still resets the shared index when it is stale.

Rollback: revert this commit.
