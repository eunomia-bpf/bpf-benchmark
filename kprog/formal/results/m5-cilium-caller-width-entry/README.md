# Actual caller reader entry through first width call

The SAME ReaderEntry.entry executes once, followed once by WidthPrefix.execute. The entire reached heap is unchanged by the width prefix, preserving all actual resources, both original TableInitialized run-store witnesses, the Reads record, original provider traces and caller frame/access/frontier.

The pre-width environment is explicit. The reached resultEnv sets only the actual return and width temporaries, preserves index32 and all other lookups, and reaches original innerloop150/151 under the original outerloop and subsequent-instruction continuation.

Public temp_frame and entry queries check the composition. Complete instruction/native refinement and loaded text remain separate. Actual direct/focused/full/public logs are retained; CPU17/j1/nice0/32GiB and Lean caps remain fixed, outside timingSH per coordinator2026-11-28T05:43Z during x86 rotate, with formal-full-check exclusion.
