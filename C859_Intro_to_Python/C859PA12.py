user_input = input("Enter text file: ")

with open(user_input, 'r+') as wtf:
    word_list = wtf.readlines()
    print(word_list)
   
    wtf.write('\n')
    wtf.write(' '.join(word.strip() for word in word_list))
    
    wtf.seek(0)
    show = wtf.read()
    print(show)
    
   
        
    #WordTextFile1.txt

  





    '''first_line = wtf.readline()
    second_line = wtf.readline()
    third_line = wtf.readline()   
    first_line = first_line.strip()
    second_line = second_line.strip()
    third_line = third_line.strip()
    
    combined_lines =  '\n' + first_line + ' ' + second_line + ' ' +  third_line
    wtf.write(combined_lines)
    wtf.seek(0)
    show = wtf.read()
    print(show)'''
    