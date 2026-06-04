# Prefetch Literature

最后更新：2026-06-03。

## 结论

本目录保存 Kinsn prefetch task 的 literature review 和 source cache。这里的内容用于设计 policy
和构造 microbenchmark，不直接等同于当前实现或最终默认策略。

## 目录

| 路径 | 内容 |
|---|---|
| `literature-review.md` | 论文、工业实现、开源实现的整理和对 Kinsn prefetch 的影响。 |
| `sources/manifest.tsv` | 本地 source cache manifest。 |
| `sources/papers/` | 论文 PDF / PS。 |
| `sources/manuals/` | 官方手册和 ISA / compiler 文档。 |
| `sources/opensource/` | 开源实现源码或 repo snapshot。 |
| `sources/text/` | 从论文或手册提取的文本，便于检索。 |
| `sources/web/` | 网页来源的 HTML 副本。 |

## 使用规则

1. 设计结论必须能追溯到 `sources/manifest.tsv` 中的 source。
2. 不能只引用 abstract 或搜索摘要。
3. 如果 literature 启发了某个 prefetch policy，必须在 `policy-matrix.md` 里说明它和 Kinsn scope
   的差异。

