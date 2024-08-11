class test:
    a=13
    
    def fun(self,b):
        self.b=12
        print(test.a)
        print(self.a)
        print(self.b)
        print(b)
        



a=test()
b=test()

a.fun(12)


a.a=23
print(test.a,a.a)