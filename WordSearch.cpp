#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_ROWS 256

void print2dVector(std::vector<std::vector<char>> const &mat) {
    for (vector<char> row: mat) {
        for (char val: row) {
            cout << val << " ";
        }
        cout << '\n';
    }    
}

bool readInPuzzleAndWords(string puzzleFile, string wordFile, 
        vector<vector<char>>& board, vector<string>& words) {
    ifstream inFile(puzzleFile, ios::in);
    if(!inFile.is_open()) return false;
    
    string line;
    char char_array[MAX_ROWS];
    int i=0;
    int j=0;
    while(getline(inFile, line)){
        strcpy(char_array, line.c_str());
        
        //Todo: check strlen(line) is the same for all
        
        for (i=0; i<strlen(line.c_str()); i++) {
            board[j].push_back(char_array[i]);
        }
        
        j++;
    }
    
    inFile.close();
    
    ifstream inFile2(wordFile, ios::in);
    
    if(!inFile2.is_open()) return false;
    while(getline(inFile, line)){
        words.push_back(line);
    }
    
    inFile2.close();
}

bool writeOutPuzzle(vector<vector<char>> &board, string outputFile) {
    ofstream outFile(outputFile, ios::out);
    if(!outFile.is_open()) return false;
    
    for (vector<char> row: board) {
        string str(row.begin(), row.end());
        outFile << str;
    }  
    
    outFile.close();
}


class Solution {
public:
    map<string, vector<pair<int,int>>> findWords(vector<vector<char>>& board, 
        vector<string>& words) {

        int nRows = board.size();
        int nCols = board[0].size();
        // 8 directions
        const int x[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
        const int y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    
        map<string, vector<pair<int,int>>> mapResult;
        for (int row = 0; row < nRows; row++) {
           for (int col = 0; col < nCols; col++) {
           
                for(auto word : words) {
        
                    //First character of word doesn't match
                    if (board[row][col] != word[0]) continue; 
                  
                    int len = word.length(); 
                  
                    // Search the word in all 8 directions from (row,col) 
                    for (int dir = 0; dir < 8; dir++) 
                    { 
                        // Init starting point for current direction 
                        int k, rd = row + x[dir], cd = col + y[dir]; 
                  
                        // 1st char is already checked, match remaining chars 
                        for (k = 1; k < len; k++) 
                        { 
                            // If out of boundary, break 
                            if (rd >= nRows || rd < 0 || cd >= nCols || cd < 0) 
                                break; 
                  
                            // If not match,  break 
                            if (board[rd][cd] != word[k]) 
                                break; 
                  
                            //  Moving to particular direction 
                            rd += x[dir], cd += y[dir]; 
                        } 
                  
                        // All character matched, then value of must 
                        // the same as the length of word 
                        if (k == len) mapResult[word].push_back({row,col});
                    }
                    
                    //cout << "Done searching " << word << " at " << row << ", " 
                    //    << col << " Result: " << endl; 
                    //for (string &s : result) cout << s << " ";
                    //cout << '\n';
                }
                
           }
        }
        
        return mapResult;
    }
};

    /*Part (A):
    Write a program that will read in any list of unique words from a text file 
    (where each word is on its own line), and will subsequently identify the 
    number of occurrences for each word in a word search puzzle text file (that 
    will also have to be read in). 

    The program will consider vertical, horizontal, and diagonal words. 

    Valid assumption: The word search puzzle is a square (n x n) matrix of only 
    letters. The letters in both the word list and the puzzle are in uppercase. 

    Both the number of words in the word list and the matrix size of the puzzle 
    can vary. When you have completed the task, your program will be tested with 
    another word list and puzzle.*/

int main()
{
    Solution solution;
   
    vector<vector<char>> board{ {'T','K','J','O','Q','M','I','T','Q','A','E','E'},
       {'F','D','S','O','U','X','D','Q','M','E','S','I'},
       {'H','A','C','R','H','N','R','E','T','N','I','V'},
       {'A','R','H','O','I','N','T','E','R','N','Z','A'},
       {'F','X','J','N','M','Y','F','R','F','I','O','F'},
       {'H','X','O','G','W','X','E','B','Q','K','Y','H'},
       {'I','E','F','C','M','D','I','E','L','J','O','A'},
       {'A','X','L','O','W','H','L','W','O','R','L','D'},
       {'H','E','L','L','O','D','L','R','O','W','L','O'},
       {'W','L','S','L','O','D','G','D','O','S','E','J'},
       {'T','M','J','E','Q','Z','L','O','M','W','H','P'},
       {'L','L','Q','H','Q','T','M','I','W','C','M','A'} };
       
    vector<string> words{"HELLO","WORLD","INTERN"};
   
    //If file loading failed, the above data will be used 
    readInPuzzleAndWords("sample_puzzle.txt", "sample_word_list.txt", board, words);
  
    map<pair<int,int>, vector<string>> map2;
    map<string, vector<pair<int,int>>> result = solution.findWords(board, words);
    for(auto elem : result) {
        cout << elem.first << '\t' << elem.second.size() << ": " << endl;
        for(auto item : elem.second) {
            cout << elem.first << " " << item.first << " " << item.second << "\n";
            
            map2[{item.first, item.second}].push_back(elem.first);
        }
    }
    
    /*Part (B): 
    Expand your program to output a new text file that will have every letter of 
    all the identified words in the puzzle (vertical, horizontal, and diagonal) 
    replaced with "*". If a letter is being used by multiple words, replace it 
    with "#". */
    
    for(auto item : map2) {
        cout << item.first.first << " " << item.first.second << '\t' << item.second.size() << endl;
        board[item.first.first][item.first.second] = item.second.size()>1? '#' : '*';
    }
    
    // print the 2D vector
    print2dVector(board);
    writeOutPuzzle(board, "output_puzzle.txt");

   return 0;
}
