// Combine embedded frontend modules while retaining section program entries.
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Linker/Linker.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
using namespace llvm;

static cl::list<std::string> Inputs(cl::Positional, cl::OneOrMore);
static cl::opt<std::string> Output("o", cl::Required);

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv);
  LLVMContext Context;
  std::unique_ptr<Module> Combined;
  for (const auto &Path : Inputs) {
    SMDiagnostic Error;
    auto Input = parseIRFile(Path, Error, Context);
    if (!Input) { Error.print(argv[0], errs()); return 1; }
    // cc1 embedding omits compiler-used roots. A function with an explicit
    // program section is externally selected through the original ELF even
    // when C gave it internal linkage. Preserve its name and complete body.
    for (auto &Function : *Input)
      if (!Function.isDeclaration() && Function.hasSection()) {
        Function.setLinkage(GlobalValue::ExternalLinkage);
        Function.setDSOLocal(true);
      }
    if (!Combined) Combined = std::move(Input);
    else if (Linker(*Combined).linkInModule(std::move(Input))) return 1;
  }
  std::error_code Error;
  ToolOutputFile File(Output, Error, sys::fs::OF_None);
  if (Error) { errs() << Error.message() << '\n'; return 1; }
  WriteBitcodeToFile(*Combined, File.os());
  File.keep();
}
