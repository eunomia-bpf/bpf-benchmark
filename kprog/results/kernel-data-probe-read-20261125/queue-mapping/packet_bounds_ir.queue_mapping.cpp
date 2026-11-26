// Express the simulator's existing packet length predicates as pointer bounds
// for the stock BPF backend/verifier. This changes no application predicate.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/Analysis/InstructionSimplify.h"
#include "llvm/Analysis/ConstantFolding.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/ConstantRange.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/DIBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ModRef.h"
#include "llvm/Support/ToolOutputFile.h"
#include <linux/bpf.h>
#include <algorithm>
#include <cstddef>
using namespace llvm;
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
// The private arena's IR type name is ISA-specific: x86's body names a
// union, arm64's volatile arena is anonymous (%union.anon). Accepted names
// come from -stack-arena and default to the x86 spelling.
static cl::list<std::string> StackArena("stack-arena",cl::CommaSeparated);
static const std::set<std::string> &arenaNames() {
  static const std::set<std::string> names=[] {
    std::set<std::string> result;
    for (const auto &name:StackArena) result.insert(name);
    if (result.empty()) result.insert("union.x86_sim_stack_mem");
    return result;
  }();
  return names;
}
// Clang can leave an asm-named extern's debug declaration detached from its
// actual LLVM global. BTF then omits the VAR and libbpf cannot open B. Rendered
// map bindings are zero-length byte arrays; describe that exact IR declaration
// under its linker name, without guessing which orphan C alias belongs to it.
static unsigned restore_map_extern_debug_info(Module &module) {
  auto *units=module.getNamedMetadata("llvm.dbg.cu");
  if (!units || !units->getNumOperands()) return 0;
  auto *unit=cast<DICompileUnit>(units->getOperand(0));
  DIBuilder builder(module,true,unit);
  unsigned count=0;
  for (auto &global:module.globals()) {
    auto *array=dyn_cast<ArrayType>(global.getValueType());
    if (!global.isDeclaration() || global.getSection()!=".ksyms" ||
        global.getMetadata(LLVMContext::MD_dbg) || !array ||
        array->getNumElements()!=0 || !array->getElementType()->isIntegerTy(8)) continue;
    auto *byte=builder.createBasicType("unsigned char",8,dwarf::DW_ATE_unsigned_char);
    auto *type=builder.createArrayType(0,8,byte,
        builder.getOrCreateArray({builder.getOrCreateSubrange(0,int64_t{0})}));
    global.addDebugInfo(builder.createGlobalVariableExpression(unit,global.getName(),
        global.getName(),unit->getFile(),0,type,false,false));
    ++count;
  }
  builder.finalize();
  return count;
}
static bool tied_identity(CallBase *call,InlineAsm *assembly) {
  return assembly->getAsmString().empty() && assembly->getConstraintString()=="=r,0" &&
      call->arg_size()==1 && call->getType()==call->getArgOperand(0)->getType();
}
// Empty memory-only templates are compiler barriers, with no architectural
// operation. Real helper/memory asm keeps its clobbers and ordering effects.
static unsigned remove_empty_memory_barriers(Module &module) {
  SmallVector<CallInst *,16> barriers;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *call=dyn_cast<CallInst>(&instruction);
    if (!call || !call->getType()->isVoidTy() || call->arg_size()!=0) continue;
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (assembly && assembly->getAsmString().empty() &&
        assembly->getConstraintString()=="~{memory}" &&
        !assembly->isAlignStack() && !assembly->canThrow()) barriers.push_back(call);
  }
  for (auto *barrier:barriers) barrier->eraseFromParent();
  return barriers.size();
}
// The kernel lookup reads its key without retaining it; probe reads copy from
// source to destination (including zeroing destination on error). Keep map
// mutation and kernel-internal effects, and never promise disjoint arguments.
static unsigned describe_helper_memory(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *call=dyn_cast<CallInst>(&instruction);
    if (!call) continue;
    auto *target=dyn_cast<ConstantExpr>(call->getCalledOperand());
    if (!target || target->getOpcode()!=Instruction::IntToPtr) continue;
    auto *number=dyn_cast<ConstantInt>(target->getOperand(0));
    if (!number || number->getValue().getActiveBits()>32) continue;
    unsigned id=number->getZExtValue();
    if (id==BPF_FUNC_map_lookup_elem && call->arg_size()==2 &&
        call->getArgOperand(0)->getType()->isPointerTy() &&
        call->getArgOperand(1)->getType()->isPointerTy()) {
      call->setMemoryEffects(MemoryEffects::inaccessibleOrArgMemOnly());
      call->addParamAttr(1,Attribute::ReadOnly);
      call->addParamAttr(1,Attribute::NoCapture);
      ++count;
    } else if ((id==BPF_FUNC_probe_read || id==BPF_FUNC_probe_read_str ||
                id==BPF_FUNC_probe_read_user || id==BPF_FUNC_probe_read_kernel ||
                id==BPF_FUNC_probe_read_user_str || id==BPF_FUNC_probe_read_kernel_str) &&
               call->arg_size()==3 && call->getArgOperand(0)->getType()->isPointerTy() &&
               call->getArgOperand(2)->getType()->isPointerTy()) {
      call->setMemoryEffects(MemoryEffects::inaccessibleOrArgMemOnly());
      call->addParamAttr(0,Attribute::WriteOnly);
      call->addParamAttr(0,Attribute::NoCapture);
      call->addParamAttr(2,Attribute::ReadOnly);
      call->addParamAttr(2,Attribute::NoCapture);
      ++count;
    }
  }
  return count;
}
// The interpreter's private arena is a local memory block. Clight volatile
// accesses to this block have ordinary Mem load/store semantics and trace E0;
// volatile global/context accesses remain externally observable. Expose only
// the private arena to LLVM's normal scalar replacement and dead-store passes.
static unsigned normalize_private_stack_accesses(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    Value *pointer=nullptr;
    auto *load=dyn_cast<LoadInst>(&instruction);
    auto *store=dyn_cast<StoreInst>(&instruction);
    if (load && load->isVolatile() && !load->isAtomic()) pointer=load->getPointerOperand();
    if (store && store->isVolatile() && !store->isAtomic()) pointer=store->getPointerOperand();
    if (!pointer) continue;
    SmallVector<const Value *,4> objects;
    getUnderlyingObjects(pointer,objects);
    if (objects.empty()) continue;
    bool private_stack=true;
    for (auto *object:objects) {
      auto *local=dyn_cast<AllocaInst>(object);
      auto *type=local?dyn_cast<StructType>(local->getAllocatedType()):nullptr;
      if (!type || !arenaNames().count(type->getName().str())) {
        private_stack=false;break;
      }
    }
    if (!private_stack) continue;
    if (load) load->setVolatile(false);else store->setVolatile(false);
    ++count;
  }
  return count;
}
// A tied empty asm with an integer constant emits no operation and returns
// exactly those bits. Propagate newly exposed integer constants through pure
// constant expressions to their next identity, so chains reach a fixed point.
// Live operands, pointer identities, clobbers and real assembly stay opaque.
static unsigned fold_constant_identities(Module &module) {
  SmallSetVector<Instruction *,32> pending;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    if (instruction.getType()->isIntegerTy()) pending.insert(&instruction);
  }
  unsigned identities=0;
  while (!pending.empty()) {
    auto *instruction=pending.pop_back_val();
    ConstantInt *constant=nullptr;
    if (auto *call=dyn_cast<CallInst>(instruction)) {
      auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
      // A constant ALU32 self move has the same i32 bits. Keep live-input
      // moves: their physical zero extension preserves verifier bounds.
      if (assembly && !assembly->isAlignStack() && !assembly->canThrow() &&
          (tied_identity(call,assembly) ||
           (assembly->getAsmString()=="$0 = $0" &&
            assembly->getConstraintString()=="=w,0" && call->arg_size()==1 &&
            call->getType()->isIntegerTy(32) &&
            call->getArgOperand(0)->getType()==call->getType())))
        constant=dyn_cast<ConstantInt>(call->getArgOperand(0));
      if (constant) ++identities;
    } else if (isa<BinaryOperator,CastInst,CmpInst,SelectInst,PHINode>(instruction)) {
      constant=dyn_cast_or_null<ConstantInt>(
          ConstantFoldInstruction(instruction,module.getDataLayout()));
    }
    if (!constant) continue;
    for (auto *user:instruction->users())
      if (auto *next=dyn_cast<Instruction>(user))
        if (next!=instruction && next->getType()->isIntegerTy()) pending.insert(next);
    instruction->replaceAllUsesWith(constant);instruction->eraseFromParent();
  }
  return identities;
}
// A tied empty register template returns its input bits. Freeze also models
// a concrete register value when LLVM represents the incoming value as undef
// or poison, while retaining defined input bits. Pointer and memory-clobber
// templates retain their existing treatment.
static unsigned normalize_live_integer_identities(Module &module) {
  SmallVector<CallInst *,16> calls;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *call=dyn_cast<CallInst>(&instruction);
    if (!call || !call->getType()->isIntegerTy()) continue;
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (assembly && tied_identity(call,assembly) && !assembly->isAlignStack() &&
        !assembly->canThrow()) calls.push_back(call);
  }
  for (auto *call:calls) {
    IRBuilder<> builder(call);builder.SetCurrentDebugLocation(call->getDebugLoc());
    auto *value=builder.CreateFreeze(call->getArgOperand(0),"register_bits");
    call->replaceAllUsesWith(value);call->eraseFromParent();
  }
  return calls.size();
}
// Whether a value's bits originate in a pointer: a ptrtoint, a register's
// frozen concrete bits, or any constant add/sub on top of one. The simulator
// keeps a lane as "ptrtoint + scaled register bits" (%2795 = add i64
// %register_bits, %ptrtoint in OTel request 10's retained IR), so adding a
// scalar to a pointer still yields pointer-derived bits; ending the walk at
// that add is what left the stack-pointer subtraction at B PC1583 in place.
static bool pointer_bits(Value *value) {
  while (true) {
    if (auto *freeze=dyn_cast<FreezeInst>(value)) { value=freeze->getOperand(0); continue; }
    if (isa<PtrToIntOperator>(value)) return true;
    auto *operation=dyn_cast<Operator>(value);
    if (!operation) return false;
    auto opcode=operation->getOpcode();
    if ((opcode==Instruction::Add || opcode==Instruction::Sub) &&
        isa<ConstantInt>(operation->getOperand(1))) { value=operation->getOperand(0); continue; }
    if (opcode==Instruction::Add && isa<ConstantInt>(operation->getOperand(0))) {
      value=operation->getOperand(1);continue;
    }
    if (opcode==Instruction::Add) {
      if (pointer_bits(operation->getOperand(0))) { value=operation->getOperand(0); continue; }
      if (pointer_bits(operation->getOperand(1))) { value=operation->getOperand(1); continue; }
    }
    return false;
  }
}
// A pointer difference may only be verifier-legal on its original CFG path.
// Keep the arithmetic there: pure SUB can otherwise be speculated before a
// tag test, exposing scalar-minus-pointer on an infeasible stack-pointer path.
static unsigned anchor_pointer_differences(Module &module) {
  SmallVector<BinaryOperator *,16> differences;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *difference=dyn_cast<BinaryOperator>(&instruction);
    if (difference && difference->getOpcode()==Instruction::Sub &&
        difference->getType()->isIntegerTy(64) &&
        pointer_bits(difference->getOperand(0)) &&
        pointer_bits(difference->getOperand(1)))
      differences.push_back(difference);
  }
  for (auto *difference:differences) {
    auto *type=difference->getType();
    auto *signature=FunctionType::get(type,{type,type},false);
    auto *operation=InlineAsm::get(signature,"$0 -= $2","=r,0,r",true);
    IRBuilder<> builder(difference);builder.SetCurrentDebugLocation(difference->getDebugLoc());
    auto *result=builder.CreateCall(operation,
        {difference->getOperand(0),difference->getOperand(1)},"pointer_difference");
    difference->replaceAllUsesWith(result);difference->eraseFromParent();
  }
  return differences.size();
}
// A PTR_TO_STACK operand cannot take part in any subtraction, in either
// position, and bounding the partner scalar does not help: the stock verifier
// refuses "scalar - stack_ptr", "stack_ptr - scalar" and "0 - stack_ptr"
// alike (adjust_ptr_min_max_vals and check_reg_sane_offset, verifier.c; every
// row loaded through the real kernel in
// kprog/results/otel-ptr-scalar-20261120). Two shapes carry such a
// subtraction into B.
//
// 1. Nested. OTel's is
//      %inner = sub i64 %s, %p        ; %p = ptrtoint (the simulator's frame)
//      %outer = sub i64 32, %inner    ; 32 - (s - p)
//      icmp ult %outer, 8
//    which is integer-identical to
//      %outer = add i64 (sub i64 32, %s), %p
//    - one subtraction of two scalars plus a pointer add, both legal.
// 2. Direct, %outer = sub i64 A, frame, with the frame as the subtrahend
//    (%1977 - %1976, OTel request 10 insn 1583). anchor_pointer_differences
//    keeps these on their own path, so the frame is still the operand there.
//
// The direct form leaves the subtraction in place and launders the frame
// instead, through a stack slot that ends up holding a scalar with the
// frame's exact bits. Nothing simpler works: a 32-bit store straight from
// the live stack-pointer register is refused ("invalid size of register
// spill"), any 32-bit ALU operation on the pointer is refused ("32-bit
// pointer arithmetic prohibited"), a 64-bit self-move keeps the pointer
// ("r1 = r1"), and "pointer -= pointer" is not expressible in IR. The one
// encoding the verifier takes is a 32-bit self-move of a 32-bit register,
// "w1 = w1" (bc), and that is what frame_scalar emits. Every step is exact
// in the 64-bit domain.
static unsigned eliminate_stack_pointer_subtractions(Module &module) {
  /* Decompose a value into the simulator's own frame plus a constant
   * offset: ptrtoint of an alloca, through constant adds and subtracts. */
  auto frame_offset=[](Value *value,int64_t &offset,AllocaInst **alloca) {
    offset=0;
    while (auto *operation=dyn_cast<Operator>(value)) {
      auto opcode=operation->getOpcode();
      if (opcode!=Instruction::Add && opcode!=Instruction::Sub) break;
      if (auto *constant=dyn_cast<ConstantInt>(operation->getOperand(1))) {
        offset+=(opcode==Instruction::Add?1:-1)*constant->getSExtValue();
        value=operation->getOperand(0);continue;
      }
      if (opcode!=Instruction::Add) break;
      if (auto *constant=dyn_cast<ConstantInt>(operation->getOperand(0))) {
        offset+=constant->getSExtValue();value=operation->getOperand(1);continue;
      }
      break;
    }
    auto *cast=dyn_cast<PtrToIntOperator>(value);
    if (alloca) *alloca=cast?dyn_cast<AllocaInst>(cast->getOperand(0)):nullptr;
    return cast && isa<AllocaInst>(cast->getOperand(0));
  };
  auto stack_pointer=[&](Value *value) { int64_t offset; return frame_offset(value,offset,nullptr); };
  /* The frame as a scalar, once per frame alloca, materialised in the entry
   * block so it dominates every use; the frame's own ptrtoint may sit in a
   * later block.
   *
   * The 64-bit store alone leaves the slot a stack-pointer slot, and a
   * 32-bit store straight from that register is refused ("invalid size of
   * register spill"), so the register has to stop being a pointer first. A
   * 32-bit ALU operation is refused on a pointer ("32-bit pointer arithmetic
   * prohibited"), a 64-bit self-move keeps the pointer, and every 32-bit
   * reload variant is refused, so the only encoding that drops it is the
   * 32-bit self-move "w1 = w1" (bc). clang does not emit it for a bare
   * trunc - it coalesces the value straight into the 32-bit store - and a
   * one-line form lets the backend pick a different register for the store,
   * so the move is written as explicit asm that names r1 for input, launder
   * and output, with r1 declared clobbered. */
  DenseMap<AllocaInst *,Value *> scalars;
  auto frame_scalar=[&](AllocaInst *alloca) -> Value * {
    auto found=scalars.find(alloca);
    if (found!=scalars.end()) return found->second;
    Function *function=alloca->getFunction();
    /* After every alloca of the entry block: the frame's own alloca must be
     * defined before its ptrtoint, and the launder must stay in the entry
     * block. */
    BasicBlock &entry=function->getEntryBlock();
    auto position=entry.begin();
    for (auto iterator=entry.begin();iterator!=entry.end();++iterator)
      if (isa<AllocaInst>(&*iterator)) position=std::next(iterator);
    IRBuilder<> builder(&*position);
    /* The laundering window is the frame's own first word, not a slot of its
     * own: an extra i64 alloca costs 16 bytes of frame (llc rounds the add),
     * and r3 runs at 504 of the 512-byte limit, so a new slot pushed it to
     * 520 and the stock verifier refused it ("invalid write to stack R10
     * off=-520 size=8"). The window is dead at that point -- the simulator's
     * first store has not run yet, and the emulated stack's bytes are
     * uninitialised either way -- and the four accesses below are volatile
     * and adjacent in one block with no call between them, so no use can
     * observe the borrowed word. The loaded bits equal the frame's own
     * ptrtoint exactly: the laundered move keeps the low 32 bits, which are
     * all the 32-bit store writes back. */
    Value *slot=alloca;
    Value *address=builder.CreatePtrToInt(alloca,builder.getInt64Ty(),"frame_address");
    builder.CreateStore(address,slot,true);
    /* The asm takes and returns 64 bits. Narrowing the pointer before the
     * asm is refused ("pointer arithmetic with <<= prohibited"), because a
     * 32-bit value of a stack pointer is built by shifting it; the asm output
     * is a scalar, so narrowing it afterwards is ordinary scalar arithmetic. */
    auto *signature=FunctionType::get(builder.getInt64Ty(),{builder.getInt64Ty()},false);
    auto *launder=InlineAsm::get(signature,"r1 = $1\012w1 = w1\012$0 = r1","=r,r,~{r1}",true);
    auto *low=builder.CreateCall(launder,{address});
    builder.CreateStore(builder.CreateTrunc(low,builder.getInt32Ty()),slot,true);
    auto *scalar=builder.CreateLoad(builder.getInt64Ty(),slot,true,"frame_scalar");
    scalars.insert({alloca,scalar});
    return scalar;
  };
  /* The same value's bits without the frame's pointer type. */
  auto scalar_of_frame=[&](Value *frame,Instruction *site) -> Value * {
    int64_t offset;AllocaInst *alloca=nullptr;
    if (!frame_offset(frame,offset,&alloca) || !alloca) return frame;
    Value *scalar=frame_scalar(alloca);
    if (!offset) return scalar;
    IRBuilder<> builder(site);builder.SetCurrentDebugLocation(site->getDebugLoc());
    return builder.CreateAdd(scalar,ConstantInt::get(scalar->getType(),offset),"frame_scalar_offset");
  };
  /* The verifier merges a PHI's register class over its arms, so a PHI is a
   * pointer when some arm is one; the arms that are still being merged
   * contribute nothing new (r11's minuend is the loop induction value
   * "%6214 = phi i64 [ %6209 = add i64 map_bits, 3992 ], [ %6476 = ... %6214 ]",
   * i.e. its own second arm). The simulator's lanes are the frame's
   * ptrtoint or a helper's returned pointer plus constant offsets, so every
   * minuend that reaches the subtraction as map_value is found this way (r5:
   * "%10122 = phi i64 [ %10119 = add i64 %10100, ptrtoint(ptr %10051) ], ..."). */
  SmallPtrSet<Value *,16> visiting;
  std::function<bool(Value *)> pointer_lane=[&](Value *value) {
    if (pointer_bits(value)) return true;
    if (!visiting.insert(value).second) return false;
    bool found=false;
    if (auto *phi=dyn_cast<PHINode>(value)) {
      for (Value *incoming:phi->incoming_values())
        if (pointer_lane(incoming)) { found=true; break; }
    } else if (auto *select=dyn_cast<SelectInst>(value)) {
      found=pointer_lane(select->getTrueValue()) || pointer_lane(select->getFalseValue());
    } else if (auto *operation=dyn_cast<Operator>(value)) {
      auto opcode=operation->getOpcode();
      if (opcode==Instruction::Add || opcode==Instruction::Sub)
        for (Value *operand:operation->operands())
          if (!isa<ConstantInt>(operand) && pointer_lane(operand)) { found=true; break; }
    }
    visiting.erase(value);
    return found;
  };
  /* A pointer-typed minuend is refused just as a frame operand is:
   * "math between map_value pointer and register with unbounded min value is
   * not allowed" (check_reg_sane_offset, verifier.c), and neither masking
   * nor bounding the partner helps, because the kernel reads the laundered
   * partner back as a full-width value (rows in
   * kprog/results/pointer-launder-20261122). What it accepts is the
   * minuend's own bits after the same borrow-the-frame-word round trip
   * frame_scalar uses: 64-bit store, "w1 = w1", 32-bit store, 64-bit load
   * (probe /tmp/ptrsub3.py "launder", loaded through the real kernel).
   * The word is saved and restored because, unlike the entry-block launder,
   * the emulated stack may already hold live bytes at the site. */
  auto launder_bits=[&](Value *value,Instruction *site,AllocaInst *alloca) -> Value * {
    IRBuilder<> builder(site);builder.SetCurrentDebugLocation(site->getDebugLoc());
    auto *i64=builder.getInt64Ty();
    auto *saved=builder.CreateLoad(i64,alloca,true,"launder_saved");
    builder.CreateStore(value,alloca,true);
    auto *signature=FunctionType::get(i64,{i64},false);
    auto *launder=InlineAsm::get(signature,"r1 = $1\012w1 = w1\012$0 = r1","=r,r,~{r1}",true);
    auto *low=builder.CreateCall(launder,{value});
    builder.CreateStore(builder.CreateTrunc(low,builder.getInt32Ty()),alloca,true);
    auto *bits=builder.CreateLoad(i64,alloca,true,"pointer_bits_scalar");
    builder.CreateStore(saved,alloca,true);
    return bits;
  };
  SmallVector<BinaryOperator *,16> outers;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *outer=dyn_cast<BinaryOperator>(&instruction);
    if (!outer || outer->getOpcode()!=Instruction::Sub ||
        !outer->getType()->isIntegerTy(64)) continue;
    /* After anchor_pointer_differences the difference is the tied asm. */
    auto *inner=dyn_cast<BinaryOperator>(outer->getOperand(1));
    auto *inner_call=dyn_cast<CallInst>(outer->getOperand(1));
    if (inner_call) {
      auto *assembly=dyn_cast<InlineAsm>(inner_call->getCalledOperand());
      if (!assembly || inner_call->arg_size()!=2 ||
          assembly->getAsmString()!="$0 -= $2") continue;
      const bool left=pointer_bits(inner_call->getArgOperand(0));
      const bool right=pointer_bits(inner_call->getArgOperand(1));
      /* The refused operand is the frame itself: ptrtoint of an alloca. A
       * plain register-valued pointer is a legal difference partner. */
      const bool stack_left=stack_pointer(inner_call->getArgOperand(0));
      const bool stack_right=stack_pointer(inner_call->getArgOperand(1));
      if (stack_left==stack_right || pointer_bits(outer->getOperand(0))) continue;
      outers.push_back(outer);
      continue;
    }
    if (!inner || inner->getOpcode()!=Instruction::Sub || !inner->hasOneUse() ||
        !inner->getType()->isIntegerTy(64)) continue;
    // inner = scalar - pointer, exactly one side pointer-derived.
    const bool left=pointer_bits(inner->getOperand(0));
    const bool right=pointer_bits(inner->getOperand(1));
    if (left==right) continue;
    if (pointer_bits(outer->getOperand(0))) continue;   // A must be scalar
    outers.push_back(outer);
  }
  for (auto *outer:outers) {
    Value *inner=outer->getOperand(1);
    Value *scalar_value=nullptr;Value *pointer_value=nullptr;Instruction *dead=nullptr;
    if (auto *inner_call=dyn_cast<CallInst>(inner)) {
      scalar_value=inner_call->getArgOperand(0);pointer_value=inner_call->getArgOperand(1);
      /* The stack pointer is the side that must leave the subtraction. */
      if (stack_pointer(scalar_value)) std::swap(scalar_value,pointer_value);
      dead=inner_call;
    } else {
      auto *inner_operator=cast<BinaryOperator>(inner);
      const bool pointer_left=stack_pointer(inner_operator->getOperand(0));
      pointer_value=pointer_left?inner_operator->getOperand(0):inner_operator->getOperand(1);
      scalar_value=pointer_left?inner_operator->getOperand(1):inner_operator->getOperand(0);
      dead=inner_operator;
    }
    IRBuilder<> builder(outer);builder.SetCurrentDebugLocation(outer->getDebugLoc());
    /* A - (s - p) = (A - s) + p, integer-identical in the 64-bit domain. */
    Value *scalar_difference=builder.CreateSub(outer->getOperand(0),scalar_value,"scalar_difference");
    Value *sum=builder.CreateAdd(scalar_difference,scalar_of_frame(pointer_value,outer),"scalar_plus_pointer");
    sum->takeName(outer);
    outer->replaceAllUsesWith(sum);outer->eraseFromParent();
    if (dead->use_empty()) dead->eraseFromParent();
  }
  /* The direct form: the frame is the subtrahend, and
   * anchor_pointer_differences skipped it because only one side is
   * pointer-derived. Keep the subtraction, replace its frame operand. */
  SmallVector<BinaryOperator *,16> directs;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *outer=dyn_cast<BinaryOperator>(&instruction);
    if (!outer || outer->getOpcode()!=Instruction::Sub ||
        !outer->getType()->isIntegerTy(64)) continue;
    if (!stack_pointer(outer->getOperand(1))) continue;
    directs.push_back(outer);
  }
  for (auto *outer:directs) {
    Value *frame=outer->getOperand(1);
    int64_t offset;AllocaInst *alloca=nullptr;
    frame_offset(frame,offset,&alloca);
    Value *scalar=scalar_of_frame(frame,outer);
    if (scalar!=frame) outer->setOperand(1,scalar);
    /* The minuend keeps map_value bits through the pass; laundering the
     * frame alone still asks the verifier to subtract from a pointer. */
    Value *minuend=outer->getOperand(0);
    if (alloca && pointer_lane(minuend) && !stack_pointer(minuend))
      outer->setOperand(0,launder_bits(minuend,outer,alloca));
  }
  /* The anchored differences that remain carry their operands as opaque
   * scalars to the runtime, but the operand list still names the frame, so
   * the backend emits the register pair the verifier refuses. Launder it. */
  unsigned anchored=0;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *call=dyn_cast<CallInst>(&instruction);
    if (!call) continue;
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (!assembly || call->arg_size()!=2 || assembly->getAsmString()!="$0 -= $2") continue;
    bool changed=false;
    int64_t offset;AllocaInst *alloca=nullptr;
    frame_offset(call->getArgOperand(1),offset,&alloca);
    for (unsigned index=0;index<2;++index) {
      Value *operand=call->getArgOperand(index);
      if (!stack_pointer(operand)) continue;
      call->setArgOperand(index,scalar_of_frame(operand,call));changed=true;
    }
    Value *minuend=call->getArgOperand(0);
    if (alloca && pointer_lane(minuend) && !stack_pointer(minuend)) {
      call->setArgOperand(0,launder_bits(minuend,call,alloca));changed=true;
    }
    if (changed) ++anchored;
  }
  return outers.size()+directs.size()+anchored;
}
static Value *origin(Value *value) {
  while (true) {
    if (auto *extension=dyn_cast<ZExtInst>(value)) { value=extension->getOperand(0); continue; }
    // Kernel context fields supply defined bits; a freeze preserves the
    // identity that the former tied register template already exposed here.
    if (auto *freeze=dyn_cast<FreezeInst>(value)) { value=freeze->getOperand(0); continue; }
    if (auto *call=dyn_cast<CallInst>(value))
      if (auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand()))
        if (tied_identity(call,assembly) ||
            (assembly->getAsmString()=="$0 = $0" &&
             assembly->getConstraintString()=="=w,0" && call->arg_size()==1 &&
             call->getType()->isIntegerTy(32) &&
             call->getArgOperand(0)->getType()==call->getType() &&
             !assembly->isAlignStack() && !assembly->canThrow())) {
          value=call->getArgOperand(0); continue;
        }
    return value;
  }
}
static bool kernel_context_cast(CallBase *call) {
  auto *function=call->getCalledFunction();
  return function && function->getName()=="bpf_cast_to_kern_ctx" &&
      function->isDeclaration() && function->getSection()==".ksyms" && call->arg_size()==1;
}
static bool field(Value *value,Function &function,int64_t offset,bool kernel=false,Instruction **read=nullptr) {
  value=origin(value);
  // The simulator's u32 memory template returns a wide register, truncated
  // at its original native instruction. Other truncations stay opaque.
  if (auto *truncate=dyn_cast<TruncInst>(value))
    if (truncate->getType()->isIntegerTy(32)) value=origin(truncate->getOperand(0));
  Value *address=nullptr;ConstantInt *displacement=nullptr;
  if (auto *load=dyn_cast<LoadInst>(value)) {
    if (!load->getType()->isIntegerTy(32)) return false;
    address=load->getPointerOperand();
  } else if (auto *call=dyn_cast<CallInst>(value)) {
    // The u32 memory template has two IR shapes: an inline-asm read and the
    // emitter's out-of-line kprog_x86_mem_load_fixed_into subprogram, which
    // returns the width-truncated value of the same read.
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (assembly) {
      if (call->arg_size()!=2 || !call->getType()->isIntegerTy(64) ||
          assembly->getAsmString()!="$0 = *(u32 *)($1 + $2)" ||
          assembly->getConstraintString()!="=r,r,i,~{memory}") return false;
      address=call->getArgOperand(0);
      displacement=dyn_cast<ConstantInt>(call->getArgOperand(1));
      if (!displacement) return false;
    } else if (auto *callee=call->getCalledFunction()) {
      if (callee->getName()!="kprog_x86_mem_load_fixed_into" || call->arg_size()!=4 ||
          !call->getType()->isIntegerTy(64)) return false;
      address=call->getArgOperand(1);
      displacement=dyn_cast<ConstantInt>(call->getArgOperand(2));
      if (!displacement) return false;
    } else return false;
  } else return false;
  if (!address->getType()->isPointerTy()) return false;
  int64_t actual=0;
  auto *base=origin(GetPointerBaseWithConstantOffset(origin(address),actual,function.getParent()->getDataLayout()));
  if (kernel) {
    auto *cast=dyn_cast<CallInst>(base);
    if (!cast || !kernel_context_cast(cast)) return false;
    base=origin(cast->getArgOperand(0));
  }
  APInt total(64,actual);
  if (displacement) total+=displacement->getValue().sextOrTrunc(64);
  bool matches=base==function.getArg(0) && total==APInt(64,offset);
  if (matches && read) *read=cast<Instruction>(value);
  return matches;
}
// The TC converter maps cb and tc_classid stores into sk_buff.cb. These
// exact templates preserve data, len and data_len; crossing stores keep
// their freshness barrier.
static bool skb_cb_store(CallBase *call,InlineAsm *assembly) {
  auto *function=call->getFunction();auto section=function->getSection();
  if (section!="classifier" && section!="tc" && !section.starts_with("tc/") &&
      !section.starts_with("cgroup_skb/")) return false;
  if (call->arg_size()==2 && call->getType()->isVoidTy() &&
      assembly->getConstraintString()=="r,r,~{memory}" &&
      assembly->getAsmString()=="*(u32 *)($0 + "+std::to_string(offsetof(__sk_buff,tc_classid))+") = $1" &&
      origin(call->getArgOperand(0))==function->getArg(0) &&
      call->getArgOperand(1)->getType()->isIntegerTy(64) &&
      !assembly->isAlignStack() && !assembly->canThrow()) return true;
  if (call->arg_size()!=6 || !call->getType()->isIntegerTy(64) ||
      assembly->getConstraintString()!="=&r,r,r,i,i,i,i,~{memory}" ||
      assembly->getAsmString()!="$0 = $2\n*(u8 *)($1 + $3) = $0\n$0 >>= 8\n*(u8 *)($1 + $4) = $0\n$0 >>= 8\n*(u8 *)($1 + $5) = $0\n$0 >>= 8\n*(u8 *)($1 + $6) = $0" ||
      origin(call->getArgOperand(0))!=function->getArg(0) ||
      assembly->isAlignStack() || assembly->canThrow()) return false;
  for (unsigned index=2;index<6;++index) {
    auto *offset=dyn_cast<ConstantInt>(call->getArgOperand(index));
    if (!offset || offset->getValue().getActiveBits()>64 ||
        offset->getZExtValue()<offsetof(__sk_buff,cb) ||
        offset->getZExtValue()>=offsetof(__sk_buff,cb)+sizeof(__sk_buff::cb)) return false;
  }
  return true;
}
// A fresh public packet span equals the captured head length only while no
// intervening operation can mutate the skb. Walk every predecessor path back
// to each field read, including loop backedges; private stores are irrelevant.
static bool current_headlen(Instruction *read,Instruction *compare) {
  SmallVector<std::pair<BasicBlock *,Instruction *>,16> pending{{compare->getParent(),compare}};
  SmallPtrSet<BasicBlock *,32> visited;
  while (!pending.empty()) {
    auto [block,limit]=pending.pop_back_val();
    if (!limit && !visited.insert(block).second) continue;
    auto it=limit?limit->getIterator():block->end();bool reached=false;
    while (it!=block->begin()) {
      auto &instruction=*--it;
      if (&instruction==read) { reached=true;break; }
      if (!instruction.mayWriteToMemory()) continue;
      // The private input marker supplies a choice and preserves skb state.
      if (auto *load=dyn_cast<LoadInst>(&instruction)) {
        auto *global=dyn_cast<GlobalVariable>(load->getPointerOperand());
        if (load->isVolatile() && !load->isAtomic() && load->getType()->isIntegerTy(64) &&
            global && global->isDeclaration() && global->getName()=="kprog_unspecified_input" &&
            global->getSection()==".ksyms") continue;
      }
      if (auto *store=dyn_cast<StoreInst>(&instruction))
        if (isa<AllocaInst>(getUnderlyingObject(store->getPointerOperand()))) continue;
      if (auto *call=dyn_cast<CallBase>(&instruction)) {
        if (call->onlyReadsMemory() || kernel_context_cast(call)) continue;
        // A lifetime marker writes no program memory, and the emitter's load
        // subprogram only reads its inputs, so neither intervenes.
        if (auto *intrinsic=dyn_cast<IntrinsicInst>(call))
          if (intrinsic->isLifetimeStartOrEnd()) continue;
        if (auto *callee=call->getCalledFunction())
          if (callee->getName()=="kprog_x86_mem_load_fixed_into") continue;
        if (auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand())) {
          auto text=assembly->getAsmString();
          if (tied_identity(call,assembly) || skb_cb_store(call,assembly) ||
              (text=="$0 = $0" && assembly->getConstraintString()=="=w,0") ||
              (assembly->getConstraintString()=="=r,r,i,~{memory}" &&
               (text=="$0 = *(u8 *)($1 + $2)" || text=="$0 = *(u16 *)($1 + $2)" ||
                text=="$0 = *(u32 *)($1 + $2)" || text=="$0 = *(u64 *)($1 + $2)"))) continue;
        }
      }
      return false;
    }
    if (reached) continue;
    if (pred_empty(block)) return false;
    for (auto *parent:predecessors(block)) pending.emplace_back(parent,nullptr);
  }
  return true;
}
// Context data reloads produce fresh verifier packet registers. Keep every
// original read (including its ordering effect), but share the proven equal
// SSA value while no context write can intervene. Bounds then describe the
// value used by the access instead of a discarded earlier packet register.
static unsigned reuse_packet_data_values(Module &module) {
  unsigned count=0;
  for (auto &function:module) {
    if (function.isDeclaration() || function.arg_empty() ||
        !function.getArg(0)->getType()->isPointerTy()) continue;
    auto section=function.getSection();int64_t data;
    if (section=="xdp" || section.starts_with("xdp/")) data=offsetof(xdp_md,data);
    else if (section=="classifier" || section=="tc" || section.starts_with("tc/") ||
             section.starts_with("cgroup_skb/")) data=offsetof(__sk_buff,data);
    else continue;
    SmallVector<CallInst *,16> reads,representatives;
    for (auto &instruction:instructions(function)) {
      auto *call=dyn_cast<CallInst>(&instruction);
      auto *assembly=call?dyn_cast<InlineAsm>(call->getCalledOperand()):nullptr;
      // A tied identity may carry a value captured before a context write;
      // only an actual field read can start a fresh interval.
      if (assembly && assembly->getAsmString()=="$0 = *(u32 *)($1 + $2)" &&
          assembly->getConstraintString()=="=r,r,i,~{memory}" &&
          call->getType()->isIntegerTy(64) && field(call,function,data)) reads.push_back(call);
    }
    for (auto *read:reads) {
      bool reused=false;
      for (auto *source:representatives) if (current_headlen(source,read)) {
        if (!read->use_empty()) { read->replaceAllUsesWith(source);++count; }
        reused=true;break;
      }
      if (!reused) representatives.push_back(read);
    }
  }
  return count;
}
// The frozen TC converter maps public tc_classid/u32 to the same qdisc
// overlay field (sk_buff.cb40 + qdisc_skb_cb.tc_classid6), with a u16 store.
// Use that public accessor for B; P's original physical store is untouched.
static unsigned canonical_tc_class_stores(Module &module) {
  unsigned count=0;
  for (auto &function:module) {
    if (function.isDeclaration() || function.arg_empty() ||
        !function.getArg(0)->getType()->isPointerTy()) continue;
    auto section=function.getSection();
    if (section!="classifier" && section!="tc" && !section.starts_with("tc/")) continue;
    SmallVector<CallInst *,4> stores;
    for (auto &instruction:instructions(function)) {
      auto *call=dyn_cast<CallInst>(&instruction);
      if (!call || !call->getType()->isVoidTy() || call->arg_size()!=2 ||
          !call->getArgOperand(0)->getType()->isPointerTy() ||
          !call->getArgOperand(1)->getType()->isIntegerTy(64)) continue;
      auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
      if (!assembly || assembly->getAsmString()!="*(u16 *)($0 + 0) = $1" ||
          assembly->getConstraintString()!="r,r,~{memory}" ||
          !assembly->hasSideEffects() || assembly->isAlignStack() || assembly->canThrow()) continue;
      int64_t offset=0;
      auto *base=origin(GetPointerBaseWithConstantOffset(origin(call->getArgOperand(0)),
          offset,module.getDataLayout()));
      auto *cast=dyn_cast<CallInst>(base);
      if ((offset==46 || offset==124) && cast && kernel_context_cast(cast) &&
          origin(cast->getArgOperand(0))==function.getArg(0)) stores.push_back(call);
    }
    for (auto *store:stores) {
      int64_t so=0; GetPointerBaseWithConstantOffset(origin(store->getArgOperand(0)),so,module.getDataLayout());
      auto *signature=FunctionType::get(store->getType(),
          {function.getArg(0)->getType(),store->getArgOperand(1)->getType()},false);
      std::string text=so==124 ? "*(u32 *)($0 + "+std::to_string(offsetof(__sk_buff,queue_mapping))+") = $1"
                               : "*(u32 *)($0 + "+std::to_string(offsetof(__sk_buff,tc_classid))+") = $1";
      auto *operation=InlineAsm::get(signature,text,"r,r,~{memory}",true);
      IRBuilder<> builder(store);builder.SetCurrentDebugLocation(store->getDebugLoc());
      builder.CreateCall(operation,{function.getArg(0),store->getArgOperand(1)});
      store->eraseFromParent();++count;
    }
  }
  return count;
}
static Value *context_origin(Value *value) {
  while (auto *call=dyn_cast<CallInst>(value)) {
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (!assembly || !tied_identity(call,assembly)) break;
    value=call->getArgOperand(0);
  }
  return value;
}
// Tracing contexts contain scalar register values. Keep the original context
// operand and put a proven constant displacement in the memory instruction.
// An opaque identity used by the simulator can otherwise make LLVM allocate
// ctx+K as a separate pointer, which the stock verifier treats differently.
static unsigned canonical_context_loads(Module &module) {
  unsigned count=0;
  for (auto &function:module) {
    if (function.isDeclaration() || function.arg_empty() ||
        !function.getArg(0)->getType()->isPointerTy()) continue;
    auto section=function.getSection();
    if (section!="kprobe" && !section.starts_with("kprobe/")) continue;
    SmallVector<LoadInst *,16> loads;
    for (auto &instruction:instructions(function))
      if (auto *load=dyn_cast<LoadInst>(&instruction)) loads.push_back(load);
    for (auto *load:loads) {
      if (load->isAtomic() || !load->getType()->isIntegerTy()) continue;
      unsigned width=load->getType()->getIntegerBitWidth();
      if (width!=8 && width!=16 && width!=32 && width!=64) continue;
      int64_t offset=0;
      auto *base=GetPointerBaseWithConstantOffset(context_origin(load->getPointerOperand()),
          offset,module.getDataLayout());
      if (context_origin(base)!=function.getArg(0) || offset < -32768 || offset > 32767) continue;
      std::string displacement=offset<0?" - "+std::to_string(-offset):" + "+std::to_string(offset);
      std::string assembly="$0 = *(u"+std::to_string(width)+" *)($1"+displacement+")";
      auto *wide=Type::getInt64Ty(module.getContext());
      auto *signature=FunctionType::get(wide,{function.getArg(0)->getType()},false);
      auto *operation=InlineAsm::get(signature,assembly,"=r,r,~{memory}",load->isVolatile());
      IRBuilder<> builder(load);builder.SetCurrentDebugLocation(load->getDebugLoc());
      Value *result=builder.CreateCall(operation,{function.getArg(0)},"ctx_load");
      if (width!=64) result=builder.CreateTrunc(result,load->getType());
      load->replaceAllUsesWith(result);load->eraseFromParent();++count;
    }
  }
  return count;
}
// Private unknown choices have no observable read effect. Dropping an unused
// choice projects the same possible observable states; live reads stay distinct.
static unsigned remove_unused_private_inputs(Module &module) {
  SmallVector<LoadInst *,16> unused;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *load=dyn_cast<LoadInst>(&instruction);
    if (!load || !load->use_empty() || !load->isVolatile() || load->isAtomic() ||
        !load->getType()->isIntegerTy(64)) continue;
    int64_t offset=0;
    auto *base=GetPointerBaseWithConstantOffset(load->getPointerOperand(),offset,module.getDataLayout());
    auto *global=dyn_cast<GlobalVariable>(base);
    if (offset==0 && global && global->isDeclaration() &&
        global->getName()=="kprog_unspecified_input" && global->getSection()==".ksyms")
      unused.push_back(load);
  }
  for (auto *load:unused) load->eraseFromParent();
  return unused.size();
}
// Variable-location intrinsics have no execution effect. Constant folding of a
// large simulated block can leave millions of adjacent dbg.value instructions;
// LLVM18's getStableDebugLoc scans to the next non-debug instruction for each.
// Keep instruction locations, function/type/global metadata and BTF, but omit
// these variable updates before B machine-code selection. The checked native
// compiler still receives the unchanged original frontend IR.
static unsigned remove_debug_variable_intrinsics(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &block:function)
    for (auto it=block.begin();it!=block.end();) {
      auto &instruction=*it++;
      if (isa<DbgVariableIntrinsic>(instruction)) {
        instruction.eraseFromParent();++count;
      }
    }
  return count;
}
// A PHI incoming value is observed on its own edge. For example, a preserved
// sign flag on a pointer==NULL edge is exactly zero. Fold that expression at
// the PHI so the BPF backend can discard arithmetic on the nullable pointer.
// Other edges retain their original expression and the comparison stays live.
static unsigned fold_equality_edges(Module &module) {
  unsigned count=0;
  const SimplifyQuery query(module.getDataLayout());
  for (auto &function:module) for (auto &block:function) for (auto &phi:block.phis()) {
    for (unsigned index=0;index<phi.getNumIncomingValues();++index) {
      auto *branch=dyn_cast<BranchInst>(phi.getIncomingBlock(index)->getTerminator());
      if (!branch || !branch->isConditional() ||
          branch->getSuccessor(0)==branch->getSuccessor(1)) continue;
      auto *compare=dyn_cast<ICmpInst>(branch->getCondition());
      if (!compare || !compare->isEquality()) continue;
      unsigned edge=compare->getPredicate()==ICmpInst::ICMP_EQ?0:1;
      if (branch->getSuccessor(edge)!=&block) continue;
      Value *value=compare->getOperand(0),*constant=compare->getOperand(1);
      if (isa<Constant>(value)) std::swap(value,constant);
      if (!isa<ConstantInt>(constant) && !isa<ConstantPointerNull>(constant)) continue;
      auto *incoming=phi.getIncomingValue(index);
      auto *folded=simplifyWithOpReplaced(incoming,value,constant,query,false);
      if (folded && isa<Constant>(folded) && folded!=incoming) {
        phi.setIncomingValue(index,folded);++count;
      }
    }
  }
  return count;
}
// A loop re-entry reloads a scalar from the map and tests a 32-bit
// zero-extended copy of it against the iteration bound, while the merge PHI
// carries the unprojected 64-bit value into the scaled access. The verifier
// narrows the register the guard compares, never the one the scaling uses,
// so the offset is unbounded on the re-entry path (OTel request 11, insn 301
// after the reload at insn 315: "R1 unbounded memory access" at insn 301).
// Carry the projection onto the arm itself: the arm is then exactly the
// guarded value, and the widening stays on the narrowed register. Every real
// use of such a PHI reads only its low 32 bits, so the carried value is
// unchanged for every consumer.
static bool low_word_mask(BinaryOperator *operation) {
  if (operation->getOpcode()!=Instruction::And) return false;
  for (unsigned side=0;side<2;++side) {
    auto *mask=dyn_cast<ConstantInt>(operation->getOperand(side));
    if (mask && mask->getZExtValue()==0xffffffffu) return true;
  }
  return false;
}
static unsigned carry_guard_projections(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &block:function) for (auto &phi:block.phis()) {
    auto *type=dyn_cast<IntegerType>(phi.getType());
    if (!type || type->getBitWidth()<=32) continue;
    bool narrow=true;
    for (auto &use:phi.uses()) {
      auto *instruction=dyn_cast<Instruction>(use.getUser());
      if (!instruction) { narrow=false;break; }
      if (isa<DbgInfoIntrinsic>(instruction)) continue;
      bool low=false;
      if (auto *truncate=dyn_cast<TruncInst>(instruction))
        low=truncate->getDestTy()->isIntegerTy(32);
      else if (auto *operation=dyn_cast<BinaryOperator>(instruction))
        low=low_word_mask(operation);
      if (!low) { narrow=false;break; }
    }
    if (!narrow) continue;
    for (unsigned index=0;index<phi.getNumIncomingValues();++index) {
      Value *arm=phi.getIncomingValue(index);
      auto *incoming=phi.getIncomingBlock(index);
      auto *branch=dyn_cast<BranchInst>(incoming->getTerminator());
      if (!branch || !branch->isConditional() ||
          (branch->getSuccessor(0)!=&block && branch->getSuccessor(1)!=&block)) continue;
      auto *compare=dyn_cast<ICmpInst>(branch->getCondition());
      if (!compare) continue;
      Value *guarded=nullptr;
      for (unsigned side=0;side<2 && !guarded;++side) {
        if (!isa<ConstantInt>(compare->getOperand(1-side))) continue;
        auto *operand=compare->getOperand(side);
        if (auto *operation=dyn_cast<BinaryOperator>(origin(operand))) {
          if (!low_word_mask(operation)) continue;
          for (unsigned field_index=0;field_index<2;++field_index)
            if (operation->getOperand(field_index)==arm) guarded=operand;
        } else if (auto *truncate=dyn_cast<TruncInst>(origin(operand))) {
          if (truncate->getOperand(0)==arm) guarded=operand;
        }
      }
      /* The carried value has to be the very register the compare narrows,
       * and a value defined before the terminator is not narrowed, so a
       * widening would have to be inserted on the edge where a PHI incoming
       * value cannot live. Same width only. */
      if (!guarded || guarded==arm || guarded->getType()!=phi.getType()) continue;
      phi.setIncomingValue(index,guarded);++count;
    }
  }
  return count;
}
// At a known interval boundary, equality is an ordered scalar predicate:
// x>=K makes x==K equivalent to x<=K. Its false edge then carries x>K,
// allowing the existing packet-bound lowering to describe both outcomes.
static ICmpInst::Predicate ordered_boundary(ICmpInst *compare,DominatorTree &tree) {
  auto predicate=compare->getPredicate();
  auto *node=tree.getNode(compare->getParent());
  if (!compare->isEquality() || !node) return predicate;
  auto *constant=cast<ConstantInt>(compare->getOperand(1));
  for (node=node->getIDom();node;node=node->getIDom()) {
    auto *branch=dyn_cast<BranchInst>(node->getBlock()->getTerminator());
    if (!branch || !branch->isConditional() ||
        branch->getSuccessor(0)==branch->getSuccessor(1)) continue;
    auto *guard=dyn_cast<ICmpInst>(branch->getCondition());
    if (!guard || guard->getOperand(0)->getType()!=compare->getOperand(0)->getType() ||
        origin(guard->getOperand(0))!=origin(compare->getOperand(0))) continue;
    auto *bound=dyn_cast<ConstantInt>(guard->getOperand(1));
    if (!bound) continue;
    for (unsigned edge=0;edge<2;++edge) {
      if (!tree.dominates(BasicBlockEdge(node->getBlock(),branch->getSuccessor(edge)),
                          compare->getParent())) continue;
      auto relation=edge?guard->getInversePredicate():guard->getPredicate();
      auto range=ConstantRange::makeExactICmpRegion(relation,bound->getValue());
      auto point=ConstantRange(constant->getValue());
      bool equal=predicate==ICmpInst::ICMP_EQ;
      if (range.icmp(ICmpInst::ICMP_UGE,point))
        return equal?ICmpInst::ICMP_ULE:ICmpInst::ICMP_UGT;
      if (range.icmp(ICmpInst::ICMP_ULE,point))
        return equal?ICmpInst::ICMP_UGE:ICmpInst::ICMP_ULT;
    }
  }
  return predicate;
}
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext context;SMDiagnostic error;auto module=parseIRFile(Input,error,context);
  if (!module) { error.print(argv[0],errs());return 1; }
  unsigned externs=restore_map_extern_debug_info(*module);
  unsigned constants=fold_constant_identities(*module);
  unsigned live_identities=normalize_live_integer_identities(*module);
  unsigned memory_barriers=remove_empty_memory_barriers(*module);
  unsigned helper_memory=describe_helper_memory(*module);
  unsigned private_stack=normalize_private_stack_accesses(*module);
  unsigned unused=remove_unused_private_inputs(*module);
  unsigned contexts=canonical_context_loads(*module);
  unsigned debug_variables=remove_debug_variable_intrinsics(*module);
  unsigned equality_edges=fold_equality_edges(*module);
  unsigned guard_projections=carry_guard_projections(*module);
  unsigned class_stores=canonical_tc_class_stores(*module);
  unsigned count=0,stale_headlen=0;
  for (auto &function:*module) {
    if (function.isDeclaration() || function.arg_empty()) continue;
    auto section=function.getSection();int64_t data,end;
    if (section=="xdp" || section.starts_with("xdp/")) {
      data=offsetof(xdp_md,data);end=offsetof(xdp_md,data_end);
    } else if (section=="tc" || section=="classifier" || section.starts_with("tc/") || section.starts_with("cgroup_skb/")) {
      data=offsetof(__sk_buff,data);end=offsetof(__sk_buff,data_end);
    } else continue;
    SmallVector<ICmpInst *,8> comparisons;
    for (auto &instruction:instructions(function)) if (auto *compare=dyn_cast<ICmpInst>(&instruction)) comparisons.push_back(compare);
    // Consult original branch guards before their pointer-bound expansion.
    std::stable_partition(comparisons.begin(),comparisons.end(),
        [](ICmpInst *compare) { return compare->isEquality(); });
    DominatorTree dominators(function);
    for (auto *compare:comparisons) {
      auto *span=compare->getOperand(0);
      auto *difference=dyn_cast<BinaryOperator>(origin(span));
      auto *constant=dyn_cast<ConstantInt>(compare->getOperand(1));
      if (!difference || difference->getOpcode()!=Instruction::Sub || !constant) continue;
      // The one frozen kernel's sk_buff u32 len/data_len fields are112/116
      // (the target vmlinux.h layout is checked by the regression recipe).
      Instruction *length_read=nullptr,*nonlinear_read=nullptr;
      bool headlen=data==offsetof(__sk_buff,data) &&
          (constant->getType()->isIntegerTy(32) || constant->getType()->isIntegerTy(64)) &&
          difference->getType()->isIntegerTy(32) &&
          field(difference->getOperand(0),function,112,true,&length_read) &&
          field(difference->getOperand(1),function,116,true,&nonlinear_read);
      if (headlen && (!current_headlen(length_read,compare) || !current_headlen(nonlinear_read,compare))) {
        ++stale_headlen;continue;
      }
      if (!headlen && (!constant->getType()->isIntegerTy(64) || !difference->getType()->isIntegerTy(64) ||
          !field(difference->getOperand(0),function,end) || !field(difference->getOperand(1),function,data))) continue;
      auto predicate=ordered_boundary(compare,dominators);auto size=constant->getValue();
      bool signed_compare=ICmpInst::isSigned(predicate);
      if (signed_compare && size.isNegative()) continue;
      bool inverse=predicate==ICmpInst::ICMP_SGE || predicate==ICmpInst::ICMP_UGE || predicate==ICmpInst::ICMP_SGT || predicate==ICmpInst::ICMP_UGT;
      bool inclusive=predicate==ICmpInst::ICMP_SLE || predicate==ICmpInst::ICMP_ULE || predicate==ICmpInst::ICMP_SGT || predicate==ICmpInst::ICMP_UGT;
      if (!inverse && !inclusive && predicate!=ICmpInst::ICMP_SLT && predicate!=ICmpInst::ICMP_ULT) continue;
      if (inclusive) { if (size.isMaxValue()) continue; ++size; }
      IRBuilder<> builder(compare);builder.SetCurrentDebugLocation(compare->getDebugLoc());
      auto *start=difference->getOperand(1),*finish=difference->getOperand(0);
      if (headlen) {
        auto *wide=Type::getInt64Ty(context);
        auto *signature=FunctionType::get(wide,{function.getArg(0)->getType(),wide},false);
        auto *operation=InlineAsm::get(signature,"$0 = *(u32 *)($1 + $2)","=r,r,i,~{memory}",true);
        start=builder.CreateCall(operation,{function.getArg(0),ConstantInt::get(wide,data)},"packet_data");
        finish=builder.CreateCall(operation,{function.getArg(0),ConstantInt::get(wide,end)},"packet_end");
      }
      auto *bound=builder.CreateAdd(start,ConstantInt::get(context,size.zextOrTrunc(64)),"packet_bound");
      // The original scalar predicate retains wrap/overflow behavior. On an
      // ordered packet span <=PTRDIFF_MAX, accepting it already implies
      // start+K<=end. Express that same fact in the verifier's pointer form;
      // no numeric comparison of a packet pointer against ULONG_MAX is needed.
      auto *original=builder.CreateICmp(predicate,span,constant);
      auto *original_reject=inverse?builder.CreateNot(original):original;
      auto *reject=builder.CreateOr(original_reject,builder.CreateICmpUGT(bound,finish));
      compare->replaceAllUsesWith(inverse?builder.CreateNot(reject):reject);
      compare->eraseFromParent();++count;
    }
  }
  unsigned packet_values=reuse_packet_data_values(*module);
  unsigned pointer_differences=anchor_pointer_differences(*module);
  unsigned stack_pointer_subtractions=eliminate_stack_pointer_subtractions(*module);
  if (verifyModule(*module,&errs())) return 1;
  std::error_code ec;ToolOutputFile output(Output,ec,sys::fs::OF_None);
  if (ec) { errs()<<ec.message()<<'\n';return 1; }
  WriteBitcodeToFile(*module,output.os());output.keep();output.os().flush();
  if (output.os().has_error()) { errs()<<"write packet bounds IR failed\n";return 1; }
  errs()<<"packet length predicates lowered="<<count<<'\n';
  errs()<<"head length predicates with intervening writes="<<stale_headlen<<'\n';
  errs()<<"packet data reload values unified="<<packet_values<<'\n';
  errs()<<"TC class stores canonicalized="<<class_stores<<'\n';
  errs()<<"map extern debug declarations restored="<<externs<<'\n';
  errs()<<"unused private inputs removed="<<unused<<'\n';
  errs()<<"constant context loads canonicalized="<<contexts<<'\n';
  errs()<<"debug variable intrinsics removed="<<debug_variables<<'\n';
  errs()<<"equality-edge PHI expressions folded="<<equality_edges<<'\n';
  errs()<<"tied integer constant identities folded="<<constants<<'\n';
  errs()<<"guard projections carried onto PHI arms="<<guard_projections<<'\n';
  errs()<<"live integer identities normalized="<<live_identities<<'\n';
  errs()<<"empty memory barriers removed="<<memory_barriers<<'\n';
  errs()<<"helper memory contracts described="<<helper_memory<<'\n';
  errs()<<"private stack accesses normalized="<<private_stack<<'\n';
  errs()<<"stack pointer subtractions eliminated="<<stack_pointer_subtractions<<'\n';
  errs()<<"pointer differences anchored="<<pointer_differences<<'\n';
}
