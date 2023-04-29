## Bitcoin Exchange

### Read .cvs database of dates and exchange rates and save them in a `map<std::string, float>`
### Read inputed .csv file with the dates and amount of bitcoins to exchange line by line, and:
1. Verify Validity of the format (YYYY-MM-DD | BTC), date (monthly limits), and amount (0 > x < 1000)
2. Find in the map the value of Bitcoin at the date querried (or the closest previous date if there isn't an exact match in the database)
3. Print the result of the bitcoin conversion
