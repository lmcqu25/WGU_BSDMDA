with open('BertrandRussell.txt', 'r') as br:
    #rdr = br.read()
    #print(rdr)
    #rdr = list(rdr) # Turn into list
    #print(rdr)
    #rdr_lc = rdr.split(' ')
    #print(rdr_lc)
    print()
    print()

    counts = dict()
    for line in br:
        line = line.rstrip()
        words = line.split()
        for word in words:
            counts[word] = counts.get(word, 0) +1

    
    print()
    print()

    print(counts)
    print()
    print()

    bigcount = None
    bigword = None
    smallcount = None
    smallword = None
    for word,count in counts.items():
        if word in ['The', 'the', 'An', 'an', 'and', 
                    'And', 'a', 'A', 'of', 'Of', 'On', 
                    'on', 'to', 'To', 'is', 'Is'] :
            continue
        if count < 3:
            continue
        if bigcount is None or count > bigcount:
            bigword = word
            bigcount = count

        if smallcount is None or count < bigcount:
            smallword = word
            smallcount = count
        



    print(bigword, bigcount)
    print()
    print(smallword, smallcount)



    '''count = dict()
    for word in rdr_lc:
       count[word] = count.get(word, 0) + 1
    print(count)
    print()
    print()

    for key, value in count.items():
        print(key, value)'''

