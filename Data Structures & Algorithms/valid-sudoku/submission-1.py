class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            s=set()
            for j in range(9):
                if board[i][j]=='.':
                    continue
                if board[i][j] in s:
                    return False
                s.add(board[i][j])
        
        for j in range(9):
            s=set()
            for i in range(9):
                if board[i][j]=='.':
                    continue
                if board[i][j] in s:
                    return False
                s.add(board[i][j])
        
        for sq in range(9):
            s=set()
            for i in range(3):
                for j in range(3):
                      row=(sq//3)*3+i
                      col=(sq%3)*3+j
                      if board[row][col] =='.':
                        continue
                      if board[row][col] in s:
                        return False
                      s.add(board[row][col])
        
        return True
        