from pathlib import Path
import json
OUT=Path(__file__).resolve().parent;rows=json.loads((OUT/'programs.json').read_text());objects=json.loads((OUT/'objects.json').read_text())
for row in rows:
 obj=objects[row['object']];row['alignment_evidence']={
 'frozen_globals':dict(frontend_ir_present=row['frontend_ir_present'],readonly_candidates_in_object=len(obj['readonly_native_objects']),actual_live_frozen_map_values='pending-plan-and-installed-code-join'),
 'context_rewrites':dict(native_source='mechanisms.md#context',program_attach_type_and_actual_offsets='pending-load-and-code-join'),
 'helpers':dict(direct_entry_external_symbols=row['direct_entry_external_symbols'],transitive_and_actual_targets='not-proven-by-entry-relocations'),
 'tail_calls':dict(direct_entry_reference=row['direct_entry_tail_call_reference'],live_prog_arrays_and_taken_targets='pending-runtime-evidence'),
 'map_dispatch':dict(object_map_symbols=len(obj['map_symbols']),object_truncated_alias_collision_groups=len(obj['map_alias_collisions']),actual_name_id_type_shape_binding='pending-live-link-plan-join'),
 'app_compile_and_load_switches':dict(embedded_command_available=bool(obj['embedded_compile_command']),record='codegen-policy.json and objects.json',live_loader_written_values_and_feature_set='pending-current-app-source-and-plan-join')}
(OUT/'programs.json').write_text(json.dumps(rows,indent=2)+'\n')
