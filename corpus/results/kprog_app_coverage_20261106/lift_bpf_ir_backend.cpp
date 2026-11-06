/* Reuse llvmbpf instruction lowering; compose source subprograms as LLVM functions. */
#include "lift_bpf_ir_backend.h"
#include <llvmbpf.hpp>
#include "llvm_jit_context.hpp"
#include <llvm/AsmParser/Parser.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Linker/Linker.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

static std::string external(unsigned id) {
    std::ostringstream symbol;symbol<<"_bpf_helper_ext_"<<std::setw(4)<<std::setfill('0')<<id;
    return symbol.str();
}
int lift_bpf_module(const std::vector<LiftFunction> &functions,
    const std::set<unsigned> &helpers,const std::map<unsigned,std::string> &calls,
    const char *output_path) {
    llvm::LLVMContext common;
    auto combined=std::make_unique<llvm::Module>("bpf-source",common);
    for(const auto &function:functions) {
        bpftime::llvmbpf_vm vm;vm.set_kernel_compatible_mode(true);
        if(vm.load_code(function.bytes.data(),function.bytes.size())) {
            std::cerr<<vm.get_error_message()<<'\n';return 1;
        }
        std::vector<std::string> symbols;
        for(unsigned id:helpers)symbols.push_back(external(id));
        for(const auto &[id,name]:calls)symbols.push_back(external(id));
        bpftime::llvm_bpf_jit_context context(vm);
        auto generated=context.generateModule(symbols,{},false,true,function.symbol);
        if(!generated){std::cerr<<llvm::toString(generated.takeError())<<'\n';return 1;}
        std::string ir;
        generated->withModuleDo([&](llvm::Module &body) {
            llvm::raw_string_ostream stream(ir);body.print(stream,nullptr);
        });
        llvm::SMDiagnostic diagnostic;
        auto module=llvm::parseAssemblyString(ir,diagnostic,common);
        if(!module){diagnostic.print("lift-bpf-ir",llvm::errs());return 1;}
        for(const auto &[id,name]:calls) {
            auto *decl=module->getFunction(external(id));
            if(!decl)continue;
            decl->setName(name+".declaration");
            auto *target=module->getFunction(name);
            if(!target)target=llvm::Function::Create(decl->getFunctionType(),llvm::Function::ExternalLinkage,name,*module);
            if(target->getFunctionType()!=decl->getFunctionType() && !decl->use_empty()) {
                std::cerr<<"recursive source entry has incompatible native ABI\n";return 1;
            }
            if(!decl->use_empty())decl->replaceAllUsesWith(target);
            decl->eraseFromParent();
        }
        if(function.pc) {
            auto *old=module->getFunction(function.symbol);
            if(!old || old->arg_size()!=1 || old->empty()){std::cerr<<"source function ABI missing\n";return 1;}
            const auto name=old->getName().str();old->setName(name+".source_entry");
            std::vector<llvm::Type*> args(5,llvm::Type::getInt64Ty(common));
            auto *type=llvm::FunctionType::get(llvm::Type::getInt64Ty(common),args,false);
            auto *body=llvm::Function::Create(type,llvm::Function::ExternalLinkage,name,*module);
            body->splice(body->end(),old);
            llvm::IRBuilder<> builder(&body->getEntryBlock().front());
            auto *ctx=builder.CreateIntToPtr(body->getArg(0),old->getArg(0)->getType());
            old->getArg(0)->replaceAllUsesWith(ctx);
            unsigned restored=0;
            for(auto &instruction:body->getEntryBlock()) {
                auto *store=llvm::dyn_cast<llvm::StoreInst>(&instruction);
                if(!store)continue;
                auto *slot=llvm::dyn_cast<llvm::AllocaInst>(store->getPointerOperand());
                if(!slot || !llvm::isa<llvm::ConstantInt>(store->getValueOperand()))continue;
                const auto reg=slot->getName();
                if(reg.size()==2 && reg[0]=='r' && reg[1]>='2' && reg[1]<='5') {
                    store->setOperand(0,body->getArg(reg[1]-'1'));++restored;
                }
            }
            if(restored!=4 || !old->use_empty()){std::cerr<<"source argument reconstruction failed\n";return 1;}
            old->eraseFromParent();
        }
        if(llvm::Linker::linkModules(*combined,std::move(module))) {
            std::cerr<<"source subprogram LLVM link failed\n";return 1;
        }
    }
    std::string ir;llvm::raw_string_ostream stream(ir);combined->print(stream,nullptr);
    std::ofstream output(output_path,std::ios::binary);
    if(!output){std::cerr<<"open LLVM IR output failed\n";return 1;}
    output.write(ir.data(),static_cast<std::streamsize>(ir.size()));output.close();
    if(!output){std::cerr<<"write LLVM IR output failed\n";return 1;}
    return 0;
}
