// SPDX-License-Identifier: MIT
// Native input follows the eBPF integer quotient/remainder semantics.
#include <llvm/IR/Constants.h>
#include <llvm/IR/DebugInfoMetadata.h>
#include <llvm/Analysis/ValueTracking.h>
#include <llvm/BinaryFormat/Dwarf.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/TargetParser/Triple.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/SROA.h>
#include <llvm/Transforms/Scalar/SimplifyCFG.h>

namespace {
struct NativeDivision : llvm::PassInfoMixin<NativeDivision> {
    static bool isRequired() { return true; }
    llvm::PreservedAnalyses run(llvm::Function &function,
                               llvm::FunctionAnalysisManager &) {
        llvm::SmallVector<llvm::BinaryOperator *> divisions;
        for (auto &block : function)
            for (auto &instruction : block)
                if (auto *op = llvm::dyn_cast<llvm::BinaryOperator>(&instruction))
                    if (op->getOpcode() == llvm::Instruction::UDiv ||
                        op->getOpcode() == llvm::Instruction::SDiv ||
                        op->getOpcode() == llvm::Instruction::URem ||
                        op->getOpcode() == llvm::Instruction::SRem)
                        divisions.push_back(op);
        for (size_t cursor = 0; cursor < divisions.size(); ++cursor) {
            auto *op = divisions[cursor];
            auto *type = op->getType();
            if (auto *vector = llvm::dyn_cast<llvm::FixedVectorType>(type)) {
                llvm::IRBuilder<> scalarize(op);
                llvm::Value *result = llvm::PoisonValue::get(type);
                for (unsigned lane = 0; lane < vector->getNumElements(); ++lane) {
                    auto *left = scalarize.CreateExtractElement(op->getOperand(0), lane);
                    auto *right = scalarize.CreateExtractElement(op->getOperand(1), lane);
                    auto *element = llvm::BinaryOperator::Create(op->getOpcode(),
                        left, right, "native.div.lane", op);
                    divisions.push_back(element);
                    result = scalarize.CreateInsertElement(result, element, lane);
                }
                op->replaceAllUsesWith(result);
                op->eraseFromParent();
                continue;
            }
            auto *dividend = op->getOperand(0);
            auto *divisor = op->getOperand(1);
            bool sign = op->getOpcode() == llvm::Instruction::SDiv ||
                        op->getOpcode() == llvm::Instruction::SRem;
            bool remainder = op->getOpcode() == llvm::Instruction::URem ||
                             op->getOpcode() == llvm::Instruction::SRem;
            // Defined constant divisors retain LLVM's strength reduction.
            if (auto *constant = llvm::dyn_cast<llvm::ConstantInt>(divisor))
                if (!constant->isZero() && (!sign || !constant->isMinusOne()))
                    continue;
            llvm::IRBuilder<> before(op);
            auto *zero = llvm::Constant::getNullValue(type);
            auto *is_zero = before.CreateICmpEQ(divisor, zero);
            llvm::Value *exception = is_zero;
            llvm::Value *exception_result = remainder ? dividend : zero;
            if (sign) {
                auto *minimum = llvm::ConstantInt::get(type,
                    llvm::APInt::getSignedMinValue(type->getScalarSizeInBits()));
                auto *minus_one = llvm::Constant::getAllOnesValue(type);
                auto *overflow = before.CreateAnd(
                    before.CreateICmpEQ(dividend, minimum),
                    before.CreateICmpEQ(divisor, minus_one));
                exception = before.CreateOr(is_zero, overflow);
                exception_result = before.CreateSelect(is_zero,
                    remainder ? dividend : zero, remainder ? zero : dividend);
            }
            auto *entry = op->getParent();
            auto *continuation = entry->splitBasicBlock(op, "native.div.join");
            auto *arithmetic = llvm::BasicBlock::Create(function.getContext(),
                "native.div.nonzero", &function, continuation);
            entry->getTerminator()->eraseFromParent();
            before.SetInsertPoint(entry);
            before.CreateCondBr(exception, continuation, arithmetic);
            llvm::IRBuilder<> calculate(arithmetic);
            llvm::Value *value;
            if (llvm::Triple(function.getParent()->getTargetTriple()).isX86() &&
                type->isIntegerTy() && type->getIntegerBitWidth() <= 64) {
                auto *word = type->getIntegerBitWidth() <= 32 ?
                    calculate.getInt32Ty() : calculate.getInt64Ty();
                auto *left = calculate.CreateIntCast(dividend, word, sign);
                auto *right = calculate.CreateIntCast(divisor, word, sign);
                auto *results = llvm::StructType::get(word, word);
                auto *signature = llvm::FunctionType::get(results, {word, word}, false);
                const char *assembly = sign ?
                    (word->isIntegerTy(64) ? "cqto; idivq $3" : "cltd; idivl $3") :
                    (word->isIntegerTy(64) ? "xorl %edx, %edx; divq $3" :
                                            "xorl %edx, %edx; divl $3");
                auto *divide = llvm::InlineAsm::get(signature, assembly,
                    "=&{ax},=&{dx},0,r,~{flags}", true);
                auto *pair = calculate.CreateCall(divide, {left, right});
                value = calculate.CreateIntCast(calculate.CreateExtractValue(pair,
                    remainder ? 1 : 0), type, sign);
            } else {
                value = calculate.CreateBinOp(op->getOpcode(), dividend, divisor);
            }
            calculate.CreateBr(continuation);
            auto *result = llvm::PHINode::Create(type, 2, "native.div.result", op);
            result->addIncoming(exception_result, entry);
            result->addIncoming(value, arithmetic);
            op->replaceAllUsesWith(result);
            op->eraseFromParent();
        }
        return divisions.empty() ? llvm::PreservedAnalyses::all() :
                                   llvm::PreservedAnalyses::none();
    }
};

#if defined(K_BPF_ARRAY_VALUE_OFFSET) && defined(K_BPF_ARRAY_ELEM_SIZE_OFFSET) && \
    defined(K_BPF_ARRAY_INDEX_MASK_OFFSET) && defined(K_BPF_MAP_MAX_ENTRIES_OFFSET)
/* Kernel layout enters the producer when this plugin is compiled. Native P
 * keeps ordinary map-symbol relocations; the kernel emits its submitted copy.
 * BTF C map types select the same array operation as map_gen_lookup. */
struct NativeArrayLookups : llvm::PassInfoMixin<NativeArrayLookups> {
    static bool isRequired() { return true; }

    static bool isLookup(llvm::CallInst &call) {
        if (call.arg_size() != 2 || !call.getType()->isPointerTy())
            return false;
        auto *target = llvm::dyn_cast<llvm::Operator>(call.getCalledOperand());
        if (!target || target->getOpcode() != llvm::Instruction::IntToPtr)
            return false;
        auto *id = target->getOperand(0);
        if (auto *barrier = llvm::dyn_cast<llvm::CallInst>(id)) {
            auto *assembly = llvm::dyn_cast<llvm::InlineAsm>(barrier->getCalledOperand());
            if (!assembly || !assembly->getAsmString().empty() || barrier->arg_empty())
                return false;
            // Read/write output constraints tie the helper number to an input.
            // Clang places that input after the explicit helper arguments.
            const auto constraints = assembly->ParseConstraints();
            llvm::Value *tied = nullptr;
            if (!constraints.empty() && !constraints[0].isIndirect &&
                !constraints[0].isMultipleAlternative) {
                unsigned argument = 0;
                for (unsigned index = 0; index < constraints.size(); ++index) {
                    if (!constraints[index].hasArg())
                        continue;
                    if (constraints[0].MatchingInput == static_cast<int>(index) &&
                        !constraints[index].isMultipleAlternative)
                        tied = barrier->getArgOperand(argument);
                    ++argument;
                }
            }
            id = tied;
        }
        auto *number = llvm::dyn_cast_or_null<llvm::ConstantInt>(id);
        return number && number->equalsInt(1);
    }

    static unsigned mapType(const llvm::GlobalVariable &map) {
        llvm::SmallVector<llvm::DIGlobalVariableExpression *> debug;
        map.getDebugInfo(debug);
        for (auto *expression : debug) {
            llvm::DIType *type = expression->getVariable()->getType();
            while (auto *alias = llvm::dyn_cast_or_null<llvm::DIDerivedType>(type))
                type = alias->getBaseType();
            auto *record = llvm::dyn_cast_or_null<llvm::DICompositeType>(type);
            if (!record)
                continue;
            for (auto *element : record->getElements()) {
                auto *member = llvm::dyn_cast<llvm::DIDerivedType>(element);
                if (!member || member->getName() != "type")
                    continue;
                auto *pointer = llvm::dyn_cast_or_null<llvm::DIDerivedType>(member->getBaseType());
                if (!pointer || pointer->getTag() != llvm::dwarf::DW_TAG_pointer_type)
                    continue;
                auto *array = llvm::dyn_cast_or_null<llvm::DICompositeType>(pointer->getBaseType());
                if (!array || array->getTag() != llvm::dwarf::DW_TAG_array_type)
                    continue;
                for (auto *dimension : array->getElements()) {
                    auto *range = llvm::dyn_cast<llvm::DISubrange>(dimension);
                    if (range)
                        if (auto *count = range->getCount().dyn_cast<llvm::ConstantInt *>())
                            if (count->equalsInt(2) || count->equalsInt(6))
                                return count->getZExtValue();
                }
            }
        }
        return 0;
    }

    llvm::PreservedAnalyses run(llvm::Module &module, llvm::ModuleAnalysisManager &) {
        llvm::SmallVector<llvm::CallInst *> lookups;
        for (auto &function : module)
            for (auto &block : function)
                for (auto &instruction : block)
                    if (auto *call = llvm::dyn_cast<llvm::CallInst>(&instruction)) {
                        if (!isLookup(*call))
                            continue;
                        auto *map = llvm::dyn_cast<llvm::GlobalVariable>(
                            llvm::getUnderlyingObject(call->getArgOperand(0)));
                        if (map && map->getSection() == ".maps" && mapType(*map))
                            lookups.push_back(call);
                    }
        for (auto *call : lookups) {
            auto *global = llvm::cast<llvm::GlobalVariable>(
                llvm::getUnderlyingObject(call->getArgOperand(0)));
            const bool per_cpu = mapType(*global) == 6;
            llvm::IRBuilder<> before(call);
            before.SetCurrentDebugLocation(call->getDebugLoc());
            auto *pointer = before.getPtrTy();
            auto *opaque = llvm::InlineAsm::get(llvm::FunctionType::get(pointer, {pointer}, false),
                "", "=r,0,~{memory}", true);
            // The ELF symbol becomes the kernel map address at binding time;
            // its original C declaration describes metadata, rather than storage.
            auto *map = before.CreateCall(opaque, {call->getArgOperand(0)}, "native.map.address");
            auto field = [&](unsigned offset) {
                return before.CreateLoad(before.getInt32Ty(),
                    before.CreateGEP(before.getInt8Ty(), map, before.getInt64(offset)));
            };
            auto *index = before.CreateLoad(before.getInt32Ty(), call->getArgOperand(1));
            auto *maximum = field(K_BPF_MAP_MAX_ENTRIES_OFFSET);
            auto *entry = call->getParent();
            auto *join = entry->splitBasicBlock(call, "native.array.join");
            auto *value = llvm::BasicBlock::Create(module.getContext(), "native.array.value",
                                                 entry->getParent(), join);
            entry->getTerminator()->eraseFromParent();
            before.SetInsertPoint(entry);
            before.CreateCondBr(before.CreateICmpULT(index, maximum), value, join);
            before.SetInsertPoint(value);
            auto *mask = field(K_BPF_ARRAY_INDEX_MASK_OFFSET);
            auto *stride = per_cpu ? static_cast<llvm::Value *>(before.getInt32(8)) : field(K_BPF_ARRAY_ELEM_SIZE_OFFSET);
            auto *offset = before.CreateAdd(before.getInt64(K_BPF_ARRAY_VALUE_OFFSET),
                before.CreateMul(before.CreateZExt(before.CreateAnd(index, mask), before.getInt64Ty()),
                                 before.CreateZExt(stride, before.getInt64Ty())));
            auto *result = before.CreateGEP(before.getInt8Ty(), map, offset);
            if (per_cpu) {
                auto *slot = before.CreateLoad(pointer, result);
                auto *signature = llvm::FunctionType::get(pointer, {pointer}, false);
                auto *this_cpu = llvm::ConstantExpr::getIntToPtr(before.getInt64(154), pointer);
                result = before.CreateCall(signature, this_cpu, {slot});
            }
            before.CreateBr(join);
            auto *merged = llvm::PHINode::Create(pointer, 2, "native.array.result", call);
            merged->addIncoming(llvm::ConstantPointerNull::get(pointer), entry);
            merged->addIncoming(result, value);
            call->replaceAllUsesWith(merged);
            llvm::errs() << "native-map-lowering: " << (per_cpu ? "percpu-array " : "array ")
                         << module.getModuleIdentifier()
                         << "::" << entry->getParent()->getName() << "\n";
            call->eraseFromParent();
        }
        return lookups.empty() ? llvm::PreservedAnalyses::all() : llvm::PreservedAnalyses::none();
    }
};
#endif
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "native-bpf-division", LLVM_VERSION_STRING,
        [](llvm::PassBuilder &builder) {
            builder.registerPipelineStartEPCallback(
                [](llvm::ModulePassManager &passes, llvm::OptimizationLevel) {
                    passes.addPass(llvm::createModuleToFunctionPassAdaptor(NativeDivision()));
                });
#if defined(K_BPF_ARRAY_VALUE_OFFSET) && defined(K_BPF_ARRAY_ELEM_SIZE_OFFSET) && \
    defined(K_BPF_ARRAY_INDEX_MASK_OFFSET) && defined(K_BPF_MAP_MAX_ENTRIES_OFFSET)
            builder.registerOptimizerLastEPCallback(
                [](llvm::ModulePassManager &passes, llvm::OptimizationLevel) {
                    passes.addPass(NativeArrayLookups());
                    llvm::FunctionPassManager cleanup;
                    cleanup.addPass(llvm::SROAPass(llvm::SROAOptions::ModifyCFG));
                    cleanup.addPass(llvm::InstCombinePass());
                    cleanup.addPass(llvm::SimplifyCFGPass());
                    passes.addPass(llvm::createModuleToFunctionPassAdaptor(std::move(cleanup)));
                });
#endif
        }};
}
