# Prefetch literature source cache

最后更新：2026-05-31。

## 规则

这个目录保存 prefetch literature review 使用的完整 source。后续更新 review 时必须遵守：

1. 不能只看摘要、新闻稿或二手博客就写结论。
2. 对每个被纳入 review 的论文、手册、网页或开源实现，必须保存一份可复查 source。
3. PDF / PS / HTML / source code 能直接下载时，必须放到本目录对应子目录。
4. 下载失败或被登录墙阻挡时，必须在 `manifest.tsv` 里标为 `blocked` 或 `unavailable`，不能假装已经阅读。
5. 文档中只允许引用短句或转述结论，不能复制长段原文。
6. 对设计决策的结论必须能追溯到 `manifest.tsv` 中的 source。

## 子目录

| 目录 | 内容 |
|---|---|
| `papers/` | 论文 PDF、PS、PS.GZ。 |
| `manuals/` | ISA / compiler / vendor 手册和网页。 |
| `opensource/` | 开源实现源码或 repository snapshot。 |
| `web/` | 论文主页、项目主页和网页快照。 |
| `text/` | PDF 转成的 text，用于本地检索和复查。 |

## 入口

Source inventory：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources/manifest.tsv
```

Review：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md
```
