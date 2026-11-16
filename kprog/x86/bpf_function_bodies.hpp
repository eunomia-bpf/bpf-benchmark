#pragma once
// Compile only the exact supplied BPF leaf semantics, shared by producer and
// load-time native LTO. No symbol names or absent bodies imply an implementation.
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/JSON.h"
#include <linux/bpf.h>
#include <functional>

namespace native_bpf {
using namespace llvm;
inline Error failure(const Twine &Message) {
  return make_error<StringError>(Message.str(), inconvertibleErrorCode());
}
inline Error materializeFunctions(Module &M,json::Value &Document,
    std::function<Error(Function &, ArrayRef<bpf_insn>)> Lower = {}) {
  auto *Object=Document.getAsObject();
  auto *Functions=Object?Object->getObject("functions"):nullptr;
  if (!Functions) return failure("BPF function bodies require a functions object");
  struct Body { Function *F; uint64_t Value; SmallVector<bpf_insn,8> Code; bool Leaf; };
  SmallVector<Body,16> Bodies;
  for (auto &Entry:*Functions) {
    auto *F=M.getFunction(Entry.first);
    if (!F || !F->isDeclaration()) return failure(Twine("BPF body needs an existing function declaration: ")+StringRef(Entry.first));
    auto Text=Entry.second.getAsString();
    if (!Text || (!Lower && Text->size()!=sizeof(bpf_insn)*4))
      return failure("BPF constant leaf requires two complete instructions");
    if (Text->empty() || Text->size() % (sizeof(bpf_insn)*2))
      return failure("BPF function requires complete instructions");
    SmallVector<bpf_insn,8> Code(Text->size() / (sizeof(bpf_insn)*2));
    auto *Bytes=reinterpret_cast<unsigned char *>(Code.data());
    for (size_t I=0;I<Code.size()*sizeof(bpf_insn);++I) {
      unsigned Byte;
      if (Text->substr(I*2,2).getAsInteger(16,Byte)) return failure("malformed BPF function instruction hex");
      Bytes[I]=Byte;
    }
    bool Wide=Code[0].code==(BPF_ALU64|BPF_MOV|BPF_K);
    bool Narrow=Code[0].code==(BPF_ALU|BPF_MOV|BPF_K);
    bool Leaf=Code.size()==2 && (Wide || Narrow) && Code[0].dst_reg==BPF_REG_0 && !Code[0].src_reg && !Code[0].off &&
        Code[1].code==(BPF_JMP|BPF_EXIT) && !Code[1].dst_reg && !Code[1].src_reg && !Code[1].off && !Code[1].imm;
    if (!Leaf && !Lower)
      return failure(Twine("BPF function body is not an exact constant-return leaf: ")+StringRef(Entry.first));
    auto *Return=F->getReturnType();
    if ((!Return->isIntegerTy() || Return->getIntegerBitWidth()>64) && !Return->isPointerTy() && !Return->isVoidTy())
      return failure("BPF scalar return has an incompatible native return type");
    Bodies.push_back({F,Wide?uint64_t(int64_t(Code[0].imm)):uint64_t(uint32_t(Code[0].imm)), std::move(Code), Leaf});
  }
  // Parse all supplied records first. A lowering error never emits a partial
  // native object or substitutes an implementation for missing semantics.
  for (auto &Body:Bodies) {
    if (!Body.Leaf) {
      if (auto E=Lower(*Body.F,Body.Code)) return E;
      continue;
    }
    auto *Block=BasicBlock::Create(M.getContext(),"original_bpf_leaf",Body.F);
    Body.F->setLinkage(GlobalValue::InternalLinkage);
    Body.F->setDSOLocal(true);
    // A declaration's debug node is not a definition, and describes the C
    // declaration rather than the provided current-load BPF body.
    Body.F->setSubprogram(nullptr);
    IRBuilder<> B(Block);auto *Return=Body.F->getReturnType();
    if (Return->isVoidTy()) B.CreateRetVoid();
    else if (Return->isPointerTy()) B.CreateRet(B.CreateIntToPtr(B.getInt64(Body.Value),Return));
    else B.CreateRet(ConstantInt::get(Return,Body.Value));
  }
  return Error::success();
}
} // namespace native_bpf
