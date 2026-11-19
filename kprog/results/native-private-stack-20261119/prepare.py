"""Prepare the native counterpart of the existing B private-arena rule."""
from pathlib import Path
import difflib
p=Path('kprog/x86/compile_sim_ir.cpp');old=p.read_text()
new=old.replace('#include "llvm/IR/IRBuilder.h"','#include "llvm/Analysis/ValueTracking.h"\n#include "llvm/IR/IRBuilder.h"',1)
point='int main(int argc,char **argv) {'
code='''// The same private arena has ordinary Mem semantics in the checked B pass
// (packet_bounds_ir.cpp). Context/global/atomic accesses retain volatility.
static unsigned normalizePrivateStack(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *load=dyn_cast<LoadInst>(&instruction);
    auto *store=dyn_cast<StoreInst>(&instruction);
    Value *pointer=nullptr;
    if (load && load->isVolatile() && !load->isAtomic()) pointer=load->getPointerOperand();
    if (store && store->isVolatile() && !store->isAtomic()) pointer=store->getPointerOperand();
    if (!pointer) continue;
    SmallVector<const Value *,4> objects;
    getUnderlyingObjects(pointer,objects);
    if (objects.empty()) continue;
    bool privateStack=true;
    for (auto *object:objects) {
      auto *local=dyn_cast<AllocaInst>(object);
      auto *type=local?dyn_cast<StructType>(local->getAllocatedType()):nullptr;
      if (!type || type->getName()!="union.x86_sim_stack_mem") {
        privateStack=false;break;
      }
    }
    if (!privateStack) continue;
    if (load) load->setVolatile(false);else store->setVolatile(false);
    ++count;
  }
  return count;
}

'''
new=new.replace(point,code+point,1).replace('  if (verifyModule(*m,&errs())) return 1;',
 '  errs()<<"native private stack accesses normalized="<<normalizePrivateStack(*m)<<\'\\n\';\n  if (verifyModule(*m,&errs())) return 1;',1)
Path('kprog/results/native-private-stack-20261119/implementation.patch').write_text(''.join(
 difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile='a/'+str(p),tofile='b/'+str(p))))
