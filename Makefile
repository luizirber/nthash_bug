all: nt_opt nt_article nt_104

SHELL:=/bin/bash --login

nt_104: nt_main.cpp nthash_104.hpp
	g++ -O3 -DNTHASH_104 -I. $< -o $@

nt_opt: nt_main.cpp nthash.hpp
	g++ -O3 -DNTHASH_OPT -I. $< -o $@

nt_article: nt_main.cpp nthash_simple.hpp
	g++ -O3 -I. $< -o $@

test: nt_opt nt_article
	./nt_opt TGCAG
	./nt_article TGCAG
	python nthash.py TGCAG
	cargo run -q TGCAG

.PHONY: test
