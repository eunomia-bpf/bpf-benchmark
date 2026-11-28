# Original caller header pointer stores

For each of the twelve fixed pointer fields, the actual allocated header's first 96 writable bytes and its current permission map derive a genuine Mint64 store at offset 8*i. The value is the pointer derived by the original RHS expression from the same allocation. The very same store establishes its pointer readback, preserves the other eleven nonoverlapping field loads, every other block, the caller frame, permissions and allocation frontier.

The original sequence/assignment/skip visit executes in three internal steps with that same store. Its CompCert assignment uses the accepted original field lvalue evaluation, array-decay or address-of RHS evaluation and cast. The temporary environment is unchanged. Actual allocation name separation converts the other-block frame into preservation of every other local.

Three root queries check store, visit and named_frame, with retained direct, focused, full-root and public logs. This step does not yet compose all twelve visits or the whole function entry. The exact subsequent source remains the original vector_lo[0] NULL assignment. No native/global/universal refinement or M6 completion is claimed.
