
/*##### Initialising patterns #############################*/
/*
 * The amount of steps in sequence is stored in the [0][0] position,
 * so THE FIRST ROW OF THE SEQUENCE IS NOT USED
 */


const int8_t ritariAssa[][7]  = {
  {14,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1},
  {0,0,0,0,0,0,1},
  {0,0,0,0,0,1,0},
  {0,0,0,0,1,0,0},
  {0,0,0,1,0,0,0},
  {0,0,1,0,0,0,0},
  {0,1,0,0,0,0,0},
  {1,0,0,0,0,0,0}
  };
  
const int8_t allOn[][7]  = {
  {1,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {1,1,1,1,1,1,1}
  };
  
const int8_t allOff[][7]  = {
  {1,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {0,0,0,0,0,0,0}
  };

const int8_t randChance = -2;
const int8_t randSidesMidOn[][7]  = {
  {1,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {randChance,randChance,randChance,1,randChance,randChance,randChance}
  };
const int8_t randSidesMidBlink[][7]  = {
  {2,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {randChance,randChance,randChance,1,randChance,randChance,randChance},
  {randChance,randChance,randChance,0,randChance,randChance,randChance}
  };

const int randChance2 = -3;
const int8_t randSidesMidBlink_rarer[][7]  = {
  {2,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {randChance2,randChance2,randChance2,1,randChance2,randChance2,randChance2},
  {randChance2,randChance2,randChance2,0,randChance2,randChance2,randChance2}
  };


const int8_t waterFall[][7]  = {
  {10,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {1,0,0,0,0,0,1},
  {0,1,0,0,0,1,0},
  {0,0,1,0,1,0,0},
  {0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0},
  {0,0,1,0,0,0,0},
  {0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0},
  {0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0}
  };


const int8_t pseudoRandomSides[][7]  = {
  {18,0,0,0,0,0,0}, /* The amount of steps in sequence */
  {1,0,0,1,0,0,0},
  {0,0,0,1,1,0,0},
  {0,1,0,1,0,0,0},
  {0,0,0,1,0,0,1},
  {1,0,0,1,0,0,0},
  {0,0,0,1,0,1,0},
  {0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0},
  {0,1,0,1,0,0,0},
  {0,0,0,1,1,0,0},
  {1,0,0,1,0,0,0},
  {0,0,0,1,0,0,1},
  {1,0,0,1,0,0,0},
  {0,0,0,1,0,1,0},
  {0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0},
  {0,1,0,1,0,0,0},
  {0,0,0,1,0,1,0}
  };

  
