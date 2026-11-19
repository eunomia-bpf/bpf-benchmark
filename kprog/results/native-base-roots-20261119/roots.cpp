// Inspect the roots hidden by generated native memory-base barriers.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <map>
using namespace llvm;

static void inspect(Module &module, StringRef phase) {
  std::map<std::string, unsigned> counts;
  for (auto &function : module) for (auto &instruction : instructions(function)) {
    auto *call = dyn_cast<CallInst>(&instruction);
    if (!call || call->arg_size() != 1) continue;
    auto *assembly = dyn_cast<InlineAsm>(call->getCalledOperand());
    if (!assembly || !assembly->getAsmString().empty() ||
        assembly->getConstraintString() != "=r,0") continue;
    auto *cast = dyn_cast<PtrToIntInst>(call->getArgOperand(0));
    if (!cast) { ++counts["non-pointer operand"]; continue; }
    SmallVector<Value *, 4> roots;
    bool known = getUnderlyingObjectsForCodeGen(cast->getPointerOperand(), roots);
    bool privateStack = known && !roots.empty();
    for (auto *root : roots) {
      auto *local = dyn_cast<AllocaInst>(root);
      auto *type = local ? dyn_cast<StructType>(local->getAllocatedType()) : nullptr;
      if (!type || type->getName() != "union.x86_sim_stack_mem") privateStack = false;
    }
    ++counts[privateStack ? "known private arena" : known ? "other known roots" : "unknown roots"];
  }
  for (const auto &count : counts)
    outs() << phase << '\t' << count.first << '\t' << count.second << '\n';
}

int main(int argc, char **argv) {
  if (argc != 2) return 1;
  LLVMContext context;
  SMDiagnostic diagnostic;
  auto module = parseIRFile(argv[1], diagnostic, context);
  if (!module) { diagnostic.print(argv[0], errs()); return 1; }
  inspect(*module, "retained");
  // Defined integer constants have no poison bits; freezing preserves them.
  // Change only this in-memory diagnostic module, never the retained input.
  SmallVector<FreezeInst *, 16> constants;
  for (auto &function : *module) for (auto &instruction : instructions(function))
    if (auto *freeze = dyn_cast<FreezeInst>(&instruction))
      if (isa<ConstantInt>(freeze->getOperand(0))) constants.push_back(freeze);
  for (auto *freeze : constants) {
    freeze->replaceAllUsesWith(freeze->getOperand(0));
    freeze->eraseFromParent();
  }
  inspect(*module, "constant-freezes-folded");
}
