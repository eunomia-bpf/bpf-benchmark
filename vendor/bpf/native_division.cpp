// SPDX-License-Identifier: MIT
// Native input follows the eBPF integer quotient/remainder semantics.
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/TargetParser/Triple.h>

namespace {
struct NativeDivision : llvm::PassInfoMixin<NativeDivision> {
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
        for (auto *op : divisions) {
            auto *type = op->getType();
            auto *dividend = op->getOperand(0);
            auto *divisor = op->getOperand(1);
            bool sign = op->getOpcode() == llvm::Instruction::SDiv ||
                        op->getOpcode() == llvm::Instruction::SRem;
            bool remainder = op->getOpcode() == llvm::Instruction::URem ||
                             op->getOpcode() == llvm::Instruction::SRem;
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
                    "=&{ax},=&{dx},0,r,~{cc}", true);
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
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "native-bpf-division", LLVM_VERSION_STRING,
        [](llvm::PassBuilder &builder) {
            builder.registerPipelineStartEPCallback(
                [](llvm::ModulePassManager &passes, llvm::OptimizationLevel) {
                    passes.addPass(llvm::createModuleToFunctionPassAdaptor(NativeDivision()));
                });
        }};
}
