/* arm64 native objects: all executable input sections in one .text (vendor/bpf/Makefile). */
SECTIONS
{
  .text : { INPUT_SECTION_FLAGS (SHF_EXECINSTR) *(*) }
}
