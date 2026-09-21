def stock_portfolio_tracker():
    # Hardcoded dictionary to define stock prices
    stock_prices = {
        "AAPL": 180.0,
        "TSLA": 250.0,
        "GOOGL": 140.0,
        "MSFT": 400.0,
        "AMZN": 175.0
    }
    
    portfolio = {}
    
    print("=== Simple Stock Portfolio Tracker ===")
    print("Available stocks and prices:")
    for stock, price in stock_prices.items():
        print(f"  - {stock}: ${price:.2f}")
    print("-" * 40)
    
    # User input loop
    while True:
        stock_name = input("Enter stock symbol (or type 'DONE' to finish): ").strip().upper()
        if stock_name == 'DONE':
            break
        
        if stock_name not in stock_prices:
            print(f"Sorry, '{stock_name}' is not in our price list. Please try again.")
            continue
            
        try:
            quantity = float(input(f"Enter quantity for {stock_name}: "))
            if quantity < 0:
                print("Quantity cannot be negative. Please try again.")
                continue
            # Add to portfolio (handles multiple entries of the same stock)
            portfolio[stock_name] = portfolio.get(stock_name, 0.0) + quantity
        except ValueError:
            print("Invalid input for quantity. Please enter a valid number.")
            
    if not portfolio:
        print("\nNo stocks added to the portfolio.")
        return

    # Calculate total portfolio value and generate summary
    print("\n=== Portfolio Summary ===")
    total_value = 0.0
    summary_lines = []
    
    header = f"{'Stock':<10} | {'Quantity':<10} | {'Price ($)':<10} | {'Total ($)':<12}"
    print(header)
    print("-" * len(header))
    summary_lines.append(header)
    summary_lines.append("-" * len(header))
    
    for stock, qty in portfolio.items():
        price = stock_prices[stock]
        stock_total = qty * price
        total_value += stock_total
        line = f"{stock:<10} | {qty:<10} | {price:<10.2f} | {stock_total:<12.2f}"
        print(line)
        summary_lines.append(line)
        
    print("-" * len(header))
    total_line = f"Total Portfolio Value: ${total_value:.2f}"
    print(total_line)
    summary_lines.append("-" * len(header))
    summary_lines.append(total_line)
    
    # Optional file saving
    save_choice = input("\nWould you like to save this portfolio to a file? (yes/no): ").strip().lower()
    if save_choice in ['y', 'yes']:
        filename = input("Enter filename (e.g., portfolio.txt or portfolio.csv): ").strip()
        try:
            with open(filename, 'w') as f:
                f.write("\n".join(summary_lines))
            print(f"Portfolio successfully saved to {filename}!")
        except Exception as e:
            print(f"Error saving file: {e}")

if __name__ == "__main__":
    stock_portfolio_tracker()