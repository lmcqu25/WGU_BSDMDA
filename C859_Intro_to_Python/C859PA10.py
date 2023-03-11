stocks = {'TSLA': 912.86 , 'BBBY': 24.84, 'AAPL': 174.26, 'SOFI': 6.92, 'KIRK': 8.72, 'AURA': 22.12, 'AMZN': 141.28, 'EMBK': 12.29, 'LVLU': 2.33}
qnty_of_stocks = int(input("Enter qnty of stocks: "))
stock_selection = [input("Enter stocks: ").upper() for i in range(qnty_of_stocks)]
cost_of_stocks = [stocks.get(i) for i in stock_selection]
#cost_of_stocks = sum(cost_of_stocks)



print(f'Total price: ${sum(cost_of_stocks):.2f}')
