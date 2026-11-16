// Reuse the canonical BPF lowering, adapting its entry before any optimization.
#include "llvmbpf.hpp"
#include "llvm_jit_context.hpp"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/ToolOutputFile.h"
using namespace llvm;

static cl::opt<std::string> Input(cl::Positional, cl::Required);
static cl::opt<std::string> Output("o", cl::Required);
static cl::opt<std::string> Symbol("symbol", cl::Required);

int main(int argc, char **argv)
{
    cl::ParseCommandLineOptions(argc, argv);
    auto bytes = MemoryBuffer::getFile(Input);
    if (!bytes) { errs() << bytes.getError().message() << '\n'; return 1; }
    bpftime::llvmbpf_vm vm;
    vm.set_kernel_compatible_mode(true);
    if (vm.load_code((*bytes)->getBufferStart(), (*bytes)->getBufferSize())) {
        errs() << vm.get_error_message() << '\n'; return 1;
    }
    bpftime::llvm_bpf_jit_context context(vm);
    auto module = context.generateModule({}, {}, false, true, Symbol);
    if (!module) { errs() << toString(module.takeError()) << '\n'; return 1; }
    bool invalid = false;
    module->withModuleDo([&](Module &m) {
        auto *entry = m.getFunction(Symbol);
        auto &c = m.getContext();
        auto *word = Type::getInt64Ty(c);
        auto *callee = Function::Create(FunctionType::get(word, {word, word, word, word, word}, false),
                                        GlobalValue::ExternalLinkage, "", m);
        callee->takeName(entry);
        callee->splice(callee->begin(), entry);
        auto &setup = callee->getEntryBlock();
        IRBuilder<> builder(&*setup.getFirstInsertionPt());
        entry->getArg(0)->replaceAllUsesWith(builder.CreateIntToPtr(callee->getArg(0), entry->getArg(0)->getType()));
        // Kernel-entry lowering initializes these registers to zero. A BPF
        // callee receives their actual caller values, so replace the setup
        // stores before promotion/inlining can fold them into the body.
        for (auto &instruction : setup) {
            auto *store = dyn_cast<StoreInst>(&instruction);
            if (!store) continue;
            for (unsigned reg = 2; reg <= 5; ++reg)
                if (store->getPointerOperand()->getName() == "r" + Twine(reg).str())
                    store->setOperand(0, callee->getArg(reg - 1));
        }
        entry->eraseFromParent();
        invalid = verifyModule(m, &errs());
        if (invalid) return;
        std::error_code error;
        ToolOutputFile output(Output, error, sys::fs::OF_Text);
        if (error) { errs() << error.message() << '\n'; invalid = true; return; }
        m.print(output.os(), nullptr);
        output.keep();
    });
    return invalid ? 1 : 0;
}
