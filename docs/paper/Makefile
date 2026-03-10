PAPER = paper
LATEX = pdflatex
BIBTEX = bibtex

.PHONY: all clean

all: $(PAPER).pdf

$(PAPER).pdf: $(PAPER).tex references.bib
	$(LATEX) $(PAPER)
	$(BIBTEX) $(PAPER)
	$(LATEX) $(PAPER)
	$(LATEX) $(PAPER)

clean:
	rm -f $(PAPER).pdf $(PAPER).aux $(PAPER).log $(PAPER).bbl \
	       $(PAPER).blg $(PAPER).out $(PAPER).toc $(PAPER).lof \
	       $(PAPER).lot $(PAPER).synctex.gz
