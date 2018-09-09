all: nt_opt nt_article

SHELL:=/bin/bash --login

%: %.cpp
	g++ -O3 -I. $< -o $@

test: nt_opt nt_article
	./nt_opt TGCAG
	./nt_article TGCAG
	python nthash.py TGCAG
	cargo run -q TGCAG
