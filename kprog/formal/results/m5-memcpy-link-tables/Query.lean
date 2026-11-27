import KProgFormal.ClightRefinement.Arm64MemcpyLinkSource

#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.entry_valid
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.entry_valid
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.enter
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.enter
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.first_store
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.first_store
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.tables_source
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.tables_source
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.table_storage
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.table_storage
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.table_store
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.table_store
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.tableTemps_parameters
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.tableTemps_parameters
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.run_table
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.run_table
#check KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.initialize_tables
#print axioms KProgFormal.ClightRefinement.Arm64MemcpyLinkSource.initialize_tables

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkSource
open Arm64MemcpyLinkProgram (ge entry)
example (m : CC.Mem) (header registers : CC.Block)
    (headerOffset registerOffset : CC.Integers.Ptrofs) (address : BitVec 64) (k : CC.Cont)
    (old : header.toNat < m.nextblock.toNat)
    (read : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add headerOffset (CC.Integers.Ptrofs.repr 8))) =
        some (.Vptr registers registerOffset)) :
    ∃ block after, (allocation m).1.get Arm64Addressing.___a64_cells =
        some (block,CC.tarray (CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr)) 31) ∧
      InternalRun ge 6
        (.State entry entry.fn_body k (allocation m).1
          (temps (.Vptr header headerOffset) address) (allocation m).2)
        (.State entry afterFirst k (allocation m).1
          ((temps (.Vptr header headerOffset) address).set Arm64Addressing._t'69 (.Vptr registers registerOffset)) after) ∧
      CC.Mem.load CC.Mptr after block 0 = some (.Vptr registers registerOffset) ∧
      FrameBelow m.nextblock m after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  exact first_store m header registers headerOffset registerOffset address k old read
end KProgFormal.ClightRefinement.Arm64MemcpyLinkSource
