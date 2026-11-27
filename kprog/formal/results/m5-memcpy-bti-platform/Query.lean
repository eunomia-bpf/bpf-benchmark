import Arm.Insts.BR.Hints

#check BR.is_bti_hint
#check BR.exec_hints_bti
#print axioms BR.exec_hints_bti
example : Hints_cls → ArmState → ArmState := BR.exec_hints
