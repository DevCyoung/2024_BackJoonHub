size   = int(input())
result = 0
for i in range(1,size+1):
    if i < 100:
        result += 1
        continue
    strNum = str(i)
    if int(strNum[2]) - int(strNum[1]) == int(strNum[1]) - int(strNum[0]):
        result += 1
print(result)
    
        

        
    
    