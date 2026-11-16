import Lake

open System Lake DSL

package KProgFormal where
  version := v!"0.1.0"

require lnsym from "external/LNSym"

require x86lean from "external/x86lean"

require «compcert-clight-lean» from "external/clean/export"

target clightSources pkg : Unit := do
  Job.async do
    Lake.proc { cmd := "make", args := #["clight-sources"], cwd := some pkg.dir }

-- Library import discovery reads inputs before ordinary extra dependencies.
-- Delegate to Lake's input facet after generating this package's C exports.
@[«module_facet»] def generatedLeanInput : ModuleFacetDecl :=
  ⟨Module.inputFacet, mkFacetJobConfig (buildable := false) fun mod => do
    if mod.pkg.baseName == `KProgFormal then
      discard (← mod.pkg.fetchTargetJob `clightSources).await
    Module.inputFacetConfig.run mod⟩

@[default_target] lean_lib KProgFormal where
  globs := #[`KProgFormal.*]
  weakLeanArgs := #["-j1"]

@[default_target] lean_exe reference where root := `ReferenceMain
