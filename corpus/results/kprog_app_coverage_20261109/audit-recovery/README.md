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
