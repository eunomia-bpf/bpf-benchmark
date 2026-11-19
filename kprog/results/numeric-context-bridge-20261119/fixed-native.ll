; ModuleID = '/workspaces/kprog-raw/perf/numeric-context-bridge-20261119/reproduce-20261119T133702Z-416559/native.bc'
source_filename = "/workspaces/repository/kprog/results/numeric-context-bridge-20261119/fixture.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(none)
define noundef i64 @plain_value(i64 noundef returned %0) local_unnamed_addr #0 !dbg !20 {
  call void @llvm.dbg.value(metadata i64 %0, metadata !25, metadata !DIExpression()), !dbg !26
  ret i64 %0, !dbg !27
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(none)
define noundef i64 @numeric_value(i64 noundef returned %0) local_unnamed_addr #0 !dbg !28 {
  call void @llvm.dbg.value(metadata i64 %0, metadata !30, metadata !DIExpression()), !dbg !34
  ret i64 %0, !dbg !35
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(none)
define i64 @numeric_lane(i64 noundef %0, i32 noundef %1) local_unnamed_addr #0 !dbg !36 {
  call void @llvm.dbg.value(metadata i64 %0, metadata !41, metadata !DIExpression()), !dbg !46
  call void @llvm.dbg.value(metadata i32 %1, metadata !42, metadata !DIExpression()), !dbg !46
  %3 = shl i32 %1, 3, !dbg !47
  %4 = and i32 %3, 56, !dbg !47
  %5 = zext nneg i32 %4 to i64, !dbg !48
  %6 = lshr i64 %0, %5, !dbg !48
  %7 = and i64 %6, 4294967295, !dbg !49
  ret i64 %7, !dbg !50
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite)
define i64 @numeric_once(ptr nocapture noundef %0) local_unnamed_addr #1 !dbg !51 {
  call void @llvm.dbg.value(metadata ptr %0, metadata !56, metadata !DIExpression()), !dbg !60
  %2 = load i64, ptr %0, align 8, !dbg !61, !tbaa !62
  %3 = add i64 %2, 1, !dbg !61
  store i64 %3, ptr %0, align 8, !dbg !61, !tbaa !62
  call void @llvm.dbg.value(metadata i64 %2, metadata !57, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.value(metadata i64 poison, metadata !59, metadata !DIExpression()), !dbg !66
  call void @llvm.dbg.value(metadata i64 %2, metadata !59, metadata !DIExpression()), !dbg !66
  ret i64 %2, !dbg !67
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { mustprogress nofree norecurse nosync nounwind willreturn memory(none) "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite) "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #2 = { mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none) }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!14, !15, !16, !17, !18}
!llvm.ident = !{!19}

!0 = distinct !DICompileUnit(language: DW_LANG_C11, file: !1, producer: "Ubuntu clang version 18.1.3 (1ubuntu1)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !2, globals: !7, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "/workspaces/repository/kprog/results/numeric-context-bridge-20261119/fixture.c", directory: "/workspaces/repository", checksumkind: CSK_MD5, checksum: "492e19c09a2bcaf1f4d53fcca0d72ba4")
!2 = !{!3, !4}
!3 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!4 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !5, size: 64)
!5 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !6)
!6 = !DIBasicType(name: "unsigned long long", size: 64, encoding: DW_ATE_unsigned)
!7 = !{!8}
!8 = !DIGlobalVariableExpression(var: !9, expr: !DIExpression())
!9 = distinct !DIGlobalVariable(name: "kprog_unspecified_input", scope: !0, file: !10, line: 19, type: !11, isLocal: false, isDefinition: false)
!10 = !DIFile(filename: "kprog/stock-path/bin/../include/stock_native_input.h", directory: "/workspaces/repository", checksumkind: CSK_MD5, checksum: "cde30e22d63c53ed5cfa7a8b2a7c9aca")
!11 = !DICompositeType(tag: DW_TAG_array_type, baseType: !6, elements: !12)
!12 = !{!13}
!13 = !DISubrange(count: -1)
!14 = !{i32 7, !"Dwarf Version", i32 5}
!15 = !{i32 2, !"Debug Info Version", i32 3}
!16 = !{i32 1, !"wchar_size", i32 4}
!17 = !{i32 7, !"frame-pointer", i32 2}
!18 = !{i32 7, !"debug-info-assignment-tracking", i1 true}
!19 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!20 = distinct !DISubprogram(name: "plain_value", scope: !21, file: !21, line: 3, type: !22, scopeLine: 3, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !24)
!21 = !DIFile(filename: "kprog/results/numeric-context-bridge-20261119/fixture.c", directory: "/workspaces/repository", checksumkind: CSK_MD5, checksum: "492e19c09a2bcaf1f4d53fcca0d72ba4")
!22 = !DISubroutineType(types: !23)
!23 = !{!3, !3}
!24 = !{!25}
!25 = !DILocalVariable(name: "value", arg: 1, scope: !20, file: !21, line: 3, type: !3)
!26 = !DILocation(line: 0, scope: !20)
!27 = !DILocation(line: 3, column: 50, scope: !20)
!28 = distinct !DISubprogram(name: "numeric_value", scope: !21, file: !21, line: 5, type: !22, scopeLine: 6, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !29)
!29 = !{!30, !31, !33}
!30 = !DILocalVariable(name: "value", arg: 1, scope: !28, file: !21, line: 5, type: !3)
!31 = !DILocalVariable(name: "__kprog_numeric_bits", scope: !32, file: !21, line: 7, type: !3)
!32 = distinct !DILexicalBlock(scope: !28, file: !21, line: 7, column: 12)
!33 = !DILocalVariable(name: "__kprog_numeric_scalar", scope: !32, file: !21, line: 7, type: !3)
!34 = !DILocation(line: 0, scope: !28)
!35 = !DILocation(line: 7, column: 5, scope: !28)
!36 = distinct !DISubprogram(name: "numeric_lane", scope: !21, file: !21, line: 10, type: !37, scopeLine: 11, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !40)
!37 = !DISubroutineType(types: !38)
!38 = !{!3, !3, !39}
!39 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!40 = !{!41, !42, !43, !45}
!41 = !DILocalVariable(name: "value", arg: 1, scope: !36, file: !21, line: 10, type: !3)
!42 = !DILocalVariable(name: "lane", arg: 2, scope: !36, file: !21, line: 10, type: !39)
!43 = !DILocalVariable(name: "__kprog_numeric_bits", scope: !44, file: !21, line: 12, type: !3)
!44 = distinct !DILexicalBlock(scope: !36, file: !21, line: 12, column: 13)
!45 = !DILocalVariable(name: "__kprog_numeric_scalar", scope: !44, file: !21, line: 12, type: !3)
!46 = !DILocation(line: 0, scope: !36)
!47 = !DILocation(line: 12, column: 54, scope: !36)
!48 = !DILocation(line: 12, column: 39, scope: !36)
!49 = !DILocation(line: 12, column: 60, scope: !36)
!50 = !DILocation(line: 12, column: 5, scope: !36)
!51 = distinct !DISubprogram(name: "numeric_once", scope: !21, file: !21, line: 15, type: !52, scopeLine: 16, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !55)
!52 = !DISubroutineType(types: !53)
!53 = !{!3, !54}
!54 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !3, size: 64)
!55 = !{!56, !57, !59}
!56 = !DILocalVariable(name: "value", arg: 1, scope: !51, file: !21, line: 15, type: !54)
!57 = !DILocalVariable(name: "__kprog_numeric_bits", scope: !58, file: !21, line: 17, type: !3)
!58 = distinct !DILexicalBlock(scope: !51, file: !21, line: 17, column: 12)
!59 = !DILocalVariable(name: "__kprog_numeric_scalar", scope: !58, file: !21, line: 17, type: !3)
!60 = !DILocation(line: 0, scope: !51)
!61 = !DILocation(line: 17, column: 12, scope: !58)
!62 = !{!63, !63, i64 0}
!63 = !{!"long", !64, i64 0}
!64 = !{!"omnipotent char", !65, i64 0}
!65 = !{!"Simple C/C++ TBAA"}
!66 = !DILocation(line: 0, scope: !58)
!67 = !DILocation(line: 17, column: 5, scope: !51)
