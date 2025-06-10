postfix = input("Enter the postfix expression: ")
token = postfix.split()
stack=[]
for token in token:
  if token.isdigit():
    stack.append(int(token))

  else:

    pop1= stack.pop()
    pop2= stack.pop()

    if token == '+':
      stack.append(pop2 + pop1)

    elif token == '-':
      stack.append(pop2 - pop1)
 
    elif token == '*':
      stack.append(pop2 * pop1)
    
    elif token == '/':
      stack.append(pop2 / pop1)

    elif token == '^':
      stack.append(pop2 ** pop1)

result = stack.pop()
print (f"the result is {result}")
            






    



