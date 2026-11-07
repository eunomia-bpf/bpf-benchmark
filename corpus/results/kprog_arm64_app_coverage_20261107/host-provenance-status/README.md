# Host outcomes and complete source provenance

The completed ARM Katran run records guest exit0, application status ok and one bound service request. Its host ok field follows a source-hash drift flag caused by the shared inventory's x86 memory header update. Packet and receiver work remain in the original runtime archive and the two-start analysis.

The common transport now derives host outcome from QEMU, guest and application completion. Before/after source hash vectors and their equality flag retain provenance independently. Sixteen status combinations preserve QEMU/guest/application failures while completed work retains its actual outcome across shared source changes. The captured completed-run record reproduces the prior false host outcome and the corrected result.

The patch is queued in the existing Tetragon application collector's common transport source, after its main/readonly/Cilium predecessors close. Current application jobs retain their loaded source epoch. Kernel binding, native inputs, source generation, workload and application protocol retain their existing behavior. Original runtime records keep their original values.
