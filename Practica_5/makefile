.PHONY: Practica5.pdf all clean

all: Practica5.pdf


%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@


Practica5.pdf: Practica5.tex
	latexmk -f -quiet -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Practica5.tex

clean:
	latexmk -CA