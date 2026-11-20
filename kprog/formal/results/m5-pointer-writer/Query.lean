import KProgFormal.ClightRefinement.Arm64PointerWriteLinked

open KProgFormal.ClightRefinement

#check Arm64PointerWrite.execute_stores_layout
#print axioms Arm64PointerWrite.execute_stores_layout

#check Arm64PointerWrite.write
#print axioms Arm64PointerWrite.write

#check Arm64PointerWrite.Result.kept
#print axioms Arm64PointerWrite.Result.kept

#check Arm64PointerWrite.Result.represents
#print axioms Arm64PointerWrite.Result.represents

#check Arm64PointerWrite.write_all_behaviors
#print axioms Arm64PointerWrite.write_all_behaviors

#check Arm64PointerWrite.Linked.layout
#print axioms Arm64PointerWrite.Linked.layout

#check Arm64PointerWrite.Linked.binding
#print axioms Arm64PointerWrite.Linked.binding

#check Arm64PointerWrite.Linked.write
#print axioms Arm64PointerWrite.Linked.write

#check Arm64PointerWrite.Linked.all_behaviors
#print axioms Arm64PointerWrite.Linked.all_behaviors
