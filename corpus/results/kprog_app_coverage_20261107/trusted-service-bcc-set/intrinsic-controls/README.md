# Historical memset control capture, November7

This directory preserves the original three fixture definitions, producer manifests, replay source and actual115535-115539UTC capture as recorded on November7. The terminal records show valid_stack_fill executed with returncode0 and invalid_context_fill accepted at its load-only stage with unsafe_native_executed=false. The capture stopped at that finding; invalid_stack_fill remains a defined input in cases.json. summary.json retains the actual ok=false result and every raw artifact is preserved in controls-20261107T115539842188Z.tar.gz.

This historical recipe records its original source/build/output paths and source epoch. Current execution uses the published generic five-step path and run/build/cache directories under /var/tmp/kprog-tmp/C. Current kernel selftests and safety fixture definitions retain their published annotations. The historical accepted finding remains explicit with its source epoch.
