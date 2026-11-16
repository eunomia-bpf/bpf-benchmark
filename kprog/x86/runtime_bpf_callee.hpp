#pragma once
#include "llvm/Linker/Linker.h"
#include "../libnativeloader/src/native_loader_subprocess.hpp"
#include <fstream>

// The companion compiler uses the canonical LLVM build. Text IR crosses the
// process boundary and is parsed into this module's context before native O3.
static llvm::Error lowerRuntimeBpfCallee(
    llvm::Function &function, llvm::ArrayRef<bpf_insn> code,
    llvm::Function &entry, const std::filesystem::path &compiler,
    const std::string &prefix)
{
    using namespace llvm;
    const auto raw = prefix + ".bpf", ir = prefix + ".ll", log = prefix + ".log";
    {
        std::ofstream output(raw, std::ios::binary | std::ios::trunc);
        output.write(reinterpret_cast<const char *>(code.data()), code.size() * sizeof(bpf_insn));
        output.close();
        if (!output) return native_bpf::failure("write captured BPF callee: " + raw);
    }
    const auto symbol = "__captured_bpf_body_" + function.getName().str();
    const std::vector<std::string> argv = {compiler.string(), raw, "--symbol", symbol, "-o", ir};
    const int status = native_loader_detail::run_subprocess(argv, log);
    if (status) {
        const int saved = errno;
        auto diagnostics = MemoryBuffer::getFile(log);
        const auto detail = diagnostics ? (*diagnostics)->getBuffer().str() : diagnostics.getError().message();
        return native_bpf::failure("BPF callee compiler failed (status " + std::to_string(status) +
                                  ", errno " + std::to_string(saved) + "): " + detail);
    }
    auto &module = *function.getParent();
    SMDiagnostic diagnostic;
    auto imported = parseIRFile(ir, diagnostic, module.getContext());
    if (!imported) {
        std::string message;
        raw_string_ostream stream(message);
        diagnostic.print("BPF callee IR", stream);
        return native_bpf::failure(stream.str());
    }
    imported->setTargetTriple(module.getTargetTriple());
    imported->setDataLayout(module.getDataLayout());
    SmallVector<Function *, 8> helpers;
    for (auto &f : *imported) {
        if (f.getName().starts_with("_bpf_helper_ext_")) helpers.push_back(&f);
        if (f.isDeclaration()) continue;
        for (const auto *name : {"target-cpu", "target-features", "tune-cpu", "frame-pointer"}) {
            auto attribute = entry.getFnAttribute(name);
            if (attribute.isValid()) f.addFnAttr(attribute);
        }
        if (entry.hasFnAttribute(Attribute::NoRedZone)) f.addFnAttr(Attribute::NoRedZone);
    }
    for (auto *helper : helpers) {
        uint32_t id;
        if (helper->getName().drop_front(StringRef("_bpf_helper_ext_").size()).getAsInteger(10, id))
            return native_bpf::failure("invalid canonical BPF helper symbol");
        helper->replaceAllUsesWith(ConstantExpr::getIntToPtr(
            ConstantInt::get(Type::getInt64Ty(module.getContext()), id), helper->getType()));
        helper->eraseFromParent();
    }
    if (Linker::linkModules(module, std::move(imported)))
        return native_bpf::failure("link captured BPF callee IR");
    auto *body = module.getFunction(symbol);
    if (!body) return native_bpf::failure("captured BPF callee entry is missing");
    auto *block = BasicBlock::Create(module.getContext(), "original_bpf_body", &function);
    function.setLinkage(GlobalValue::InternalLinkage);
    function.setDSOLocal(true);
    function.setSubprogram(nullptr);
    function.setMemoryEffects(MemoryEffects::unknown());
    IRBuilder<> builder(block);
    SmallVector<Value *, 5> arguments(5, builder.getInt64(0));
    for (unsigned i = 0; i < function.arg_size() && i < arguments.size(); ++i) {
        auto *arg = function.getArg(i);
        if (arg->getType()->isPointerTy()) arguments[i] = builder.CreatePtrToInt(arg, builder.getInt64Ty());
        else if (arg->getType()->isIntegerTy())
            arguments[i] = builder.CreateIntCast(arg, builder.getInt64Ty(), function.hasParamAttribute(i, Attribute::SExt));
        else return native_bpf::failure("captured BPF argument requires a scalar or pointer");
    }
    auto *value = builder.CreateCall(body, arguments);
    auto *type = function.getReturnType();
    if (type->isVoidTy()) builder.CreateRetVoid();
    else if (type->isPointerTy()) builder.CreateRet(builder.CreateIntToPtr(value, type));
    else builder.CreateRet(builder.CreateIntCast(value, type, false));
    body->setLinkage(GlobalValue::InternalLinkage);
    body->setDSOLocal(true);
    return Error::success();
}
