// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_cycles
// ------------

int collatz_cycles (int x){
	
	int cycles = 1;
	while(x > 1){
		if( x % 2 == 0)
			x = x/2;
		else
			x = x * 3 + 1;
		cycles++;
	}
	return cycles;
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // my code
    int biggest = 0;
    while(i <= j) {
    
    	int x = collatz_cycles(i);
    	if(x > biggest)
    		biggest = x;
    	i++;
    }		
    
    return biggest;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int v = collatz_eval(p.first, p.second);
        collatz_print(w, p.first, p.second, v);}}
