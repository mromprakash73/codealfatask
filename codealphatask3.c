import re

def extract_emails(input_file, output_file):
    # Standard regex pattern for matching email addresses
    email_pattern = r'[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}'
    
    try:
        # Read the source text file
        with open(input_file, 'r', encoding='utf-8') as file:
            content = file.read()
            
        # Find all matches and use set() to remove duplicates
        emails = sorted(set(re.findall(email_pattern, content)))
        
        # Write the extracted emails to the output file
        with open(output_file, 'w', encoding='utf-8') as file:
            for email in emails:
                file.write(email + '\n')
                
        print(f"Successfully extracted {len(emails)} unique email(s) to '{output_file}'.")
        
    except FileNotFoundError:
        print(f"Error: The file '{input_file}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    extract_emails('source_text.txt', 'extracted_emails.txt')