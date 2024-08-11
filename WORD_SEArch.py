class Solution(object):
    def rec(self, board, word, m, n, wl, i, a, b, mp):
        if i == wl:
            return True
        mp[(a, b)] = True

        if (a+1 < m and board[a+1][b] == word[i] and bool(mp.get((a+1, b))) == False):
            if (self.rec(board, word, m, n, wl, i+1, a+1, b, mp)):
                return True
            mp[a+1, b] = False
        if (b+1 < n and board[a][b+1] == word[i] and bool(mp.get((a, b+1))) == False):
            if (self.rec(board, word, m, n, wl, i+1, a, b+1, mp)):
                return True
            mp[a, b+1] = False
        if (b-1 >= 0 and board[a][b-1] == word[i] and bool(mp.get((a, b-1))) == False):
            if (self.rec(board, word, m, n, wl, i+1, a, b-1, mp)):
                return True
            mp[a, b-1] = False
        if (a-1 >= 0 and board[a-1][b] == word[i] and bool(mp.get((a-1, b))) == False):
            if (self.rec(board, word, m, n, wl, i+1, a-1, b, mp)):
                return True
            mp[a-1, b] = False

        return False

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        mp = {}
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if (c == word[0] and self.rec(board, word, len(board), len(board[0]), len(word), 1, i, j, d)):
                    return True
                mp[i, j] = False
        return False


s = Solution()
print(s.exist([["A", "B", "C", "E"], ["S", "F", "C", "S"],
      ["A", "D", "E", "E"]], "ABCCED"))
