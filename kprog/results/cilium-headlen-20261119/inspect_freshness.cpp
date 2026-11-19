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
  }
}
