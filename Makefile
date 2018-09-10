all: nt_opt nt_article

SHELL:=/bin/bash --login

nt_opt: nt_main.cpp
	g++ -O3 -DNTHASH_OPT -I. $< -o $@

nt_article: nt_main.cpp
	g++ -O3 -I. $< -o $@

test: nt_opt nt_article
	./nt_opt TGCAG
	./nt_article TGCAG
	python nthash.py TGCAG
	cargo run -q TGCAG

.PHONY: test
