#include <iostream>
#include <vector>
using namespace std;

bool isFull(std::vector<char>& grid) { //just checks if no empty spaces
    for(int i = 0; i < 9; i++) {
        if(grid[i] == '-') { 
            return false;
        }
    } 

    return true;
}

pair<bool, char> isWinner(std::vector<char>& grid, char aiMark, char hMark) {

  
  pair<bool, char> temp; // the pair of: whether the game is over, and who won(if any.)
  //'X' if AI wins, 'O' if human wins, '-' if tie/game not over.

  //horizontal check

  for(int i = 0; i < 9; i+= 3) {

      if(grid[i] == aiMark && grid[i+1] == aiMark && grid[i+2] == aiMark) {
          temp.first = true;
          temp.second = aiMark;
          return temp;
      }
      else if (grid[i] == hMark && grid[i+1] == hMark && grid[i+2] == hMark) {
          temp.first = true;
          temp.second = hMark;
          return temp;
      }

  }

  //vertical check

  for(int i = 0; i < 3; i++) {
      if(grid[i] == aiMark && grid[i + 3] == aiMark && grid[i + 6] == aiMark) {
           temp.first = true;
          temp.second = aiMark;
          return temp;
      } else if(grid[i] == hMark && grid[i + 3] == hMark && grid[i + 6] == hMark) {
         temp.first = true;
          temp.second = hMark;
          return temp;
      }
  }

  //diagonal checks
  if(grid[0] == aiMark && grid[4] == aiMark && grid[8] == aiMark) {
       temp.first = true;
          temp.second = aiMark;
          return temp;
  } else if(grid[0] == hMark && grid[4] == hMark && grid[8] == hMark) {
      temp.first = true;
          temp.second = hMark;
          return temp;
  }

  if(grid[2] == aiMark && grid[4] == aiMark && grid[6] == aiMark) {
       temp.first = true;
          temp.second = aiMark;
          return temp;
  } else if(grid[2] == hMark && grid[4] == hMark && grid[6] == hMark) {
      temp.first = true;
          temp.second = hMark;
          return temp;
  }

  if(isFull(grid) == true) {
      temp.first = true;
      temp.second = '-';
      return temp;
  }

    temp.first = false;
    temp.second = '-';
    return temp;

  


}


int minimax(std::vector<char>& grid, int depth, bool maxim, char aiMark, char hMark) {

    pair<bool, char> result = isWinner(grid, aiMark, hMark);
    
    //result.first will be true if game is over, and result.second is:
    //'X' if ai wins, 'O' if human wins, '-' if game is not over or if it ends with tie
   
    
    if(result.first != false) {

        if(result.second == aiMark) {
	        return 1000; //AI wins (maximizing)
        } else if (result.second == hMark) {
	        return -1000; //Human wins (minimizing)
        } else {
	        return 0; //Tie or depth = 0
	}

    

        

    } else {
        
        if(maxim == true) {
            int best = INT_MIN;

            for(int i = 0; i < 9; i++) {
                
	     

                    if(grid[i] == '-') { //is space empty?
		  
                        grid[i] = aiMark; //editing board
		    
                        int score = minimax(grid, depth + 1, false, aiMark, hMark); //call minimax with "new" board
                        grid[i] = '-';
                        best = max(best, score); //update max
		                 //backtrack
			            
			            

                   


                }

            }
	        
            

            return best; //return max score

        } else {

        int worst = INT_MAX;

        for(int i = 0; i < 9; i++) {
           

                if(grid[i] == '-') {
                    grid[i] = hMark;
                    int score = minimax(grid, depth + 1, true, aiMark, hMark);
                    grid[i] = '-';
                    worst = min(worst, score);
		            
			        
			        

                   
                    }
	        
	        

                }
            


        return worst; //return min score
        }

    }

    

}


void bestMove(std::vector<char>& grid,  char aiMark, char hMark) {

    int best = INT_MIN; //best score for ai
    int finalSpot = -1; //place where ai will put mark
    

    pair<bool, char> result = isWinner(grid, aiMark, hMark); //explained in minimax function comments
    
    if(result.first != false) {
      return; //if game is supposed to be over
    }


    for(int i = 0; i < 9; i++) {
        
	 

            if(grid[i] == '-') {
                int depth = 0;
                grid[i] = aiMark;
                int score = minimax(grid, depth, false, aiMark, hMark);
                cout<<score<<"\n";
                
                
	            if(score > best) {
                    best = score;
                    finalSpot = i; //update best score and best spot
		            
                }
		        grid[i] = '-'; //backtrack
	        
               
                
            }
	    

               

        }
    

    grid[finalSpot] = aiMark; //AI finally updates grid
    return;
    

}


