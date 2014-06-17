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

int collatz_eval (int i, int j, int cache[]) {
    // my code
    int biggest = 0;

    // set i to be the min and j to be max
    if( i > j){
        int temp = i;
        i = j;
        j = temp;
    }

    while(i <= j) {
    	
    	int x;
    	
    	// check to see if i's cycles have been calculated if not, calculate it
    	if(i > 999)
    		x = collatz_cycles(i);
    	else if(cache[i] == 0) {
    		x = collatz_cycles(i);
    		cache[i] = x;	
    	}
    	else
    		x = cache[i];
    		
    	if(x > biggest) {
    		biggest = x;
        }
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

	// can hold up to 1k cache values
	int cache [1000] = {};

    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int v = collatz_eval(p.first, p.second, cache);
        collatz_print(w, p.first, p.second, v);}}