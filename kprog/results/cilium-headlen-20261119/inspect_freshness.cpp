// Reuse the actual selector and walker on retained IR, without changing it.
#define main packet_bounds_main
#include "../../x86/packet_bounds_ir.cpp"
#undef main

int main(int argc,char **argv) {
  if (argc!=2) { errs()<<"usage: inspect-freshness bounds.bc\n";return 1; }
  LLVMContext context;SMDiagnostic error;
  auto module=parseIRFile(argv[1],error,context);
  if (!module) { error.print(argv[0],errs());return 1; }
  for (auto &function:*module) {
    if (function.isDeclaration()) continue;
    SmallVector<Instruction *,8> reads;
    for (auto &instruction:instructions(function))
      if (field(&instruction,function,offsetof(__sk_buff,data))) reads.push_back(&instruction);
    for (auto *read:reads) {
      errs()<<"READ "<<*read<<'\n';
      for (auto *source:reads) {
        if (source==read) break;
        errs()<<"FROM ";source->printAsOperand(errs(),false);
        errs()<<" fresh="<<current_headlen(source,read)<<'\n';
      }
    }
    // Show the first blocking instruction on each reverse predecessor path.
    for (unsigned index=1;index<reads.size();++index) {
      auto *read=reads[index];auto *source=reads[index-1];
      SmallVector<std::pair<BasicBlock *,Instruction *>,16> pending{{read->getParent(),read}};
      SmallPtrSet<BasicBlock *,32> visited;
      while (!pending.empty()) {
        auto [block,limit]=pending.pop_back_val();
        if (!limit && !visited.insert(block).second) continue;
        auto it=limit?limit->getIterator():block->end();bool stopped=false;
        while (it!=block->begin()) {
          auto &instruction=*--it;
          if (&instruction==source) { stopped=true;break; }
          if (!instruction.mayWriteToMemory()) continue;
          if (auto *store=dyn_cast<StoreInst>(&instruction))
            if (isa<AllocaInst>(getUnderlyingObject(store->getPointerOperand()))) continue;
          if (auto *call=dyn_cast<CallBase>(&instruction)) {
            if (call->onlyReadsMemory() || kernel_context_cast(call)) continue;
            if (auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand())) {
              auto text=assembly->getAsmString();
              if (tied_identity(call,assembly) || skb_cb_store(call,assembly) ||
                  (text=="$0 = $0" && assembly->getConstraintString()=="=w,0") ||
                  (assembly->getConstraintString()=="=r,r,i,~{memory}" &&
                   (text=="$0 = *(u8 *)($1 + $2)" || text=="$0 = *(u16 *)($1 + $2)" ||
                    text=="$0 = *(u32 *)($1 + $2)" || text=="$0 = *(u64 *)($1 + $2)"))) continue;
            }
          }
          errs()<<"BLOCKING "<<*read<<" BY "<<instruction<<'\n';
          stopped=true;break;
        }
        if (!stopped) for (auto *parent:predecessors(block)) pending.emplace_back(parent,nullptr);
      }
    }
  }
}
