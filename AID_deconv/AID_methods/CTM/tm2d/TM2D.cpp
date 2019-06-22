/*

  FIXED THE BUG OF CYCLES OF ORDER TWO

  2D Turing Machines
  Version with the reduced enumeration and detection of non-halting machines

  Output codes:
  - "-1": non-detected non-halting machine
  - "-2": machine without transition to the halting state
  - "-3": short escapees
  - "-4": other escapees
  - "-5": cycles of order two

 */

#include <stdlib.h>  // general-purpose library
//#include <stdio.h>   // read-write functionality
//#include <string>  // string manipulation library
//#include <ctype.h>   // character classification functions
#include <gmp.h>
#include <iostream>
//#include <algorithm>
#include <sstream>
#include <map>
//#include <utility>

using namespace std;

typedef char symbol;   // The 'symbol' is a char (256)
enum direction {DIR_LEFT, STOP, DIR_RIGHT, DIR_UP, DIR_DOWN}; // possible directions


struct position {
  int posx;
  int posy;
  bool operator<( const position & n ) const {
    return (this->posx < n.posx) || (this->posx==n.posx && this->posy<n.posy); 
  }
};
typedef struct position position;

// struct which contains the result of a transition of the TM
struct transition_result {
  int control_state;      // new state
  symbol write_symbol;    // written symbol
  enum direction dir;     // head direction
};
typedef struct transition_result transition_result;

// the state of the TM 
struct turing_machine_state {
  int control_state;         // current state
  int max_head_x_position;   // number of the most-right visited cell (>=0)
  int min_head_x_position;   // number of the most-left visited cell  (<=0)
  int max_head_y_position;   // number of the most-up visited cell (>=0)
  int min_head_y_position;   // number of the most-down visited cell  (<=0)
  int escapees;              // consecutive shifts to blank symbols (to detect escapees)
  
  position head_position;
  map<position, int> tape;
};
typedef struct turing_machine_state turing_machine_state;

// General data of the TM
struct turing_machine {
  int number_colors;         // number of symbols
  int running_state;         // -1 continue, 0 stop, other values: non-halting codes
  int number_states;         // number of states
  int halting_state;         // halting state
  int initial_control_state; // initial state
  symbol blank_symbol;       // blank symbol 
  turing_machine_state state;
  transition_result** transition_table;
};
typedef struct turing_machine turing_machine;


/* Check whether the two given directions are opposed */
bool reverseDir(direction d1, direction d2){
  switch (d1){
  case DIR_LEFT:
    if(d2 == DIR_RIGHT)
      return true;
    break;
  case DIR_RIGHT:
    if(d2 == DIR_LEFT)
      return true;
    break;
  case DIR_UP:
    if(d2 == DIR_DOWN)
      return true;
    break;
  case DIR_DOWN:
    if(d2 == DIR_UP)
      return true;
    break;    
  default:
    return false;
  }
  return false;
}

 
/*****************************************************************************
   Executes one step in a given TM
*****************************************************************************/
int run_step(turing_machine *m){

  int state1 = m->state.control_state;         // the state before the step
  position cell = m->state.head_position;      // the position before the step
    
  symbol s1 = m->state.tape[cell];         // reading this symbol before the step
    
  // Gets the transition to apply
  transition_result tr = m->transition_table[m->state.control_state][s1];

  // writes the symbol
  m->state.tape[cell] = tr.write_symbol;
    
  // Changes the state    
  m->state.control_state = tr.control_state;  

  // Stops (without moving the head) if the halting state is reached
  if(m->state.control_state == m->halting_state){
    m->running_state=0;
    return 0;
  }

  // a flag that will be activated to increment the escepees detector
  bool escap = false;
 
  switch(tr.dir){            // moving the head
  case DIR_LEFT: // LEFT
    m->state.head_position.posx--;
    if(m->state.min_head_x_position > m->state.head_position.posx){
      m->state.min_head_x_position--;
      escap = true;
    };
    break;
  case DIR_RIGHT: // RIGHT
    m->state.head_position.posx++;
    if(m->state.max_head_x_position < m->state.head_position.posx){
      m->state.max_head_x_position++;
      escap = true;
    };
    break;
  case DIR_UP:  // UP
    m->state.head_position.posy++;
    if(m->state.max_head_y_position < m->state.head_position.posy){
      m->state.max_head_y_position++;
      escap = true;
    };
    break;
  case DIR_DOWN:  // DOWN
    m->state.head_position.posy--;
    if(m->state.min_head_y_position > m->state.head_position.posy){
      m->state.min_head_y_position--;
      escap = true;
    };
    break;
  }
  
  if(escap){  // detecting escapees
    m->state.escapees++;
    if(s1 == m->blank_symbol && m->state.control_state == state1){ // short escapee
      m->running_state = -3; 
      return 0;
    }
    if(m->state.escapees > m->number_states){   // regular escapee detected
      m->running_state = -4; 
      return 0;
    }       
  } else{
    m->state.escapees = 0;
  }
  
  // Detecting cycles of order two
  if(tr.write_symbol == s1){     // BUG FIXED
    symbol s2 = m->state.tape[m->state.head_position];
    transition_result tr2 = m->transition_table[m->state.control_state][s2];
    if (tr2.control_state == state1 && 
	tr2.write_symbol == s2 &&
	reverseDir(tr2.dir,tr.dir)){
      m->running_state = -5; 
      return 0;
    }
  }
  
  return 1;  
}




/******************************************************************
  Initialization of a Turing Machine
 ******************************************************************/

turing_machine init_turing_machine(int states, int colors, int blank, mpz_t numberTM){

  turing_machine m;
  m.number_colors = colors;
  m.number_states = states;
  m.halting_state = -1;          // Halting state
  m.initial_control_state = 0;   // 
  m.blank_symbol = blank;

  // Initial state
  m.state.control_state = m.initial_control_state;
  m.state.head_position.posx = 0;
  m.state.head_position.posy = 0;
  m.state.escapees = 0;
  m.state.max_head_x_position = 0;
  m.state.max_head_y_position = 0;
  m.state.min_head_x_position = 0;
  m.state.min_head_y_position = 0;
  
  // Creation of the transition table
  //malloc the states dimension
  m.transition_table = (transition_result**) malloc(sizeof(transition_result*) * m.number_states);  
  if (m.transition_table == NULL) {    // if not enough memory
    printf("Out of memory: creating transition table (1)");  
    exit(-1);                // the program finishes
  }
  //iterate over states
  int s;
  for(s=0;s<m.number_states;s++){
    // malloc the colors dimension
    m.transition_table[s] = (transition_result*) malloc(sizeof(transition_result) * m.number_colors);
    if (m.transition_table[s] == NULL) {    // if not enough memory
      printf("Out of memory: creating transition table (2)");  
      exit(-1);                // the program finishes
    }      
  } 
 
  
  // Filling the transition table
  int i = 0;
  int j= 0;
  mpz_t gr; // rest
  mpz_t gc; // quotient
  
  mpz_init(gr);
  mpz_init(gc);
  
  int rest;

  int halts = -2; // to test if the machine halts
  
  // Filling the initial transition 
  mpz_fdiv_qr_ui(gc, gr, numberTM, colors*(states-1));
  mpz_set(numberTM, gc);

  m.transition_table[0][0].dir = DIR_RIGHT; // goes to the right
  rest = mpz_get_ui(gr);
  m.transition_table[0][0].write_symbol = (rest % colors);
  rest = rest/colors;
  m.transition_table[0][0].control_state = 1+(rest % (states-1));

  // Other transitions from the initial state
  for(j=1;j<colors;j++){
    
    mpz_fdiv_qr_ui(gc, gr, numberTM, colors*((4*states)+1));
    mpz_set(numberTM, gc);
    
    rest = mpz_get_ui(gr);
    
    if(rest<colors){
      m.transition_table[0][j].control_state = m.halting_state;
      m.transition_table[0][j].write_symbol = rest;
      m.transition_table[0][j].dir = STOP;
      halts = -1;
    } else {
      rest = rest - colors;
      
      m.transition_table[0][j].write_symbol = (rest % colors);
      rest = rest/colors;

      switch(rest % 4){
      case 0:
	m.transition_table[0][j].dir = DIR_RIGHT;
	break;
      case 1:
	m.transition_table[0][j].dir = DIR_LEFT;
	break;
      case 2:
	m.transition_table[0][j].dir = DIR_UP;
	break;
      case 3:
	m.transition_table[0][j].dir = DIR_DOWN;
	break;
      }
      rest = rest / 4;
      
      m.transition_table[0][j].control_state = (rest % states);
      
    }
  }

  // Transitions for other states
  for (i=1; i<states; i++) {  
    for(j=0;j<colors;j++){
      
      mpz_fdiv_qr_ui(gc, gr, numberTM, colors*((4*states)+1));
      mpz_set(numberTM, gc);
      
      rest = mpz_get_ui(gr);
      
      if(rest<colors){
	m.transition_table[i][j].control_state = m.halting_state;
	m.transition_table[i][j].write_symbol = rest;
	m.transition_table[i][j].dir = STOP;
	halts = -1;
      } else {
	rest = rest - colors;

	m.transition_table[i][j].write_symbol = (rest % colors);
	rest = rest/colors;
	
	switch(rest % 4){
	case 0:
	  m.transition_table[i][j].dir = DIR_RIGHT;
	  break;
	case 1:
	  m.transition_table[i][j].dir = DIR_LEFT;
	  break;
	case 2:
	  m.transition_table[i][j].dir = DIR_UP;
	  break;
	case 3:
	  m.transition_table[i][j].dir = DIR_DOWN;
	  break;
	}
	rest = rest / 4;

	m.transition_table[i][j].control_state = (rest % states); // halting state	
	
      }
    }
  }

  m.running_state = halts;
  mpz_clear(gr);
  mpz_clear(gc);
 
  
  // TO PRINT THE TRANSITION TABLE (for debugging)
  for (i=0; i<states; i++) { 
    for(j=colors-1;j>=0; j--){
      printf("{%i, %i} -> {%i, %i, ",//%i}\n",
	     i+1,j,
	     1+(m.transition_table[i][j].control_state),
	     m.transition_table[i][j].write_symbol//,
	     // (m.transition_table[i][j].dir)-1
	     );
      switch(m.transition_table[i][j].dir){
      case STOP:
	printf("STOP}\n");
	break;
      case DIR_LEFT:
	printf("LEFT}\n");
	break;
      case DIR_RIGHT:
	printf("RIGHT}\n");
	break;
      case DIR_UP:
	printf("UP}\n");
	break;
      case DIR_DOWN:
	printf("DOWN}\n");
	break;
      }
    }
    } 


  return m;

}

void delete_state(turing_machine *m){
  //  free(m->state.tape);
  int i;
  for(i=0;i<m->number_states;i++){
    free(m->transition_table[i]);
  }
  free(m->transition_table);
}


string outputTM(turing_machine *m){
  string sout = "";
  position pos;
  char symb;
  if(m->running_state == 0){
    int i;
    int j;
    for (i=m->state.max_head_y_position; i>=m->state.min_head_y_position; i--){
      pos.posy = i;
      for(j=m->state.min_head_x_position; j<=m->state.max_head_x_position; j++){
	pos.posx = j;
	symb = (m->state.tape[pos])+'0';
	sout = sout+symb; 
      }      
      sout = sout+'-'; 
    }    
    
  } else {    
    stringstream strm;
    strm << m->running_state;  
    strm >> sout;
  }
  return sout;
}


int main(int argn, char* argv[]) {
  // Arguments:
  // - <s>
  // - <k>
  // - maxRuntime
  // - initTM
  // - end TM
  
  turing_machine machine;
  
  map<string, unsigned long long> results;
  string out;
  int i;

  int s = atoi(argv[1]);
  int k = atoi(argv[2]);
  int runtime =  atoi(argv[3]);

  mpz_t TM;
  mpz_init_set_str(TM,argv[4],10);

  mpz_t Last;
  mpz_init_set_str(Last,argv[5],10);

  mpz_t acc;
  mpz_init(acc);
  //  int count = 0;

  while(mpz_cmp(TM,Last)<=0){
    mpz_set(acc,TM);
    machine = init_turing_machine(s,k,0,acc);

    if(machine.running_state==-1){
      for(i=1; i<=runtime && run_step(&machine); i++){};
      out = outputTM(&machine);  
      ++results[out];
      
      //  count++;
    //  if(count==1000000000){
    //    printf("One billion more\n");
    //   count = 0;
    // }
    } else
      ++results["-2"]; // No transition to halt state

    delete_state(&machine);
    mpz_add_ui(TM,TM,1);    

  }

  mpz_clear(TM);
  mpz_clear(Last);
  mpz_clear(acc);

  // Prints the results
  for( map<string,unsigned long long>::iterator ii=results.begin(); ii!=results.end(); ++ii)
    {
      cout << (*ii).first << " : " << (*ii).second << '\n';
    }  
  
}

