- TMsimulator. It's compiled with 

g++ -o TMsimulator TMsimulator.c -lgmpxx -lgmp

To use it: 
./TMsimulator <s> <k> <r> <A> <B>

- <s> is the number of states. 
- <k> is the size of the alphabet. 
- <r> is the max. runtime allowed. 
- <A> is the number of the starting Turing machine (in the enumeration)
- <B> is the number of the ending Turing machine.

Example: 
$ ./TMsimulator 2 2 500 1000 5000
-1 : 2778
0 : 401
00 : 96      
001 : 1     
01 : 103
011 : 3  -> string '011' was the output of 3 machines
1 : 400
10 : 103
101 : 1
11 : 110
110 : 2
111 : 3

-1 is an indicator of non-halting machines. You will also find -2, -3, etc., depending on the filter detecting the non-halting behaviour. 

The most interesting program for you is the other one: 

- TMrandom.c. It runs random machines with desired number of states and symbols. Compiled with:

g++ -o TMrandom TMrandom.c -lgmpxx -lgmp -I boost/

I used the library boost for random number generation, because the functions I use were not included in g++ but I think that they are already included. 

The usage is equal to TMsimulator but now <A> is always 1  and <B> the number of random machines to run. For example, to run 100 random machines with 3 states and 4 symbols: 

./TMrandom 3 4 500 1 100
-1 : 13
-2 : 15
-3 : 23
-4 : 21
-5 : 4
00 : 1
01 : 2
02 : 1
03 : 3
10 : 2
103 : 2
11 : 1
12 : 1
13 : 1
20 : 3
21 : 1
22 : 2
221 : 1
23 : 1
33 : 1
331 : 1
