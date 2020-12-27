class Solution(object):
    def halvesAreAlike(self, s):
        vowels = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        l = len(s)//2
        first = s[:l]
        second = s[l:]
        counter = 0
        for i in first:
            if i in vowels:
                counter+=1
        for i in second:
            if i in vowels:
                counter-=1
        return counter==0
        
