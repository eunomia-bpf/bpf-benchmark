# Verified-track audit recovery

Operator order: the 2026-11-09 21:50 change-necessity audit, sections 5 and 6.
Each step is a forward commit, with its own push. Runtime checks added total 0.

## Step 1: stock six-register entry by default

The existing CK/linux kinsn-free tree at commit 390ef9011c7d saves
RBX/R13/R14/R15/R12/RBP around P and restores them before the stock return.
The current native-link default selects its existing stock-entry-frame feature.
B retains RSP returning to entry and the interpreter's existing return-target
dispatch. The six saved-entry values and callee equality arm are removed.
The incremental kernel recipe now builds the committed CK source directly.
The verifier source remains the stock source used by the existing kinsn-free line.

The prior fixed f05af452e positive tail replay completes at guest/make exit0.
Its original native/BPF fixtures and physical R12/RBP/RSP observation are retained
in step1-tail-raw.tar.gz. The 96b fixed census continues with its captured runtime.
One final same-model app and safety replay follows the requested restoration steps.

## Step 2: original x86 stack metadata

Forward commits undo the x86 hunks of 5d8c38d3a, b1d4012f1, 670b6e430, 8001a5459, b3c912c1e, a3a4470c3, ebe984e0f and 53dc94561. The declaration block matches aee6b236d exactly: architectural bytes plus one pointer and one byte tag per selected word. Scalar forwarding values, validity bits and their generator selection are removed. The later SP-lifetime reading semantics and stock load-fault recovery remain. The four read-only helper selections return to their earlier helper wrappers. ARM representation changes remain lane A ownership.

## Step 3a: ordinary helper and copy arguments

The x86 f7c517c0a output-below-SP fault arm and its helper/copy/fill wrapper selections are removed. memcpy uses its original source argument for scalar and pointer-shaped values. The ordinary read semantics, native count, helper calls and exception-table load recovery remain. Published safety inputs, including the cases added by 25a373adf, retain their original source and annotations for the final replay.

## Step 3b: original context selection and native copy extent

Context selection again maps XDP, TC and cgroup-SKB to their typed layouts and every other program type to raw. The 17-family generation-failure branch and its dedicated rejection test are removed. The old x86 transport copy uses the submitted extent through vmemdup_user; the added 1GiB E2BIG arm is removed. The active stock transport already uses the submitted extent directly.

CK commit c1b9c1370976 removes the armed-image subprogram pre-verifier error and its prepare function/prototype. B now reaches the ordinary verifier and JIT subprogram machinery. The stock verifier source remains byte-identical to c23719abc330.
