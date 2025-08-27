🏦 ATM System in C

This is a small project I built in C language that works like a basic ATM machine.
It lets you create an account, log in, check balance, deposit, and withdraw money.
I used file handling so that account details stay saved even after you close the program.

✨ What it does

Create a new account with Name, Account Number, PIN, and Deposit

Login with your Account Number + PIN

After login, you get an ATM menu:

Check balance

Deposit money

Withdraw money

Logout

🛠 How I built it

Language: C

Used structures to store account info

Used file handling (Account.txt) to save accounts permanently
🛠 How I built it

Language: C

Used structures to store account info

Used file handling (Account.txt) to save accounts permanently

▶️ How to run

Download or clone this repo:

git clone https://github.com/your-username/ATM-Project.git
cd ATM-Project


Compile the code:

gcc main.c -o atm


Run it:

./atm

📂 Files

main.c → the source code

Account.txt → gets created automatically, stores account info

🚀 Future ideas

Add money transfer between accounts

Add transaction history

Add "Forgot PIN" option
