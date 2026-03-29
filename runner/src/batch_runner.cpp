// TODO: moved to Python orchestrator (§5.6)
//
// The legacy C++ batch runner owned prepared-state caching, daemon socket
// coordination, and attach/app lifecycle orchestration. The new architecture
// removes that responsibility from micro_exec entirely; Python is now the only
// orchestrator for multi-step benchmark flows.
