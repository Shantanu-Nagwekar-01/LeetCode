class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        col = set() #to store columns which are used
        posDiag = set() #to store constant (r + c) that remains constant while going through positive diagonal from a cell
        negDiag = set() #to store constant (r - c) that remains constant while going through negative diagonal from a cell
        result = [] #to store distinct solution of chessboard's cells values of 'Q' or '.' 
        board = [["."]*n for i in range(n)] #initializing board with '.' so that the board does not contains any Queens at first
        def backtrack(r: int):
            if (r==n):#if row equals n then the final solution will be appended to result 
                copy = ["".join(row) for row in board]
                result.append(copy)
                return 
            
            for c in range(n):# for a row r, we check each column to place the queen 
                if c in col or (r+c) in posDiag or (r-c) in negDiag:
                    #if the queen is already placed in column col or it is in positive or negative diagonal from (r,c) cell then we cannot place 
                    #queen in that cell as it will be attacked check next column
                    continue
                #if we can place queen in the current column col add the col and constants (r+c) and (r-c) to the respective sets and 
                #place the queen in (r,c) cell
                col.add(c)
                posDiag.add(r+c)
                negDiag.add(r-c)
                board[r][c] = "Q"
                #now that we have placed the queen in 1 row we cannot place another in same row so go to next row
                backtrack(r+1)
                #backtrack logic
                #if by placing queen in (r,c) we cannot place next queen then backtrack and remove the current column and constants
                #remove Q from (r,c) cell
                col.remove(c)
                posDiag.remove(r+c)
                negDiag.remove(r-c)
                board[r][c] = "."
        
        backtrack(0)#check from first row
        return result