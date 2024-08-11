def some_function(value):
    print(value)

i = 0
some_function(i += 1)  # This will raise a SyntaxError
