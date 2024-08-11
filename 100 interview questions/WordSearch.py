class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        visited={}
        frequency={}
        for rowNO,row in enumerate(board):
            for columnNO,char in enumerate(row):
                frequency[char].append(rowNO,columnNO)
        
        for i  in range(0,len(word)-1):
            try:
                a,b=frequency[word[i]]
                c,d=frequency[word[i]]
                
                
            except KeyError:
                return False
        
        
        
   